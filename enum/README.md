# Enumeration

- [Enumeration](#enumeration)
  - [Types of Enum](#types-of-enum)
  - [Drawbacks for traditional Enum](#drawbacks-for-traditional-enum)
    - [scope issue](#scope-issue)
    - [Implicit conversion to int](#implicit-conversion-to-int)
    - [Can't override underlying type](#cant-override-underlying-type)
  - [C++11 enhancements](#c11-enhancements)
  - [Study inks](#study-inks)

## Types of Enum

- From [1]
  - C++11 onwards
    - based enum and scoped enum

## Drawbacks for traditional Enum

- From [2]
  - Enumerators [convert to `int` automatically, no questions asked](#Implicit-conversion-to-int)
  - Enumerator names are [visible from their enumn's enclosing scope](#scope-issue)
  - You cannot override the default underlying type of an enum programmatically

### scope issue

```c++11
enum Color {
  Bronze,
  Silver,
  Gold
};

enum Bullion
{
  Silver, // conflicts with Color’s Silver
  Gold,   // conflicts with Color’s Gold Platinum
};
```

### Implicit conversion to int

- Until C++11, the workaround for bellow issue is to use `class` instead of `enum`
  - Example Code:

      ```c++11
      enum Color { ClrRed, ClrOrange, ClrYellow, ClrGreen, ClrBlue, ClrViolet };
      enum Alert { CndGreen, CndYellow, CndRed };
      Color c = ClrRed;
      Alert a = CndGreen;
      a = c; // error
      a = ClrYellow; // error
      ```

    - Issue:

      __`bool armWeapons = ( a >= ClrYellow );`__ // ok; oops

### Can't override underlying type

- Since size of `int` varies according to architecture, below code is not portable
  - Example Code:

    ```c++
    enum Version { Ver1 = 1, Ver2 = 2 };
    struct packet {
      Version ver;    // bad, size can vary by implementation
      // ... more data
      Version getVersion(void) const { return ver; };
    } ;
    ```

  - Workaround
    - `unsigned char ver;`
      - Use desired type and do typecasting

## C++11 enhancements

- From [2]
  - C++11 addesses above issues
    - Gives tigher control over the
      - Scope, Size and implicit conversion of enum types

- new declaration
  - `enum class`
- No implicit conversion
  - `enum class E { E1, E2, E3 = 100, E4 /* = 101 */ };`
    - Now below statement will give errir
      - `if( e >= 100 ) // error: no E to int conversion`
      - `int i = E::E2; // error: no E to int conversion`
- Underlying type
  - enum class E : unsigned long { E1 = 1, E2 = 2, Ebig = 0xFFFFFFF0U };
- Scoping
  - `enum class E { E1, E2, E3 = 100, E4 /* = 101 */ };`
  - `E e1 = E1; // error`
  - `E e2 = E::E2; // ok`

## Study inks

- [1]
  - [Strongly Typed Enums - Revision 3](https://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2347.pdf)
- [2]
  - [Closer to Perfection: Get to Know C++11 Scoped and Based Enum Types](https://smartbear.com/blog/closer-to-perfection-get-to-know-c11-scoped-and-ba/)
