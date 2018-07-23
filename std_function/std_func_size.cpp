#include <iostream>
#include <cstdlib>
#include <array>
#include <functional>

void* operator new(std::size_t n)
{
    std::cout << "Allocating " << n << " bytes\n";
    return malloc(n);
}

void operator delete(void * p)
{
    std::cout << "Releasing some memory\n";
    free(p);
}

int main()
{
    {
        std::array<char, 4> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 8> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 16> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 20> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 24> ar;auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 32> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
    {
        std::array<char, 1000> ar;
        auto f1 = [ar](){};
        std::cout << "Lambda size : " << sizeof(f1) << std::endl;
        std::function<void()> f2 = f1;
        std::cout << "f2 size : " << sizeof(f2) << std::endl;
    }
}

/*
Output:

Lambda size : 4
f2 size : 32
Lambda size : 8
f2 size : 32
Lambda size : 16
f2 size : 32
Lambda size : 20
Allocating 20 bytes
f2 size : 32
Releasing some memory
Lambda size : 24
Allocating 24 bytes
f2 size : 32
Releasing some memory
Lambda size : 32
Allocating 32 bytes
f2 size : 32
Releasing some memory
Lambda size : 1000
Allocating 1000 bytes
f2 size : 32
Releasing some memory

*/

/*
Note that the size of std::function is always fixed.
std::function uses what is called 'small size optimization' (TO DO - study and do example code on that)
it uses dynamic memory to cover the parameters
TO DO - type erasure
*/