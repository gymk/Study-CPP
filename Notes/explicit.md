# `explicit` keyword

## explicit constructors

[Explicit constructors are](https://en.cppreference.com/w/cpp/language/converting_constructor) are only considered during direct initialization (which includes explicit conversions such as static_cast)

i.e., [explicit int a constructor disables copy-initialization](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n4014.pdf)
