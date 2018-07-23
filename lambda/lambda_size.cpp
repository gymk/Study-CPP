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

    auto f4 = [=](){}; // all by value, std::array is not used, so ar is not passed to lamba
    std::cout << "Size of lambda [=](){} ar not used : " << sizeof(f4) << std::endl;

    auto f5 = [=](){ std::cout << ar.empty() << std::endl; }; // all by value - std::array is used, ar getting passed to lambda
    std::cout << "Size of lambda [=](){} ar used : " << sizeof(f5) << std::endl;

    auto f6 = [&](){}; // lambda having pass by value
    std::cout << "Size of lambda [&](){} : " << sizeof(f6) << std::endl;
}

/*
Size of lambda [](){} : 1
Size of lambda [&ar](){} : 8
Size of lambda [ar](){} : 100
Size of lambda [=](){} ar not used : 1
Size of lambda [=](){} ar used : 100
Size of lambda [&](){} : 1
*/