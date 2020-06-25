#include <iostream>

template<typename T, size_t n>
constexpr size_t size_of( T (&) [n])
{
    return n;
}

int main()
{
    int x[10];
    int y[size_of(x)];
    int z[size_of(y)];

    std::cout << "sizeof(x): " << sizeof(x) << std::endl;
    std::cout << "size_of(x): " << size_of(x) << std::endl;
    std::cout << "sizeof(y): " << sizeof(y) << std::endl;
    std::cout << "size_of(y): " << size_of(y) << std::endl;

    int a[] = { 11, 22, 33};    // int array of size 3
    int * pa = a;               // pointer to a
    int (&ar)[3] = a;           // refernce to a[3]

    for(auto m : ar)
    {
        std::cout << m << ' ';
    }
    std::cout << std::endl;
}

/*
Output:
sizeof(x): 40
size_of(x): 10
sizeof(y): 40
size_of(y): 10
11 22 33 
*/

/*
Notes:
    *) using template argument deduction, compiler will deduce the value 'n'
    *) since constexpr is used, during compile time value will be calculated and substituted in main() for variable creation. Hence we are able to use size_of(y) in std::cout.
*/

/*
Links
    *) https://stackoverflow.com/questions/437150/can-someone-explain-this-template-code-that-gives-me-the-size-of-an-array
*/