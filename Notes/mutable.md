# `mutable` keyword

- In C++98, `mutable` means _`"not observably non-const"`_

```cpp
class widget {
  mutable mutex m;        // protects internal data
  ...                      // more data
  ...

public:
  info get_info() const {
    lock_guard<mutex> hold(m);
    return { /* use 'more data' */ };
  }
}
```

- From C++11, `mutable` means **_`thread-safe`_**[1].
  - It means it is bitwise const
  - Or internally synchronized
  - i.e, either ensure bitwise const or if logical const is required, ensure internal thread safety (Refer Notes --> thread safe copy constructor)

## Links

- Video
  - [1] <https://channel9.msdn.com/posts/C-and-Beyond-2012-Herb-Sutter-You-dont-know-blank-and-blank>
  - [2] <https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter08_025.html#:~:text=Bitwise%20const%20means%20that%20every,member%2Dby%2Dmember%20basis.>
