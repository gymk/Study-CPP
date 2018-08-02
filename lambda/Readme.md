Lambda are functional objects (not function pointers), when defined, compiler will create a unnamed class having lambda function as member, and it (compiler) will create an instance of that unnamed object.
Since it is unnamed, it is custom to have auto qualifier to lambda objects.

`auto f1 = [](){}`

if you have a std::shared_ptr - for example, and it is pased-by-value, during this object instantiation, it will have its own copied std::shared_ptr

```
std::shared_ptr<int>   p = std::make_shared<int>(10);   // p will have ref-count of 1

auto f1 = []()  // When f1 is crated, p already passed to f1 as 'pass-by-value' so p will have ref-count of 2
{
    std::cout << *p << std::endl;
}
```
TO DO

- Capture
    - [=]
    - [&]
    - [args]
- Assiging lambda to a function pointer

