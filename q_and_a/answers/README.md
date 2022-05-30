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
  - [Q10: How we can execute our code before `main()`?](#q10-how-we-can-execute-our-code-before-main)
  - [Q11: How we can run code after `main()`?](#q11-how-we-can-run-code-after-main)

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

## Q10: How we can execute our code before `main()`?

```cpp
//* https://akrzemi1.wordpress.com/2017/06/28/compile-time-string-concatenation/ */

//
// It is possible to run code before main
//

/* g++ run_before_main.cpp */

/*
g++ -v

Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/4.8/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 4.8.4-2ubuntu1~14.04.3' --with-bugurl=file:///usr/share/doc/gcc-4.8/README.Bugs --enable-languages=c,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-4.8 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --with-gxx-include-dir=/usr/include/c++/4.8 --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --enable-gnu-unique-object --disable-libmudflap --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-4.8-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-4.8-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-4.8-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 4.8.4 (Ubuntu 4.8.4-2ubuntu1~14.04.3)

*/

#include <iostream>

int i = 10;

bool run_before_main(void)
{
    i += 20;
    return true;
}

const bool preVal = run_before_main(); // will set value returned by run_before_main, which is exected before main gets run

int main()
{
    std::cout << preVal << std::endl;
    std::cout << i << std::endl;
}

/*
Output:

1
30

*/
```

## Q11: How we can run code after `main()`?

```cpp
/* https://akrzemi1.wordpress.com/2017/06/28/compile-time-string-concatenation/ */

/* g++ run_after_main.cpp */
#include <iostream>
#include <exception>

void run_after_main(void)
{
    std::cout << "Executing " << __PRETTY_FUNCTION__ << std::endl;
}

struct laterun
{
    laterun()
    {
        std::set_terminate(run_after_main);
    }
    ~laterun()
    {
        throw "except";
    }
} laterunGlobalObj;

int main()
{
    std::cout << "Exiting main()" << std::endl;
}

/*
Output:

Exiting main()
Executing void run_after_main()
Aborted (core dumped)

*/
```
