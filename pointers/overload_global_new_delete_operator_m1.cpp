#include <iostream>
#include <cstdlib>

class CTemp
{
public:
    CTemp()
    {
        std::cout << "Default constructor invoked " << this << std::endl;
    }
    CTemp(int x)
    {
        std::cout << "Constructor (int x) invoked: " << x << this << std::endl;
    }

    ~CTemp()
    {
        std::cout << "Destructor invoked " << this << std::endl;
    }
};

void* operator new(size_t n)
{
    void * p = malloc(n);
    
    std::cout << "custom new invoked " << p << std::endl;

    return p;
}
void operator delete(void *p)
{
    std::cout << "custom delete invoked " << p << std::endl;
    free(p);
}

int main()
{
    CTemp * pa = new CTemp;
    delete pa;

    CTemp * pb = new CTemp(100);
    delete pb;

    CTemp * pc = new CTemp[5];
    delete [] pc;
}

/*
Output:

custom new invoked 0x160dc20
Default constructor invoked 0x160dc20
Destructor invoked 0x160dc20
custom delete invoked 0x160dc20
custom new invoked 0x160dc20
Constructor (int x) invoked: 1000x160dc20
Destructor invoked 0x160dc20
custom delete invoked 0x160dc20
custom new invoked 0x160dc20
Default constructor invoked 0x160dc28
Default constructor invoked 0x160dc29
Default constructor invoked 0x160dc2a
Default constructor invoked 0x160dc2b
Default constructor invoked 0x160dc2c
Destructor invoked 0x160dc2c
Destructor invoked 0x160dc2b
Destructor invoked 0x160dc2a
Destructor invoked 0x160dc29
Destructor invoked 0x160dc28
custom delete invoked 0x160dc20
*/

/*
Notes:
    *) we can overload new/delete with same signature for customer memory management
    *) eventhough it is overloaded, constructors/ destructors are getting invoked form customer new/delete
*/

/*
Links:
    *) http://www.drdobbs.com/cpp/calling-constructors-with-placement-new/232901023
*/