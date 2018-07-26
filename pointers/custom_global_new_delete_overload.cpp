/*
 * Below is for study only
 * it is strongly recommended not to do like below
 * reason ==> 1) refer http://www.scs.stanford.edu/~dm/home/papers/c++-new.html
 *            2) you can't overload delete with custom parameter, you need some wrapper
 */

#include <iostream>
#include <cstdlib>

class CTemp
{
public:
    CTemp()
    {
        std::cout << "Detault constructor invoked " << this << std::endl;
    }
    CTemp(int x)
    {
        std::cout << "Constructor (int x) invoked: " << x << this << std::endl;
    }

    ~CTemp()
    {
        std::cout << "Destructor invoked " << this << std::endl;
    }

    int _t[10];
};

typedef enum tagMemAllocType
{
        HEAP_MEMORY
    ,   SECURE_MEMORY
} MEM_TYPE;

void* operator new(size_t n)
{
    void * p = malloc(n);   // std::malloc can be used

    std::cout << "ver1-custom new size: " << n << ' ' << p << std::endl;

    return p;
}
void* operator new[](size_t n)
{
    void * p = malloc(n);   // std::malloc can be used

    std::cout << "ver1-custom new[] size: " << n << ' ' << p << std::endl;

    return p;
}
// overload operator new with additional parameter telling which type of memory to be used
void* operator new(size_t n, MEM_TYPE alloc_type)
{
    void * p = malloc(n);   // std::malloc can be used

    std::cout << "ver2-custom new size: " << n << " MemType: " << alloc_type << ' ' << p << std::endl;

    return p;
}
void* operator new[](size_t n, MEM_TYPE alloc_type)
{
    void * p = malloc(n);   // std::malloc can be used

    std::cout << "ver2-custom new[] size: " << n << " MemType: " << alloc_type << ' ' << p << std::endl;

    return p;
}

void operator delete(void * p)
{
    std::cout << "ver1-custom delete " << p << std::endl;
    free(p);    // std::free can be used
}
void operator delete[](void * p)
{
    std::cout << "ver1-custom delete[] " << p << std::endl;
    free(p);    // std::free can be used
}
// based on mem_type delete should free accordingly, TO-DO
void operator delete(void * p, MEM_TYPE alloc_type)
{
    std::cout << "ver2-custom delete " << p << std::endl;
    free(p);    // std::free can be used
}
void operator delete[](void * p, MEM_TYPE alloc_type)
{
    std::cout << "ver2-custom delete[] " << p << std::endl;
    free(p);    // std::free can be used
}

// placement delete operator - which get invoked only from constructor (if it throws exception)
void operator delete(void * p, CTemp & delItem)
{
    std::cout << "placement-delete invoked " << p << std::endl;
    free(p);
}

int main()
{
    // Test with custom new and delete
    {
        CTemp * pa = new (HEAP_MEMORY) CTemp;
        //delete (pa, HEAP_MEMORY);
        delete pa;
    }
    {
        CTemp * pa = new (SECURE_MEMORY) CTemp;
        delete pa;
    }

    {
        CTemp * pa = new (HEAP_MEMORY) CTemp(100);
        delete pa;
    }
    {
        CTemp * pa = new (SECURE_MEMORY) CTemp(100);
        delete pa;
    }

    // For array, we need to overload new[] delete[]
    // Below arrays will invoke overloaded new[] delete[]
    {
        CTemp * pa = new (HEAP_MEMORY) CTemp[5];
        delete [] pa;
    }
    {
        CTemp * pa = new (SECURE_MEMORY) CTemp[5];
        delete [] pa;
    }
    std::cout << std::endl;
    std::cout << std::endl;

    // Test whether it is possible to use normal and custom new/delete together???
    std::cout << "Trying to use normal new\n";

    {
        CTemp * norm_pa = new CTemp;
        delete norm_pa;
    }

}

/*
Output:

ver2-custom new size: 40 MemType: 0 0x1261c20
Detault constructor invoked 0x1261c20
Destructor invoked 0x1261c20
ver1-custom delete 0x1261c20
ver2-custom new size: 40 MemType: 1 0x1261c20
Detault constructor invoked 0x1261c20
Destructor invoked 0x1261c20
ver1-custom delete 0x1261c20
ver2-custom new size: 40 MemType: 0 0x1261c20
Constructor (int x) invoked: 1000x1261c20
Destructor invoked 0x1261c20
ver1-custom delete 0x1261c20
ver2-custom new size: 40 MemType: 1 0x1261c20
Constructor (int x) invoked: 1000x1261c20
Destructor invoked 0x1261c20
ver1-custom delete 0x1261c20
ver2-custom new[] size: 208 MemType: 0 0x1262060
Detault constructor invoked 0x1262068
Detault constructor invoked 0x1262090
Detault constructor invoked 0x12620b8
Detault constructor invoked 0x12620e0
Detault constructor invoked 0x1262108
Destructor invoked 0x1262108
Destructor invoked 0x12620e0
Destructor invoked 0x12620b8
Destructor invoked 0x1262090
Destructor invoked 0x1262068
ver1-custom delete[] 0x1262060
ver2-custom new[] size: 208 MemType: 1 0x1262060
Detault constructor invoked 0x1262068
Detault constructor invoked 0x1262090
Detault constructor invoked 0x12620b8
Detault constructor invoked 0x12620e0
Detault constructor invoked 0x1262108
Destructor invoked 0x1262108
Destructor invoked 0x12620e0
Destructor invoked 0x12620b8
Destructor invoked 0x1262090
Destructor invoked 0x1262068
ver1-custom delete[] 0x1262060


Trying to use normal new
ver2-custom new size: 40 0x1261c20
Detault constructor invoked 0x1261c20
Destructor invoked 0x1261c20
ver1-custom delete 0x1261c20

*/

/*
Notes:

    *) To give pass additional parameters to overload new operator, parameters need to listed inside braces, which need to be placed inbetween new and T
        new (args) T
            First parameter: size of memory will be given automatically by compiler, so only remaining args that are needed to be listed inside braces
*/

/*
TO DO
    *) is it possible to use std::unique_ptr std::shared_ptr with custom new/delete???
    *) How to use ver2 delete???
        It is not possible to use.
        We may define placement-delete, but it will get invoked only by constructors on exceptions, not on normal delete
*/

/*
Links:
    *) http://www.drdobbs.com/cpp/calling-constructors-with-placement-new/232901023?pgno=1
*/