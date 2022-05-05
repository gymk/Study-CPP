# Answers

- [Answers](#answers)
  - [Q1: `auto` keyword](#q1-auto-keyword)
  - [Q3: 'Validate Parenthesis'](#q3-validate-parenthesis)
  - [Q4: Diff between heap and free store](#q4-diff-between-heap-and-free-store)
  - [Q5: Diff between malloc/free vs new/delete](#q5-diff-between-mallocfree-vs-newdelete)
  - [## Q6: `NULL` vs `0` vs `nullptr`](#-q6-null-vs-0-vs-nullptr)
  - [Q7: Can i use `realloc()` in C++](#q7-can-i-use-realloc-in-c)
  - [Q8: Explain below code](#q8-explain-below-code)
  - [Q9: Write code to print matrix in sive wave order](#q9-write-code-to-print-matrix-in-sive-wave-order)

## Q1: `auto` keyword

The type of `something` is `int`. Refer [1]

## Q3: 'Validate Parenthesis'

Refer [validate_parenthesis.cpp](../../stl/container_adaptor/stack/validate_parenthesis.cpp)

## Q4: Diff between heap and free store

- <http://www.cplusplus.com/forum/beginner/131001/>

## Q5: Diff between malloc/free vs new/delete

- malloc/free provides raw pointers
  - Can't be used for objects
    - If you use it for a C++ object, it won't invoke constructor/destructor
- new/delete- referred as free store
  - Can be used for Objects
    - Invokes contrusctors on `new` and destructors on `delete`
- <https://isocpp.org/wiki/faq/freestore-mgmt#new-malloc-diff>

## ## Q6: `NULL` vs `0` vs `nullptr`

- `0` is an integer
- In standard library, `NULL` also defined as `0`
- if you have function overloaded with integer and pointer
  - If you use `NULL` or `0`, it will take function overloaded with `int`
  - Using `nullptr` will enable compiler to use the function overloaded with pointer
  - This avoid ambiguity

## Q7: Can i use `realloc()` in C++

- <https://isocpp.org/wiki/faq/freestore-mgmt#renew>
  - `realloc()` is part of heap implementation, commonly found in C
  - In C++, we have free store, where we have to use `new` and `delete` for objects (which enables object consturctor/destructor invokation, initialization of objects, ...)
  - If `realloc` kind of functionality needed, we can use STL, example `std::vector`

## Q8: Explain below code

- Reference <https://isocpp.org/wiki/faq/freestore-mgmt#new-never-returns-null>
  - if `new` fails to allocate required memory, it will `throw` `std::bad_alloc` exception
    - Unless you specify `nothrow`
- Reference <https://isocpp.org/wiki/faq/freestore-mgmt#delete-handles-null>
  - it is safe to call `delete` operator for a NULL object
  - Deleting a `nullptr` is harmless by definition of C++ (from atleast C++03 onwards)

## Q9: Write code to print matrix in sive wave order

  ```cpp
  #include <stdio.h>

  // Hardcoded but you can read r,c if you want
  #define R 5
  #define C 3

  int main(void) {
    int r,c;
    int v = 1;
    int val_fact = C;
    for(c = 0; c < C; c++)
    {
      for(r = 0; r < R; r++)
      {
        printf("%d ", v);
        v += val_fact;
      }
      v -= val_fact;
      v++;
      val_fact *= -1;
    }
    return 0;
  }
  ```
