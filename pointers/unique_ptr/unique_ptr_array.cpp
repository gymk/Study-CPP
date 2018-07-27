/*
g++ unique_ptr_array.cpp -std=c++11 -lpthread

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

const int arr_size = 5;

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

void* operator new[](size_t t)
{
    void * p = malloc(t);

    std::cout << "Allocating array " << t << ' ' << p << std::endl;

    return p;
}

void operator delete[](void * p)
{
    std::cout << "Deallocating array " << p << std::endl;
    free(p);
}

void UniquePtr_CheckScopeMovement(std::unique_ptr<int[]> pArray, int startval)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::cout << pArray.get() << std::endl;
    for(int i = 0; i < arr_size; i++)
        pArray[i] = i+startval;

    for(int i = 0; i < arr_size; i++) // Output: 1 2 3 4 5
        std::cout << pArray[i] << ' ';
    std::cout << std::endl;
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_CheckScopeMovement_Ref(std::unique_ptr<int[]> & pArray, int startval)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::cout << pArray.get() << std::endl;
    for(int i = 0; i < arr_size; i++)
        pArray[i] = i+startval;

    for(int i = 0; i < arr_size; i++) // Output: 1 2 3 4 5
        std::cout << pArray[i] << ' ';
    std::cout << std::endl;
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_LocalScopeCheck(void)   // All the unique_ptr will be released at exit of this function
{
    std::unique_ptr<int[]> pIArray(new int[5]);
    for(int i = 0; i < 5; i++)
        pIArray[i] = i+1;

    for(int i = 0; i < 5; i++) // Output: 1 2 3 4 5
        std::cout << pIArray[i] << ' ';
    std::cout << std::endl;

    std::cout << std::endl;
}

void UniquePtr_CheckOwnershipMove(void)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::unique_ptr<int[]> pA(new int[arr_size]);

    std::unique_ptr<int[]> pB = std::move(pA);

    std::cout << pA.get() << std::endl;  // pA will have null
    std::cout << pB.get() << std::endl;  // 80 should be printed
    std::cout << "Exit " << __FUNCTION__ << std::endl;

    std::cout << std::endl;
}

void UniquePtr_CheckOwnershipRelease(void)
{
    std::cout << "Entering " << __FUNCTION__ << std::endl;
    std::unique_ptr<int[]> pA(new int[arr_size]);

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
    std::unique_ptr<int[]> pA(new int[arr_size]);

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
        std::unique_ptr<int[]> pIScalar(new int[arr_size]);
        UniquePtr_CheckScopeMovement(std::move(pIScalar), 100);    // pIScalar will be released after UniquePtr_CheckScalarScopeMovement execution
    }
    {   // Passing to function as argument
        std::unique_ptr<int[]> pIScalar(new int[arr_size]);
        UniquePtr_CheckScopeMovement_Ref(pIScalar, 200);
    }   // pIScalar will be released after this scope
    {   // Passing to thread as argument
        // TO DO - why scalar of size 56 crated for this?
        std::unique_ptr<int[]> pIScalar(new int[arr_size]);
        std::thread th(UniquePtr_CheckScopeMovement, std::move(pIScalar), 300);

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

Allocating array 20 0xa0cc20
Entering UniquePtr_CheckScopeMovement
0xa0cc20
100 101 102 103 104 
Exit UniquePtr_CheckScopeMovement

Deallocating array 0xa0cc20
Allocating array 20 0xa0cc20
Entering UniquePtr_CheckScopeMovement_Ref
0xa0cc20
200 201 202 203 204 
Exit UniquePtr_CheckScopeMovement_Ref

Deallocating array 0xa0cc20
Allocating array 20 0xa0cc20
Allocating scalar 64 0xa0d050
Entering UniquePtr_CheckScopeMovement
0xa0cc20
300 301 302 303 304 
Exit UniquePtr_CheckScopeMovement

Deallocating array 0xa0cc20
Deallocating scalar 0xa0d050
Allocating array 20 0xa0cc20
1 2 3 4 5 

Deallocating array 0xa0cc20
Entering UniquePtr_CheckOwnershipMove
Allocating array 20 0xa0cc20
0
0xa0cc20
Exit UniquePtr_CheckOwnershipMove

Deallocating array 0xa0cc20
Entering UniquePtr_CheckOwnershipRelease
Allocating array 20 0xa0cc20
unique_ptr object address before release: 0xa0cc20
unique_ptr object address after release: 0
Value of pI: 0xa0cc20
Value @ *pI: 0
Exit UniquePtr_CheckOwnershipRelease

Entering UniquePtr_CheckReset
Allocating array 20 0xa0d1d0
unique_ptr object address before release: 0xa0d1d0
Deallocating array 0xa0d1d0
unique_ptr object address after release: 0
Exit UniquePtr_CheckReset

*/