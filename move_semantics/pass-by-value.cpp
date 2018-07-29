/*
g++ pass-by-value.cpp

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

typedef struct FuncEntryLog
{
    const char * _pFuncName;
    const void * _pAddress;
    FuncEntryLog(const char * pFuncName, const void * pAddress):_pFuncName{pFuncName}, _pAddress(pAddress)
    {
        std::cout << this << ": " << "Entering " << pFuncName << std::endl;
    }
    ~FuncEntryLog()
    {
        std::cout << this << ": " << "Leaving " << _pFuncName << std::endl;
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
{
    FuncEntryLog fs(__FUNCTION__, nullptr);
    a.PrintAddress("Inside f, details of a: ");
    return a;
}

int main()
{
    FuncEntryLog fs(__FUNCTION__, nullptr);
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

0x7ffe88a2fe80: Entering main
creating a
0x7ffe88a2fe40: Entering default constructor
0x7ffe88a2fe40: Leaving default constructor
creating t
0x7ffe88a2fe40: Entering CopyConstructor
0x7ffe88a2fe40: Leaving CopyConstructor
0x7ffe88a2fe30: Entering f
0x7ffe88a2fdf0: Entering CopyConstructor
0x7ffe88a2fdf0: Leaving CopyConstructor
0x7ffe88a2fe30: Leaving f
0x7ffe88a2fe40: Entering ~test
0x7ffe88a2fe40: Leaving ~test
leaving main
0x7ffe88a2fe40: Entering ~test
0x7ffe88a2fe40: Leaving ~test
0x7ffe88a2fe40: Entering ~test
0x7ffe88a2fe40: Leaving ~test
0x7ffe88a2fe80: Leaving main
*/

/*
Notes:
    When f(a) is invoked (input as 'pass by value', a temporary object is created using copy-constructor (0x7ffe88a2fe40)
    When f(a) is returning (returning as 'pass by value'), another object is created (0x7ffe88a2fdf0) from  temporary object (0x7ffe88a2fe40) using copy-constructor

*/