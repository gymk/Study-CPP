# C++ Standard Attributes

## `[[unused]]` >= C++17

- An entity marked with `[[unused]]` means that the entity may appear to be unused for some reason
  - If the implementation would have otherwise warned that the entity isn't used, the `[[unused]]` attribute suppresses the warning

```cpp
int x; // WARNING: x is unused
[[unused]] int x; // OK
```

## `[[nodiscard]]` >= C++17

- Appears in
  - Function declaration or in
  - Enumeration decleration or in
  - Class declaration
- Syntax
  - `[[nodiscard]]`
  - `[[nodiscard( string-literal )]]`
    - `string-literal` 
- Specifies that a function's return value (return by value - an enumeration or a class or a type) is not intented to be discarded
  - If discarded it will issue a warning, unless it is cast'ed to void.

```cpp
[[nodiscard]]
int foo(int i) {
    return i * i;
}

in main() {
    foo(42);    // Warning C4834: discarding return value of function with 'nodiscard' attribute
    return 0;
}
```

## TO DO

- `[[noreturn]]`
- `[[carries_dependency]]`
- `[[deprecated]]`
- \>= C++17
  - ~~`[[unused]]`~~
  - ~~`[[nodiscard]]`~~
  - `[[fallthrough]]`

## Links

  - <https://docs.microsoft.com/en-us/cpp/cpp/attributes?view=vs-2019>
  - <http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/p0068r0.pdf>
