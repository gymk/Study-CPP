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

## Q2: 'Code Review'

- From [2]
  - Any error in this logic?

```cpp
void get_q_r(int x, int y, int *q_v, int *r_v) {
   assert(y > 0);
  int r = x;
  int q = 0;
  while (r > y) {
    r = r - y; q = q += 1;
  }
  assert(x == y * q + r);

  *q_v = q;
  *r_v = r;
}
```

## Q3: 'Validate Parenthesis'

- Write a program to validate the parenthesis expression

## Links

- [1]<http://thbecker.net/articles/auto_and_decltype/section_03.html>
- [2]<http://www.cs.cornell.edu/gries/July2016/The-Science-Of-Programming-Gries-038790641X.pdf>
  - The Science of Programming (Monographs in Computer Science) by David Gries
