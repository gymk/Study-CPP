#include <iostream>
#include <array>

struct MyStruct
{
    MyStruct()
    {
        std::cout << "MyStruct's Constructor invoked...\n";
    }
    ~MyStruct()
    {
        std::cout << "MyStruct's Destructor invoked...\n";
    }
    MyStruct(const MyStruct&)
    {
        std::cout << "MyStruct's Copy Constructor invoked...\n";
    }
    void PrintTest(void) const  // Without this const, we can't access any of the members/ member function, because lamda args are passed as const
    {
        std::cout << "PrintTest\n";
    }
};

int main()
{
    std::cout << "Entering main\n";
    MyStruct ms;
    // capture by value - Only MyStruct
    {
        /*
        Note here that while creating lamba object pass by value gets executed, that is before lambda object get invoked
        */
        std::cout << "Creating Lambda having MyStruct as argument\n";
        auto f1 = [ms](){}; // ms is passed by value, so copy constructor gets invoked
        std::cout << "Destroying Lambda having MyStruct as argument\n";
    }
    std::cout << "\n";
    // capture by reference - Only MyStruct
    {
        std::cout << "Creating Lambda having MyStruct as reference\n";
        auto f1 = [&ms](){}; // ms is passed by reference, so copy constructor gets invoked
        std::cout << "Destroying Lambda having MyStruct as reference\n";
    }
    std::cout << "\n";
    // capture by value - All
    {
        MyStruct ms2;
        std::cout << "Creating Lambda having MyStruct as argument\n";
        auto f1 = [=](){}; // everything captured as value, since none of the variable used inside lamba, nothing passed, resulting no MyStruct constructor/ destrucor call
        std::cout << "Destroying Lambda having MyStruct as argument\n";
    }
    std::cout << "\n";
    // capture by value - All
    {
        MyStruct ms2;
        std::cout << "Creating Lambda having MyStruct as argument\n";
        auto f1 = [=](){ms.PrintTest(); ms2.PrintTest();}; // everything captured as value. Since both ms and ms2 used, two copy-constructor/ destructor calles observed
        std::cout << "Destroying Lambda having MyStruct as argument\n";
    }
    std::cout << "\n";
    // capture by reference - All
    {
        std::cout << "Creating Lambda having MyStruct as reference\n";
        auto f1 = [&](){ ms.PrintTest(); }; // everying captured as reference
        std::cout << "Destroying Lambda having MyStruct as reference\n";
    }
    std::cout << "\n";
    std::cout << "Exiting from main\n";
}

/*
Output:

Entering main
MyStruct's Constructor invoked...
Creating Lambda having MyStruct as argument
MyStruct's Copy Constructor invoked...
Destroying Lambda having MyStruct as argument
MyStruct's Destructor invoked...

Creating Lambda having MyStruct as reference
Destroying Lambda having MyStruct as reference

MyStruct's Constructor invoked...
Creating Lambda having MyStruct as argument
Destroying Lambda having MyStruct as argument
MyStruct's Destructor invoked...

MyStruct's Constructor invoked...
Creating Lambda having MyStruct as argument
MyStruct's Copy Constructor invoked...
MyStruct's Copy Constructor invoked...
Destroying Lambda having MyStruct as argument
MyStruct's Destructor invoked...
MyStruct's Destructor invoked...
MyStruct's Destructor invoked...

Creating Lambda having MyStruct as reference
Destroying Lambda having MyStruct as reference

Exiting from main
MyStruct's Destructor invoked...



*/

/*
Note that lambda are scoped w.r.to where it is defined
Arguments are passed as const to lambda
*/