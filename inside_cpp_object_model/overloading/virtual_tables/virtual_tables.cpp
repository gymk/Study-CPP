/*
g++ -fdump-class-hierarchy virtual_tables.cpp 
g++ virtual_tables.cpp 

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

objdump -D a.out > virtual_tables.disassembly
objdump -t a.out > virtual_tables.symbols
*/

/*
nm a.out > virtual_tables.nm

nm --v
GNU nm (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
*/

/*
nm a.out | c++filt > virtual_tables.c++filt

c++filt --v
GNU c++filt (GNU Binutils for Ubuntu) 2.26.1
Copyright (C) 2015 Free Software Foundation, Inc.
This program is free software; you may redistribute it under the terms of
the GNU General Public License version 3 or (at your option) any later version.
This program has absolutely no warranty.
*/
#include <iostream>

class NoVirtual
{
public:
    int nv;
};

class A
{
public:
    A() {}
    ~A() {}

    virtual void set_int(int newVal)    {
        a = newVal;
    }
    virtual int get_int(void)    {
        return a;
    }

private:
    int a;
};

class B
{
public:
    B() {}
    ~B() {}

    virtual void set_int(int newVal)    {
        b = newVal;
    }
    virtual int get_int(void)    {
        return b;
    }

private:
    int b;
};

class C : public A
{
public:
    C() {}
    ~C() {}

    virtual void set_int(int newVal)    {
        c = newVal;
    }
    virtual int get_int(void)    {
        return c;
    }

private:
    int c;
};


class D : public B, public A
{
public:
    D() {}
    ~D() {}

    virtual void set_int(int newVal)    {
        d = newVal;
    }
    virtual int get_int(void)    {
        return d;
    }

private:
    int d;
};

class E : public A, public B
{
public:
    E() {}
    ~E() {}

    virtual void set_int(int newVal)    {
        e = newVal;
    }
    virtual int get_int(void)    {
        return e;
    }

private:
    int e;
};

int main()
{
    NoVirtual * nv = new NoVirtual;
    delete nv;
    A * a = new A;
    delete a;
    B * b = new B;
    delete b;
    C * c = new C;
    delete c;
    D * d = new D;
    delete d;
    E * e = new E;
    delete e;
}

/*
Links:
    *) TO DO http://www.alexonlinux.com/how-inheritance-encapsulation-and-polymorphism-work-in-cpp
*/