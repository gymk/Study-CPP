#include <iostream>
#include <vector>
#include <cstdlib>

void* operator new(std::size_t t)
{
    void * p = malloc(t);

    std::cout << "Alloc(" << t << ',' << p << ")\n";
    return p;
}

void operator delete(void * p)
{
    std::cout << "Dealloc(" << p << ")\n";
    free(p);
}

void* operator new[](std::size_t t)
{
    void * p = malloc(t);

    std::cout << "Alloc[](" << t << ',' << p << ")\n";
    return p;
}

void operator delete[](void * p)
{
    std::cout << "Dealloc[](" << p << ")\n";
    free(p);
}

int main()
{
    std::string mystring;
    std::vector<std::string> str_list;

    mystring = "Hi";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Bye";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Dear";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Hello";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    mystring = "Seeyou";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    mystring = "Anyone";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;
}

/*
Links:
    *) https://isocpp.org/blog/2014/11/push-back-and-emplace-back
    *) https://abseil.io/tips/112
*/