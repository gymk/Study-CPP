# Explanation of value categories

- More details above rvalue can be found in <https://lhcb.github.io/developkit-lessons/first-development-steps/05a-cpp11.html>
  - In C++11, rvalues are further complicated because of the desire to move object. To properly grasp the syntax, it is important to understand all 3 unique categories in C++11, from the C++ standard n3055:

    - __lvalue__: Anything that can be on the left side of equal sign.
    - __xvalue__: An rvalue that about to expire (something being returned from a function, for example). An xvalue can be moved.
    - __prvalue__: An rvalue that is not about to expire, like a literal (12, true) or the result of a non-reference return of a function.

C++11 also defines two combination categories, __glvalue__ is an __lvalue__ or __xvalue__, and the classic __rvalue__, which is a __prvalue__ or an __xvalue__.
