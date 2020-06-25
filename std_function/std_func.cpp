#include <iostream>
#include <functional>

void global_func(void)
{
    std::cout << "I am from global function...\n";
}

struct Functor
{
    void operator()()
    {
        std::cout << "I am from functor...\n";
    }
};

int main()
{
    std::function<void()> f;

    // Invoking a global functor via std::function
    f = global_func;
    f();

    // Invoking functor via same std::function
    f = Functor();
    f();

    // Involving a lambda from std::function
    f = [](){ std::cout << "I am from lambda...\n";};
    f();
}

/*
Output:

I am from global function...
I am from functor...
I am from lambda...

*/

/*
Notes:
    *) as long as function signature matches, std::function can take function/ functor/ lambda as values
*/

/*
TO DO:
    *) Need more notes
*/