#include <iostream>
#include <cstdlib>

class CTest
{
public:
    CTest()
    {
        std::cout << "default constructor invoked\n";
    }
    ~CTest()
    {
        std::cout << "destructor invoked\n";
    }

    void* operator new(size_t n)
    {
        void * p = malloc(n);

        std::cout << "class level new invoked: " << n << ' ' << p << std::endl;

        return p;
    }

    void operator delete(void * p)
    {
        std::cout << "class level delete invoked: " << p << std::endl;
        free(p);
    }

private:
    char    ai8Buf[10];
};

int main()
{
    CTest * pT = new CTest;
    delete pT;

    int * pI = new int;
    delete pI;
}

/*
Output:

class level new invoked: 10 0x24dbc20
default constructor invoked
destructor invoked
class level delete invoked: 0x24dbc20

*/

/*
Notes:
    *) it is possible to define class level new and delete overload operator
    *) in above code custom new/delete invoked only for CTest, not for int
*/

/*
Links:
    https://thispointer.com/overloading-new-and-delete-operators-at-global-and-class-level/
*/