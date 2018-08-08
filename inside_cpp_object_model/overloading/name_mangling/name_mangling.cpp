/*
g++ name_mangling.cpp -o name_mangling.out

g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.10' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10)
*/

/*
objdump -t

objdump -v
GNU objdump (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.

objdump -D name_mangling.out > name_mangling.disassembly
objdump -t name_mangling.out > name_mangling.symbols
*/

/*
nm name_mangling.out > name_mangling.nm

nm --v
GNU nm (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
*/

/*
nm name_mangling.out | c++filt > name_mangling.c++filt

c++filt --v
GNU c++filt (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
*/
#include <iostream>

namespace test_namespace
{

class CTest
{
public:
    CTest()
    {
        //
    }
    ~CTest()
    {
        //
    }

    void test_print(void)
    {
        std::cout << "From test_namespace::CTest::test_print" << std::endl;
    }
    void test_print(int i)
    {
        std::cout << "From test_namespace::CTest::test_print(int i)" << std::endl;
    }
    void test_print(double i)
    {
        std::cout << "From test_namespace::CTest::test_print(double i)" << std::endl;
    }
};

void test_print(void)
{
    std::cout << "From test_namespace::test_print()" << std::endl;
}
void test_print(int i)
{
    std::cout << "From test_namespace::test_print(int i)" << std::endl;
}
void test_print(double i)
{
    std::cout << "From test_namespace::test_print(double i)" << std::endl;
}

}   // namespace test_namespace

class CTest
{
public:
    CTest()
    {
        //
    }
    ~CTest()
    {
        //
    }

    void test_print(void)
    {
        std::cout << "From ::CTest::test_print" << std::endl;
    }
    void test_print(int i)
    {
        std::cout << "From ::CTest::test_print(int i)" << std::endl;
    }
    void test_print(double i)
    {
        std::cout << "From ::CTest::test_print(double i)" << std::endl;
    }
};

void test_print(void)
{
    std::cout << "From ::test_print()" << std::endl;
}
void test_print(int i)
{
    std::cout << "From ::test_print(int i)" << std::endl;
}
void test_print(double i)
{
    std::cout << "From ::test_print(double i)" << std::endl;
}


int main()
{
    test_namespace::CTest tt1;
    tt1.test_print();
    tt1.test_print(1);
    tt1.test_print(1.0);
    test_namespace::test_print();
    test_namespace::test_print(1);
    test_namespace::test_print(1.0);
    std::cout << std::endl;

    CTest tt2;
    tt2.test_print();
    tt2.test_print(1);
    tt2.test_print(1.0);
    test_print();
    test_print(1);
    test_print(1.0);
}

/*
Output:

From test_namespace::CTest::test_print
From test_namespace::CTest::test_print(int i)
From test_namespace::CTest::test_print(double i)
From test_namespace::test_print()
From test_namespace::test_print(int i)
From test_namespace::test_print(double i)

From ::CTest::test_print
From ::CTest::test_print(int i)
From ::CTest::test_print(double i)
From ::test_print()
From ::test_print(int i)
From ::test_print(double i)

*/

/*
Disassembly:
    refer name_mangling.disassembly
*/

/*
Objdump:
    refer name_mangling.symbols
*/

/*
Notes:
    Compiler will generate names for methods by appending:  (for both static and dynamic polymorphism)
        1. namepspace name
        2. class name
        3. parameter types
    Compiler will generate names for functions by: (static polymorphism)
        1. class name
        2. parameter types
    Since compiler does name mangaling, while linking, linker can call link to the relevant function/member

test_namespace::CTest::test_print                   _ZN14test_namespace5CTest10test_printEv
test_namespace::CTest::test_print(int i)            _ZN14test_namespace5CTest10test_printEi
test_namespace::CTest::test_print(double i)         _ZN14test_namespace5CTest10test_printEd

test_namespace::test_print()                        _ZN14test_namespace10test_printEv
test_namespace::test_print(int i)                   _ZN14test_namespace10test_printEi
test_namespace::test_print(double i)                _ZN14test_namespace10test_printEd

::CTest::test_print                                 _ZN5CTest10test_printEv
::CTest::test_print(int i)                          _ZN5CTest10test_printEi
::CTest::test_print(double i)                       _ZN5CTest10test_printEd                     

::test_print()                                      _Z10test_printv
::test_print(int i)                                 _Z10test_printi
::test_print(double i)                              _Z10test_printd
*/

