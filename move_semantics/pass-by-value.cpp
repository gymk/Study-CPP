/*
g++ pass-by-value.cpp -std=c++11

g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.3.0-16ubuntu3' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --with-as=/usr/bin/x86_64-linux-gnu-as --with-ld=/usr/bin/x86_64-linux-gnu-ld --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3) 

*/

#include <iostream>
#include "../utils/scopelog.h"

typedef struct FuncEntryLog
{
    const char * _pFuncName;
    const void * _pAddress;
    FuncEntryLog(const char * pFuncName, const void * pAddress):_pFuncName{pFuncName}, _pAddress(pAddress)
    {
        std::cout << pAddress << ": " << "Entering " << pFuncName << std::endl;
    }
    ~FuncEntryLog()
    {
        std::cout << _pAddress << ": " << "Leaving " << _pFuncName << std::endl;
    }
} FuncEntryLog;

typedef struct test
{
    test()
    {
        FuncEntryLog fs("default constructor", this);
        //std::cout << "default costructor invoked " << this << std::endl;
    }
    ~test()
    {
        FuncEntryLog fs(__FUNCTION__, this);
        //std::cout << "destructor invoked " << this << std::endl;
    }
    // copy constructor
    test(const test & rhs)
    {
        FuncEntryLog fs("CopyConstructor", this);
        rhs.PrintAddress("Inside CopyConstructor, details of rhs: ");
    }
    void PrintAddress(const char * msg) const
    {
        std::cout << '\t' << msg << ' ' << this << std::endl;
    }
} test;

// A pass-by-value function which accepts input as 'pass by value' and returns by 'pass by value'
template <typename T>
T f(T a)
{ LOG_CALL; 
    FuncEntryLog fs(__FUNCTION__, nullptr);
    a.PrintAddress("Inside f, details of a: ");
    return a;
}

int main()
{ LOG_CALL; 
    FuncEntryLog fs(__FUNCTION__, (void*)&main);
    std::cout << "creating a\n";
    test a;
    a.PrintAddress("Inside main, details of a: ");
    std::cout << "creating t\n";
    test t = f(a);
    t.PrintAddress("Inside main, details of t: ");
    std::cout << "leaving main\n";
}

/*
Output:

0x400a76: Entering main
creating a
0x7fffb4e03c8d: Entering default constructor
0x7fffb4e03c8d: Leaving default constructor
	Inside main, details of a:  0x7fffb4e03c8d
creating t
0x7fffb4e03c8f: Entering CopyConstructor
	Inside CopyConstructor, details of rhs:  0x7fffb4e03c8d
0x7fffb4e03c8f: Leaving CopyConstructor
0: Entering f
	Inside f, details of a:  0x7fffb4e03c8f
0x7fffb4e03c8e: Entering CopyConstructor
	Inside CopyConstructor, details of rhs:  0x7fffb4e03c8f
0x7fffb4e03c8e: Leaving CopyConstructor
0: Leaving f
0x7fffb4e03c8f: Entering ~test
0x7fffb4e03c8f: Leaving ~test
	Inside main, details of t:  0x7fffb4e03c8e
leaving main
0x7fffb4e03c8e: Entering ~test
0x7fffb4e03c8e: Leaving ~test
0x7fffb4e03c8d: Entering ~test
0x7fffb4e03c8d: Leaving ~test
0x400a76: Leaving main

*/

/*
Notes:
    When f(a) is invoked (input as 'pass by value', a temporary object is created using copy-constructor (0x7fffb4e03c8f)
    When f(a) is returning (returning as 'pass by value'), another object is created (0x7fffb4e03c8e) from  temporary object (0x7fffb4e03c8f) using copy-constructor
        temp object (0x7fffb4e03c8f) is deleted at exit of f(a)

*/