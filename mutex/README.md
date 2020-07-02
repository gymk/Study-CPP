# std::mutex

- The `mutex` that internal to a class **want to be mutable**[1]
  - Because they are already synchronized (thread-safe)
  - To maintain const guarantees
    - People use this to cast-away const in a member function which is `const`.
    - Eg., `info get_info() const { lock_guard<mutex> hold(m); ... }`

- Refer `const.md` under _Notes_ section to know more on `bitwise const` and `logical const`

## Links

- [1] <https://channel9.msdn.com/posts/C-and-Beyond-2012-Herb-Sutter-You-dont-know-blank-and-blank>
