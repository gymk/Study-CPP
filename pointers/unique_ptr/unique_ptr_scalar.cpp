/*
g++ unique_ptr_scalar.cpp -std=c++11 -lpthread

g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.10' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10)
*/

#include <iostream>
#include <memory>
#include <thread>

// Overloading new and delete to check std::unqiue_ptr alloc/ dealloc sequences
void* operator new(size_t t)
{
    void * p = malloc(t);

    std::cout << "Allocating scalar " << t << ' ' << p << std::endl;

    return p;
}

void operator delete(void * p)
{
    std::cout << "Deallocating scalar " << p << std::endl;
    free(p);
}


void UniquePtr_CheckScalarScopeMovement(std::unique_ptr<int> pScalar)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::cout << *pScalar << std::endl;
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_LocalScopeCheck(void)   // All the unique_ptr will be released at exit of this function
{
    std::unique_ptr<int> pIScalar(new int(100));

    std::cout << *pIScalar << std::endl;    // Output: 100

    std::cout << std::endl;
}

void UniquePtr_CheckOwnershipMove(void)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::unique_ptr<int> pA(new int(80));

    std::unique_ptr<int> pB = std::move(pA);

    std::cout << pA.get() << std::endl;  // pA will have null
    std::cout << pB.get() << std::endl;  // 80 should be printed
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_CheckOwnershipRelease(void)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::unique_ptr<int> pA(new int(30));

    std::cout << "unique_ptr object address before release: " << pA.get() << std::endl;  // pA will have null
    int * pI = pA.release();
    // note below that get() is used, if deferenced it will crash the program
    std::cout << "unique_ptr object address after release: " << pA.get() << std::endl;  // pA will have null
    std::cout << "Value of pI: " << pI << std::endl;  // should print the address given by std::unique_ptr
    std::cout << "Value @ *pI: " << *pI << std::endl;  // 30 should be printed
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_CheckReset(void)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::unique_ptr<int> pA(new int(30));

    std::cout << "unique_ptr object address before release: " << pA.get() << std::endl;  // pA will have null
    pA.reset();
    // note below that get() is used, if deferenced it will crash the program
    std::cout << "unique_ptr object address after release: " << pA.get() << std::endl;  // pA will have null
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

struct test
{
    void print(void)
    {
        std::cout << "test struct print\n";
    }
};
void UniquePtr_ReturningUniquePtr(void)
{
}

int main()
{
    {   // Passing to function as argument
        std::unique_ptr<int> pIScalar(new int(500));
        UniquePtr_CheckScalarScopeMovement(std::move(pIScalar));    // pIScalar will be released after UniquePtr_CheckScalarScopeMovement execution
    }
    {   // Passing to thread as argument
        std::unique_ptr<int> pIScalar(new int(600));
        std::thread th(UniquePtr_CheckScalarScopeMovement, std::move(pIScalar));

        th.join();
    }

    {   // Check std::unqie_ptr behaviour when scope is out
        UniquePtr_LocalScopeCheck();
    }

    {   // try to pass ownership to another variable within a scope and see the result
        UniquePtr_CheckOwnershipMove();
    }

    {   // Check release() functionality
        UniquePtr_CheckOwnershipRelease();
    }

    {   // check reset() functionality
        UniquePtr_CheckReset();
    }
}

/*
Output:

Allocating scalar 4 0x1a43c20
Entering UniquePtr_CheckScalarScopeMovement
500
Exit UniquePtr_CheckScalarScopeMovement

Deallocating scalar 0x1a43c20
Allocating scalar 4 0x1a43c20
Allocating scalar 56 0x1a44050
Entering UniquePtr_CheckScalarScopeMovement
600
Exit UniquePtr_CheckScalarScopeMovement

Deallocating scalar 0x1a43c20
Deallocating scalar 0x1a44050
Allocating scalar 4 0x1a43c20
100

Deallocating scalar 0x1a43c20
Entering UniquePtr_CheckOwnershipMove
Allocating scalar 4 0x1a43c20
0
0x1a43c20
Exit UniquePtr_CheckOwnershipMove

Deallocating scalar 0x1a43c20
Entering UniquePtr_CheckOwnershipRelease
Allocating scalar 4 0x1a43c20
unique_ptr object address before release: 0x1a43c20
unique_ptr object address after release: 0
Value of pI: 0x1a43c20
Value @ *pI: 30
Exit UniquePtr_CheckOwnershipRelease

Entering UniquePtr_CheckReset
Allocating scalar 4 0x1a441c0
unique_ptr object address before release: 0x1a441c0
Deallocating scalar 0x1a441c0
unique_ptr object address after release: 0
Exit UniquePtr_CheckReset

*/

/*
Notes:
    *) two kinds of uniqute_ptr available
        *) scalar
            eg., std::unique_ptr<int>
        *) array
            eg., std::unique_ptr<int[]>
    *) Creating std:unique_ptr
        *) C++14 and above
            auto p = std::make_unique<type>(constructor to invoke for that type)
            auto p = std::make_unique<type[]>(n)(constructor to invoke for that type)
        *) C++11
            std::unique_ptr<type> variable(new type(construtor to invoke for that type));
        *) < C++11
            not supported
    *) no copy or assginment constructor
    *) only move constructor for moving the ownership
    *) memory is owned by std::uniqure_ptr only
    *) Delete
        *) on scope exit of std::unique_ptr<> memory will be free'd
        *) alternatively p.reset() will release the memory
*/