/* https://akrzemi1.wordpress.com/2017/06/28/compile-time-string-concatenation/ */

/* g++ run_after_main.cpp */
#include <iostream>
#include <exception>

void run_after_main(void)
{
    std::cout << "Executing " << __PRETTY_FUNCTION__ << std::endl;
}

struct laterun
{
    laterun()
    {
        std::set_terminate(run_after_main);
    }
    ~laterun()
    {
        throw "except";
    }
} laterunGlobalObj;

int main()
{
    std::cout << "Exiting main()" << std::endl;
}

/*
Output:

Exiting main()
Executing void run_after_main()
Aborted (core dumped)

*/
