# Questions

## Q1: `auto` keyword

- From [1]
  - what is the type of `something`?

```cpp
int x = int{};    // x is an int, initialized to 0
assert(x == 0);

const int& crx = x;    // crx is a const int& that refers to x
x = 42;
assert(crx == 42 && x == 42);

auto something = crx;
```

## Links

- [1]<http://thbecker.net/articles/auto_and_decltype/section_03.html>
