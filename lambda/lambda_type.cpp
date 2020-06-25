#include <iostream>

int main()
{
    // Assigning lambda to a C function pointer and invoking it
    void (*f1_c_type)(void);
    auto f1 = [](){std::cout << "From f1\n";};
    f1_c_type = f1;
    f1_c_type();

    // with param
    void (*f2_c_type)(int);
    auto f2 = [](int val){ std::cout << "From f2: " << val << std::endl; };
    f2_c_type = f2;
    f2_c_type(10);
}

/*
Output:

If signautre matches, lambda can be assigned to a function pointer and can be invoked.
Be cautiously on parameters that are captured. If referenced, scoping should be taken care.
It is best practice to use auto to let compiler deduce the type (like above f1, f2)
Because lambda actual type is defined based on bespoke lamda's actual implementation

From f1
From f2: 10
*/