# `const` keyword

- In C++ terms, `const` means read-only, that is immutable.

- In C++98, `const == logically const`
- From C++11 `const` means **_`thread-safe`_**[1]
  - It means it is bitwise const
  - Or internally synchronized

This is to enable e.g., say a C++ standard library function _shall not directly or indirectly modify_ objects accessible by threads other than the current thread unless the objects are accessed directly or indirectly via the function's non-`const` arguments, including _this_.

- From [2]
  - `bitwise const`
    - `bitwise const` means every bit in the object is permanent
    - So a bit image of the object will never change
    - If an object is told as `const`, compiler will ensure that it is bitwise `const`ness.
  - `logical const` or `memberwise const`
    - `logical const` means although the entire object is conceptually constant, there may be changes on a member-by-member basis.
    - To effect logical `const`ness
      - You can do _cast away `const`ness_
        - Either `const_cast<Y*>(this)->i++` or `((Y*)this)->i++`
      - You can tell compiler that it is `mutable`
        - `mutable int i`

## Links

- Video
  - [1] <https://channel9.msdn.com/posts/C-and-Beyond-2012-Herb-Sutter-You-dont-know-blank-and-blank>
  - [2] <https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter08_025.html#:~:text=Bitwise%20const%20means%20that%20every,member%2Dby%2Dmember%20basis.>
