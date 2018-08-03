# Variadic Templates



```
template <typename... Args>
<return_type> TemplateName<Args... args>
{
}
```

`typename... Args` is called a __template parameter pack__. Args can be any arbitrary name.

`Args... args` is called a __function parameter pack__

Ellipis `...` is an _operator_

## template parameter pack

It can have zero parameters packed in it. [Link](https://stackoverflow.com/questions/28354752/template-vs-template-without-brackets-whats-the-difference)
It will be used to declare a specialization of the template, with different body.

```
E.g.,
template <>
void foo<int>(int& t);
```



TO DO

## function parameter pack

TO DO

### parameter pack expansion

TO DO - https://stackoverflow.com/questions/25680461/variadic-template-pack-expansion


### 

# Links

	*) https://eli.thegreenplace.net/2014/variadic-templates-in-c/
	*) http://kevinushey.github.io/blog/2016/01/27/introduction-to-c++-variadic-templates/

	
# Example

## Function Template

```
/* g++ var1.cpp -std=c++11 */
#include <iostream>
#include <string>

// #########
// # ADDER #
// #########
template <typename T>
T adder(T v)
{
    std::cout << "ADDER_SINGLE: " << __PRETTY_FUNCTION__ << std::endl;
    return v;
}

template <typename T, typename... Args>
T adder(T first, Args... args)
{
    std::cout << "ADDER_ARGS: " << __PRETTY_FUNCTION__ << std::endl;
    return first + adder(args...);
}

// #############################
// # Pair Compare of same type #
// #############################
template <typename T>
bool pair_compare_same(T a) // For single parameter
{
    std::cout << "PAIR_COMPARE_SAME_SINGLE: " << __PRETTY_FUNCTION__ << std::endl;
    return false;
}

template <typename T>
bool pair_compare_same(T a, T b)    // For two parameter
{
    std::cout << "PAIR_COMPARE_SAME_TWO: " << __PRETTY_FUNCTION__ << std::endl;
    return (a == b);
}

template <typename T, typename... Args> // for more than 2 parameters
bool pair_compare_same(T a, T b, Args... args)
{
    std::cout << "PAIR_COMPARE_SAME_ARGS: " << __PRETTY_FUNCTION__ << std::endl;
    return (a == b) && pair_compare_same(args...);
}

// #############################
// # Pair Compare for any type #
// #############################
template <typename T>
bool pair_compare_any(T a)  // For single parameter
{
    std::cout << "PAIR_COMPARE_ANY_TWO: " << __PRETTY_FUNCTION__ << std::endl;
    return false;
}

template <typename T, typename U>
bool pair_compare_any(T a, U b) // For two parameter
{
    std::cout << "PAIR_COMPARE_ANY_TWO: " << __PRETTY_FUNCTION__ << std::endl;
    return (a == b);
}

template <typename T, typename U, typename... VarArgs> // for more than 2 parameters
bool pair_compare_any(T a, U b, VarArgs... args)
{
    std::cout << "PAIR_COMPARE_ANY_ARGS: " << __PRETTY_FUNCTION__ << std::endl;
    return (a == b) && pair_compare_any(args...);
}

int main()
{
    std::cout << "adder(1, 2, 3, 4, 5): " << adder(1, 2, 3, 4, 5) << std::endl << std::endl;
    std::cout << "adder(10): " << adder(10) << std::endl << std::endl;
    std::cout << "adder(1, 1.5): " << adder(1, 1.5) << std::endl << std::endl;

    std::cout << std::endl;

    std::string s1 {"one"};
    std::string s2 {"two"};
    std::string s3 {"three"};
    std::string s4 {"four"};

    std::string joined = adder(s1, s2, s3, s4);

    std::cout << "adder(s1, s2, s3, s4): " << joined << std::endl << std::endl;

    //std::cout << "pair_compare_same(1, 1.0): " << pair_compare_same(1, 1.0) << std::endl << std::endl;    // KO - only same type
    std::cout << "pair_compare_same(1, 1, 1, 1): " << pair_compare_same(1, 1, 1, 1) << std::endl << std::endl;
    std::cout << "pair_compare_same(1, 1, 1): " << pair_compare_same(1, 1, 1) << std::endl << std::endl;
    std::cout << "pair_compare_same(1, 1, 1, 1, 1, 1): " << pair_compare_same(1, 1, 1, 1, 1, 1) << std::endl << std::endl;
    std::cout << "pair_compare_same(1, 2): " << pair_compare_same(1, 2) << std::endl << std::endl;
    std::cout << "pair_compare_same(8): " << pair_compare_same(8) << std::endl << std::endl;

    std::cout << "pair_compare_any(1, 1.0, true, 1): " << pair_compare_any(1L, 1.0, true, 1U, 1, 1) << std::endl << std::endl;
}


/*
Output:

ADDER_ARGS: T adder(T, Args ...) [with T = int; Args = {int, int, int, int}]
ADDER_ARGS: T adder(T, Args ...) [with T = int; Args = {int, int, int}]
ADDER_ARGS: T adder(T, Args ...) [with T = int; Args = {int, int}]
ADDER_ARGS: T adder(T, Args ...) [with T = int; Args = {int}]
ADDER_SINGLE: T adder(T) [with T = int]
adder(1, 2, 3, 4, 5): 15

ADDER_SINGLE: T adder(T) [with T = int]
adder(10): 10

ADDER_ARGS: T adder(T, Args ...) [with T = int; Args = {double}]
ADDER_SINGLE: T adder(T) [with T = double]
adder(1, 1.5): 2


ADDER_ARGS: T adder(T, Args ...) [with T = std::basic_string<char>; Args = {std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >}]
ADDER_ARGS: T adder(T, Args ...) [with T = std::basic_string<char>; Args = {std::basic_string<char, std::char_traits<char>, std::allocator<char> >, std::basic_string<char, std::char_traits<char>, std::allocator<char> >}]
ADDER_ARGS: T adder(T, Args ...) [with T = std::basic_string<char>; Args = {std::basic_string<char, std::char_traits<char>, std::allocator<char> >}]
ADDER_SINGLE: T adder(T) [with T = std::basic_string<char>]
adder(s1, s2, s3, s4): onetwothreefour

PAIR_COMPARE_SAME_ARGS: bool pair_compare_same(T, T, Args ...) [with T = int; Args = {int, int}]
PAIR_COMPARE_SAME_TWO: bool pair_compare_same(T, T) [with T = int]
pair_compare_same(1, 1, 1, 1): 1

PAIR_COMPARE_SAME_ARGS: bool pair_compare_same(T, T, Args ...) [with T = int; Args = {int}]
PAIR_COMPARE_SAME_SINGLE: bool pair_compare_same(T) [with T = int]
pair_compare_same(1, 1, 1): 0

PAIR_COMPARE_SAME_ARGS: bool pair_compare_same(T, T, Args ...) [with T = int; Args = {int, int, int, int}]
PAIR_COMPARE_SAME_ARGS: bool pair_compare_same(T, T, Args ...) [with T = int; Args = {int, int}]
PAIR_COMPARE_SAME_TWO: bool pair_compare_same(T, T) [with T = int]
pair_compare_same(1, 1, 1, 1, 1, 1): 1

PAIR_COMPARE_SAME_TWO: bool pair_compare_same(T, T) [with T = int]
pair_compare_same(1, 2): 0

PAIR_COMPARE_SAME_SINGLE: bool pair_compare_same(T) [with T = int]
pair_compare_same(8): 0

PAIR_COMPARE_ANY_ARGS: bool pair_compare_any(T, U, VarArgs ...) [with T = long int; U = double; VarArgs = {bool, unsigned int, int, int}]
PAIR_COMPARE_ANY_ARGS: bool pair_compare_any(T, U, VarArgs ...) [with T = bool; U = unsigned int; VarArgs = {int, int}]
PAIR_COMPARE_ANY_TWO: bool pair_compare_any(T, U) [with T = int; U = int]
pair_compare_any(1, 1.0, true, 1): 1

*/

```

## Class Template

TO DO