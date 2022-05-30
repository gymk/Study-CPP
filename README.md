# Study-CPP

My C++ Study related notes

- [Access Specifier](access_specifiers/README.md)
- [Memory](pointers/Readme.md)
- [C++ Memory Management](Notes/memory_management.md)
- [C++ std::thread](thread/Readme.md)
- [STL](stl/README.md)
- [C++ Standard Attributes](attributes/README.md)
- [Move Semantics](move_semantics/README.md)
- [lambda](lambda/README.md)
- [C++ Standard Attributes](attributes/README.md)
- C++ GSL

- [Design Pattern](design-patterns/README.md)

## References

- [1] <https://lhcb.github.io/developkit-lessons/first-development-steps/05a-cpp11.html>
- [2] [C++ Core Guide Lines](http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
- [3] [GSL Guideline Support Library](https://github.com/Microsoft/GSL)
  - GSL implementation from Microsoft
- [4] [C++ FAQ](https://www.cs.technion.ac.il/users/yechiel/c++-faq/)

## Yet to Study

- Herb Sutter
  - Video trainings in Orielly
    - C++20 Fundamentals
      - <https://github.com/pdeitel/CPlusPlus20FundamentalsLiveLessons>
- Free Store in C++
- Pointers  Safety
  - Type Safety
  - Memory Safety
  - Resource Safety
- C++17/C++20
- Initialization
  - Aggregate Initialization <https://en.cppreference.com/w/cpp/language/aggregate_initialization>
  - Constant Initialization <https://en.cppreference.com/w/cpp/language/constant_initialization>
  - Copy Initialization <https://en.cppreference.com/w/cpp/language/copy_initialization>
  - Default Initialization <https://en.cppreference.com/w/cpp/language/default_initialization>
  - Initializer List <https://en.cppreference.com/w/cpp/language/initializer_list>
  - List Initialization <https://en.cppreference.com/w/cpp/language/list_initialization>
  - Reference Initialization <https://en.cppreference.com/w/cpp/language/reference_initialization>
  - Value Initialization <https://en.cppreference.com/w/cpp/language/value_initialization>
  - Zero Initialization <https://en.cppreference.com/w/cpp/language/zero_initialization>

  - Direct Initialization <https://en.cppreference.com/w/cpp/language/direct_initialization>
  - Converting Constructor <https://en.cppreference.com/w/cpp/language/converting_constructor>
  - Member Initialization <https://en.cppreference.com/w/cpp/language/data_members#Member_initialization>
  - Constructor and Member Initializer Lists <https://en.cppreference.com/w/cpp/language/constructor>
  - Designated initializers <https://en.cppreference.com/w/cpp/language/aggregate_initialization>

  - Brace Initialization <https://docs.microsoft.com/en-us/cpp/cpp/initializing-classes-and-structs-without-constructors-cpp?view=vs-2019>

- Initialization of Non-Local Variables
  - Static Initialization
  - Dynamic Initialization
  - Early Dynamic Initialization
  - Deferred Dynamic Initialization

- `std::atomic` and `std::atomic_flag`
  - <https://riptutorial.com/cplusplus/topic/3804/atomic-types>
- `std::current_exception`
- What is first order functions?
- What is higher order functions?
- What is currying?
  - <https://stackoverflow.com/questions/152005/how-can-currying-be-done-in-c>
  - <https://www.fluentcpp.com/2019/05/03/curried-objects-in-cpp/>
- What is Polymorphic functions?
- What is functoids?
  - What is monomorphic direct functoids?
  - What is polymorphic direct functoids?
  - What is Indirect functoids?
  - What is Direct functoids?

## Other Links

- Quant
  - <https://www.quantstart.com/articles/topic/c/>
- Pointer Aliasing
  - <https://cvw.cac.cornell.edu/vector/coding_aliasing>
- <https://pabloariasal.github.io/tag/cpp/>
  - `std::variant`
  - `std::visit`
  - static initialization
  - C++20
  - CMake
  - VTable, vpointer
- VTable
  - <https://pabloariasal.github.io/2017/06/10/understanding-virtual-tables/>
  - <https://ww2.ii.uj.edu.pl/~kapela/pn/cpp_vtable.html>
  - <https://medium.com/@abhichavhan/demystifying-virtual-functions-vtable-and-vptr-in-c-bf56f11f7cc7>
- C++ Performance
  - <https://lhcb.github.io/developkit-lessons/first-development-steps/06a-perf.html>
- C++ Lambda
  - <https://www.cppstories.com/2019/02/lambdas-story-part1/>
  - <https://www.cppstories.com/2019/03/lambdas-story-part2/>
- C++ final draft
  - <https://timsong-cpp.github.io/cppwp/n3337/>
- C++ Concepts
  - <https://amath583.github.io/sp22/_static/pdf/L19-sp18.pdf>
- HPC (C++)
  - <https://amath583.github.io/sp22/_static/pdf/L19-sp18.pdf>
  - <http://www.morrisriedel.de/hpc-course-spring-2022>
  - <https://www.youtube.com/channel/UCWC4VKHmL4NZgFfKoHtANKg>
- Stack Overflow C++ Documentation
  - <https://sodocumentation.net/cplusplus>
- Lambda
  - [C++ lambda expressions and closures](https://pdf.sciencedirectassets.com/271600/1-s2.0-S0167642310X00089/1-s2.0-S0167642309000720/main.pdf?X-Amz-Security-Token=IQoJb3JpZ2luX2VjEAMaCXVzLWVhc3QtMSJGMEQCIB4SErPwCAdmlqC%2FGw6vgrQlO0ge%2BZwLGPh3b7AZx4YMAiA2Ywh2nnrrxOiGWDDKtRW3NKS5OTDEeyArttlQjHKbJyrbBAi8%2F%2F%2F%2F%2F%2F%2F%2F%2F%2F8BEAQaDDA1OTAwMzU0Njg2NSIMOWSpaXTqYfslHnP7Kq8EgCmYtp4iccuJUG4GXcXePpIIT6IasoLwqsWogYYTJgQWCWirrp39elXFSy1KZCGDW8Cm7rNEYbwGMUHVJFSv%2BDRZVJN%2BmeYSnPrpdJhWs%2BfyzoFH6buu8yaZUe2YrdVX3mXviMWq7fACqP1ZXjG7Cp3uXLf3H9%2FbyfjJcveRSavfYn6GE9SJae%2Fy389NM4egwyMCVxVi5t9v8ILd6gz86sBYKbRLmq5KL8yLhUbjm%2FuwN5GNZ1gpRD6Rv8wUljN5xirozzVRBwi3qUHt59DfGboE0ZRYL%2Bewo%2B%2B7NlasauxikuUfByOrfB6DFWslMQp3YatAUsyRCJBHVyF9%2B514rCcVlFBnjmHWnelMYb6A0hujkmXjD01I66ZvCItCqLTOQRO4IDlt1vDTGMU9b8XfBjRMK2IBxaqX%2BSjYxBfZK2Xql1zpjCBvV32bqOnLMwoB09hHu4ApF7mnHXgxbUKZ5LnxgUcZkJqoujwd0OO5LH6cd%2Fu8UqMKgearJwLb8sOqvmK%2F9PdxqaG9KNN4ltaJP2r3MTZeYHQbydr%2Fq5onRdKoDh7FgZ9IffBzd%2FMtGs1sZI4Go%2BA77dEK3aw29TfJkOErOz6IIyQVZsShBx6UHHqXXWv7W1kcf8ifU2G0QMqrbDiBvOevyDvYjSIGBuM7Lg%2Fel1A8uIgdHHG9g0P6NwoBsOqHaTcvcKWmE7IoNycjE7CIhe%2F5yTJG%2FFCm0aqzLHLqIByWNQIYc81Hw%2BsIcjCovKSTBjqqAXHRfD%2FGO8FO14DnQDLCKslwhNLSkyIhMB%2Fry5b%2BmouRD5gzVHA3AaftLEmu8HzWhFQwXSvPWGKw%2FN2XDTIAKYhBIjMV8f70sAuxgVq85BES6mLZOOkWzHp2qSiDdfU4GcQf8u%2B5VB3LRdzoDCnvBe1dWr26m20EmD6WV%2Fkpxi2TcpNKg1c5pekfVtTIKtWY4CRZ9HxnnIIciL%2BzMKS7fmfyliUDuvftn6zZ&X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Date=20220427T115549Z&X-Amz-SignedHeaders=host&X-Amz-Expires=300&X-Amz-Credential=ASIAQ3PHCVTYWPAHWS7F%2F20220427%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Signature=5001fd812ee35699ff3262d462f8494a735e0137acd1956141fc42d755b67f95&hash=237984e8a9088f0393bb8776036322340d3c01fb907ed2e3a8a3c69aa4f4fa2b&host=68042c943591013ac2b2430a89b270f6af2c76d8dfd086a07176afe7c76c2c61&pii=S0167642309000720&tid=spdf-95010dce-d21f-49ea-b80f-39f5f7b75813&sid=85fbb622584a214e871bef01b2ec3865e754gxrqb&type=client&ua=4d5651505004575f545f05&rr=70275f1159a4935f)
  - J. Järvi, G. Powell, A. Lumsdaine, The Lambda Library: Unnamed functions in C++, Software—Practice and Experience 33 (2003) 259–291
    - <https://citeseerx.ist.psu.edu/viewdoc/download?doi=10.1.1.88.8894&rep=rep1&type=pdf>
      - Lambda
      - Placebolders
      - ...
  - B. McNamara, Y. Smaragdakis, Functional programming with the FC++ library, Journal of Functional Programming 14 (4) (2004) 429–472.
    - <https://www.cambridge.org/core/journals/journal-of-functional-programming/article/functional-programming-with-the-fc-library/1EC78833E953D6798C39C2E4B15EE4B4>
