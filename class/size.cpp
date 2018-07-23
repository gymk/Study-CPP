#include <iostream>

// Empty Struct
typedef struct tagEmptyStruct
{
} EMPTY_STRUCT;
// Empty Class
class CEmptyClass
{
};
// Empty Functor
class CFunctor
{
public:
    void operator()()
    {
        std::cout << "Empty Functor\n";
    }
};

int main()
{
    std::cout << "Size of empty class: " << sizeof(CEmptyClass) << std::endl;
    std::cout << "Size of empty struct: " << sizeof(EMPTY_STRUCT) << std::endl;
    std::cout << "Size of empty functor: " << sizeof(CFunctor) << std::endl;
    
    auto f1 = [](){};
    std::cout << "Size of empty lambda: " << sizeof(f1) << std::endl;
}

/*
Output:
Size of empty class: 1
Size of empty struct: 1
Size of empty functor: 1
Size of empty lambda: 1

in C++ to have unique address for each object even if it is empty, it will have single dummy on byte
eg., new EMPTY_STRUCT[10] should return 10 unique address, if size is zero, all objects will have same address
which is not valid, so dummy byte for empty/ struct/ functor

if empty struct/class is inherited, their won't be any dummy value in inherited structure/ class
*/