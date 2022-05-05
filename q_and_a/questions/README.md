# Questions

- [Questions](#questions)
  - [Q1: `auto` keyword](#q1-auto-keyword)
  - [Q2: 'Code Review'](#q2-code-review)
  - [Q3: 'Validate Parenthesis'](#q3-validate-parenthesis)
  - [Q4: Diff between heap and free store](#q4-diff-between-heap-and-free-store)
  - [Q5: Diff between malloc/free vs new/delete](#q5-diff-between-mallocfree-vs-newdelete)
  - [Q6: `NULL` vs `0` vs `nullptr`](#q6-null-vs-0-vs-nullptr)
  - [Q7: Can i use `realloc()` in C++](#q7-can-i-use-realloc-in-c)
  - [Q8: Explain below code](#q8-explain-below-code)
  - [Q9: Write code to print matrix in sive wave order](#q9-write-code-to-print-matrix-in-sive-wave-order)
  - [Links](#links)
  - [Misc](#misc)

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

## Q4: Diff between heap and free store

- Explain what is the difference between heap and free store

## Q5: Diff between malloc/free vs new/delete

- Explain the difference between malloc/free and new/delete

## Q6: `NULL` vs `0` vs `nullptr`

- Explain the difference between those and which one to use when
- [Answer](../answers/README.md#q6-null-vs-0-vs-nullptr)

## Q7: Can i use `realloc()` in C++

- Explain
  - Whether can I use `realloc` in C++
    - If yes explain why and how
    - If no explain why
- [Answer](../answers/README.md#q7-can-i-use-realloc-in-c)

## Q8: Explain below code

- Reference <https://isocpp.org/wiki/faq/freestore-mgmt#new-never-returns-null>
- Explain below code
  - Any implicit/explicit things you see?
    - if yes, what it is
    - if no, what it is

    ```cpp
    Fred* p = new Fred();
    if (nullptr == p) {    // Only needed if your compiler is from the Stone Age!
      abort();
    }

    Fred * q = nullptr;
    delete q;
    ```

- [Answer](../answers/README.md#q8-explain-below-code)

## Q9: Write code to print matrix in sive wave order

- Write code:
  - For a given row x col value, print the values like sine wave.
    - Example

      ```text
      r = 5, c = 3, its matrix will be
      1  2  3
      4  5  6
      7  8  9
      10 11 12
      13 14 15
      ```

      ```text
      Print: 1 4 7 10 13 14 11 8 5 2 3 6 9 12 15
      ```

- [Answer](../answers/README.md#q9-write-code-to-print-matrix-in-sive-wave-order)

## Links

- [1]<http://thbecker.net/articles/auto_and_decltype/section_03.html>
- [2]<http://www.cs.cornell.edu/gries/July2016/The-Science-Of-Programming-Gries-038790641X.pdf>
  - The Science of Programming (Monographs in Computer Science) by David Gries

## Misc

- String Problems
  - <www.hackerearth.com/challenges/competitive/code-monk-array-strings/problems>
- 2D Array problems
  - <www.hackerearth.com/challenges/competitive/2d-array/problem>
  - <www.techgig.com/practice/data-structure/two-dimensional-arrays>
- Print pattern problems
  - <http://cbasicprogram.blogspot.com/search/label/Patterns>
- Looping exercises
  - <https://github.com/abhikdas7421/Introduction-to-CPP-Coding-Ninjas/tree/master/L-10(Character%20Arrays%20and%202D%20Arrays)>
- STL
  - <https://github.com/Shaleengovil25/Competitive-programming/tree/master/STL>
- Competitive Programming
  - <https://github.com/Mehulcoder/Coding-ninjas-competitive>
- Preparation Guidance
  - <https://medium.com/@mehulchaturvedi/interview-preparation-roadmap-that-got-me-into-amazon-d357049a0a68>