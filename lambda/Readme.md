# Lambda Expression (Lambda Function)

## __Syntax:__

```c++
[]()->type <mutable, constexpr, noexcept> {}
```

Lambda are functional objects (not function pointers), when defined, compiler will create a unnamed class having lambda function as member, and it (compiler) will create an instance of that unnamed object.
Since it is unnamed, it is custom to have auto qualifier to lambda objects.

```c++
auto f1 = [](){}
```

if you have a std::shared_ptr - for example, and it is pass-by-value, during this object instantiation, it will have its own copied std::shared_ptr

```c++
std::shared_ptr<int>   p = std::make_shared<int>(10);   // p will have ref-count of 1

auto f1 = []()  // When f1 is created, p already passed to f1 as 'pass-by-value' so p will have ref-count of 2
{
    std::cout << *p << std::endl;
}
```

## __Capture:__

Captures all the variables are in the environment (defined environment) where this lambda is defined.

- []
  - Nothing captured from the defined environment
    - Data is obtained from passed arguments if required
- [=]
  - Call by value capture
  - Captures all the variables that are in the defined environment as `Call by Value`
- [&]
  - Call by reference capture
  - Captures all the variables that are in the defined environment as `Call by Reference`
- [capture-list]
  - Captures the variables that are listed either as `Call by Value` (if no `&`) and `Call by Reference` (if `&` is specified)
  - Only the variables that are listed in this list are captured

- [&, capture-list]
- [=, capture-list]

## __Specifier:__

Lambda expression can have `mutable`, `constexpr` and `noexcept` as specifiers

- mutable
- constexpr
- noexcept

## __Assigning lambda to a function pointer:__

TO DO

## Closure

### Lambda vs Closure

- From [1] and [2]
  - Lambda <==> Class
  - Closure <==> Instance of a Class

## Links

- [1]<http://scottmeyers.blogspot.com/2013/05/lambdas-vs-closures.html>
- [2]<https://leimao.github.io/blog/CPP-Closure/#:~:text=According%20to%20the%20definition%20of,with%20first%2Dclass%20functions%E2%80%9D.&text=The%20only%20nested%20functions%20allowed%20in%20C%2B%2B%20are%20lambda%20expression.>
