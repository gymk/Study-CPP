
# Virtual Table

A table of pointers to virtual functions.
The `type_info` object associated with each class in support of runtime type identification (RTTI) is also addressed within the virtual table.

## Virtual Base

TO DO

## vptr

A single pointer to the associated virtual table is inserted within each class object, traditionally referred as _vptr_

## Books

- Inside the C++ Object Model

## Links

- [Efficient C/C++ Coding Techniques](http://www.open-std.org/jtc1/sc22/wg21/docs/ESC_Boston_01_304_paper.pdf)
- [Multiple Inheritance](https://www.cprogramming.com/tutorial/multiple_inheritance.html)
  - [FAQ on Multiple Inheritance](https://isocpp.org/wiki/faq/multiple-inheritance)
- [Virtual Inheritance](https://www.cprogramming.com/tutorial/virtual_inheritance.html)
