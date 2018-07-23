#include <iostream>
#include <functional>

void gloabal_func(void)
{
    std::cout << "I am from global funciton...\n";
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
    f = gloabal_func;
    f();

    // Invoking functor via same std::function
    f = Functor();
    f();

    // Involing a lambda from std::functiioin
    f = [](){ std::cout << "I am from lambda...\n";};
    f();
}

/*
Output:

I am from global funciton...
I am from functor...
I am from lambda...

*/