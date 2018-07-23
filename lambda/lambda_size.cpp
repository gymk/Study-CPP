#include <iostream>
#include <array>

int main()
{
    auto f1 = [](){};
    std::cout << "Size of lambda [](){} : " << sizeof(f1) << std::endl;

    std::array<char, 100> ar;
    auto f2 = [&ar](){};    // lambda having pass by reference
    std::cout << "Size of lambda [&ar](){} : " << sizeof(f2) << std::endl;

    auto f3 = [ar](){}; // lambda having pass by value
    std::cout << "Size of lambda [ar](){} : " << sizeof(f3) << std::endl;

    auto f4 = [=](){}; // all by value
    std::cout << "Size of lambda [=](){} : " << sizeof(f4) << std::endl;

    auto f5 = [&](){}; // lambda having pass by value
    std::cout << "Size of lambda [&](){} : " << sizeof(f5) << std::endl;
}

/*
Size of lambda [](){} : 1
Size of lambda [&ar](){} : 8
Size of lambda [ar](){} : 100
Size of lambda [=](){} : 1
Size of lambda [&](){} : 1
*/