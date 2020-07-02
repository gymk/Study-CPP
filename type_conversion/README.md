# Type Conversion

Casts **should be used carefully**, because what you are actually doing is saying to the compiler "**_Forget the type checking - treat it as this other type instead_**"

In a buggy program, check casts as these are most probably culprits.

- `const_cast`
  - To cast away `const` and/or `volatile` (and __unaligned attribute[4])
  - Removes the `const` qualifier from the object for the modification
    - Check for usability of `mutable` instead of `const_cast`
- `static_cast`
  - For "well-behaved" and "reasonably well-behaved" casts
    - including things you might now do without a cast
      - such as an automatic type conversion
- `static_cast` followed by `const_cast`
  - [4] used for conversion of nonpolymorphic types
- `reinterpret_cast`
  - To cast to a completely different meaning
- `reinterpret_cast` followed by `const_cast`
  - [4] used for simple reinterpretation of bits.
- `dynamic_cast`
  - For type-safe downcasting
  - [4] Used for conversion of polymorphic types

## `static_cast`

- Can be used for all conversions that are well defined.
- Considered as **safe** conversion
- For casting to and from `void*`, `static_cast` is preferred [3]
- Types of conversions
  - castless conversions
    - Typical castless conversions:
      - `int i; long l; float f;`
      - `l = i; // Promoted from int to long`
      - `f = i; // Promoted from int to float`
  - narrowing conversions i.e., information losing ()
    - Implicit narrow conversions: often you will see warnings from compiler for these type o conversions
      - `i = l; // May lose digits - int is not as wide as long`
      - `i = f; // May lose info - int is not as wide as float`
    - Saying that "I Know," eliminate warnings
      - `i = static_cast<int>(l);`
      - `i = static_cast<int>(f);`
      - `char c = static_cast<char>(i)`
  - forcing a conversion from `void*`
    - `voice * vp = &i;`
    - `float * fp = (float) vp; // This old way produces a dangerous conversion`
    - `fp = static_cast<float*>(vp); // This new way also equally dangerous`
  - implicit type conversions
    - Eg., compiler performed conversions
      - `double d = 0.0;`
      - `int x = d; // Automatic type conversion`
      - `x = static_cast<int>(d); // more explicit`
      - `void func(int) {}`
      - `func(d); // Automatic type conversion`
      - `func(static_cast<int>(d)); // More explicit`
  - static navigation of class hierarchies (`dynamic_cast`)
    - upcasting
      - Move up the Inheritance hierarchy: Derived to parent
      - Taking address of an object (either pointer or reference) and treating it as the address of the base type
    - downcasting
      - Move down the Inheritance hierarchy: Parent to derived

## `const_cast`

- You can use `const_cast` to convert from a
  - `const` to non`const`
    - `const int i;`
    - `int * j = (int *) &i; // Deprecated form`
    - `j = const_cast<int*)(&i); // preferred`
  - `volatile` to non`volatile`
    - `volatile int k = 0;`
    - `int* u = const_cast<int*>(&k);`

## `reinterpret_cast`

- **_Least safe_** casting mechanism, most likely to produce _bugs_.
- A `reintepret_cast` pretends that an object is just a bit pattern that can be treated as if it were an entirely different type of object.

```cpp
/*constexpr*/ bool is_little_endian() {
  std::uint16_t x=0x0001;
  auto p = reinterpret_cast<std::uint8_t*>(&x);
  return *p != 0;
}
/*
The binary representation of `x` in memory could be
    0000 0000 0000 0001 - if it is big endian
    0000 0001 0000 0000 - if it is little endian

if static_cast
*/
```

## Links

- [1] Explicit type conversion <https://en.cppreference.com/w/cpp/language/explicit_cast>
- [2] Thinking in C++, C++ explicit casts <https://www.linuxtopia.org/online_books/programming_books/thinking_in_c++/Chapter03_051.html>
- [3] <https://stackoverflow.com/questions/573294/when-to-use-reinterpret-cast>
- [4] <https://docs.microsoft.com/en-us/cpp/cpp/casting?view=vs-2019>
