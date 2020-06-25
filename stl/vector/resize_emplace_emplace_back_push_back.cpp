/*
g++ resize_emplace_emplace_back_push_back.cpp -std=c++11

g++ -v

Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/5/lto-wrapper
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 5.4.0-6ubuntu1~16.04.10' --with-bugurl=file:///usr/share/doc/gcc-5/README.Bugs --enable-languages=c,ada,c++,java,go,d,fortran,objc,obj-c++ --prefix=/usr --program-suffix=-5 --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --with-sysroot=/ --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --with-system-zlib --disable-browser-plugin --enable-java-awt=gtk --enable-gtk-cairo --with-java-home=/usr/lib/jvm/java-1.5.0-gcj-5-amd64/jre --enable-java-home --with-jvm-root-dir=/usr/lib/jvm/java-1.5.0-gcj-5-amd64 --with-jvm-jar-dir=/usr/lib/jvm-exports/java-1.5.0-gcj-5-amd64 --with-arch-directory=amd64 --with-ecj-jar=/usr/share/java/eclipse-ecj.jar --enable-objc-gc --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.10) 
*/

#define ENABLE_CUSTOM_NEW_DELETE_OVERRIDE

#include <iostream>
#include <vector>
#include "../../utils/timemeasure.h"
#include "../../utils/scopelog.h"
#include "../../utils/custom_alloc.h"

void push_back_check(void)
{ LOG_CALL; MEASURE_FUNC_EXECUTION_TIME;
    std::vector<int> v;

    v.resize(10);
    for(int i = 0; i < 20; i++)
    {
        v.push_back(i);
    }

    for(auto & e : v)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}

void emplace_back_check(void)
{ LOG_CALL; MEASURE_FUNC_EXECUTION_TIME;
    std::vector<int> v;

    v.resize(10);
    for(int i = 0; i < 20; i++)
    {
        v.emplace_back(i);
    }

    for(auto & e : v)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}

void emplace_check(void)
{ LOG_CALL; MEASURE_FUNC_EXECUTION_TIME;
    std::vector<int> v;

    v.resize(10);
    for(int i = 0; i < 20; i++)
    {
        v.emplace(v.begin(), i);
    }

    for(auto & e : v)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}

int main()
{ LOG_CALL; MEASURE_FUNC_EXECUTION_TIME;
    push_back_check();
    emplace_back_check();
    emplace_check();
}

/*
Output:

	Alloc(42,0xf42c20)
[resize_emplace_emplace_back_push_back.cpp:int main():Enter]
	Alloc(42,0xf43070)
	Alloc(42,0xf430b0)
	Alloc(23,0xf430f0)
[resize_emplace_emplace_back_push_back.cpp:void push_back_check():Enter]
	Alloc(42,0xf43110)
	Alloc(23,0xf43150)
	Alloc(40,0xf43170)
	Alloc(80,0xf431a0)
	Dealloc(0xf43170)
	Alloc(160,0xf43200)
	Dealloc(0xf431a0)
0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
	Dealloc(0xf43200)
(resize_emplace_emplace_back_push_back.cpp:void push_back_check() took 73 microseconds)
	Dealloc(0xf43150)
	Dealloc(0xf43110)
[resize_emplace_emplace_back_push_back.cpp:void push_back_check():Exit]
	Dealloc(0xf430f0)
	Dealloc(0xf430b0)
	Alloc(42,0xf430b0)
	Alloc(26,0xf43170)
[resize_emplace_emplace_back_push_back.cpp:void emplace_back_check():Enter]
	Alloc(42,0xf43110)
	Alloc(26,0xf431a0)
	Alloc(40,0xf431d0)
	Alloc(80,0xf43200)
	Dealloc(0xf431d0)
	Alloc(160,0xf43260)
	Dealloc(0xf43200)
0 0 0 0 0 0 0 0 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 
	Dealloc(0xf43260)
(resize_emplace_emplace_back_push_back.cpp:void emplace_back_check() took 47 microseconds)
	Dealloc(0xf431a0)
	Dealloc(0xf43110)
[resize_emplace_emplace_back_push_back.cpp:void emplace_back_check():Exit]
	Dealloc(0xf43170)
	Dealloc(0xf430b0)
	Alloc(42,0xf430b0)
	Alloc(21,0xf430f0)
[resize_emplace_emplace_back_push_back.cpp:void emplace_check():Enter]
	Alloc(42,0xf43110)
	Alloc(21,0xf43150)
	Alloc(40,0xf43170)
	Alloc(80,0xf431d0)
	Dealloc(0xf43170)
	Alloc(160,0xf43230)
	Dealloc(0xf431d0)
19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0 0 0 0 0 0 0 0 0 0 0 
	Dealloc(0xf43230)
(resize_emplace_emplace_back_push_back.cpp:void emplace_check() took 53 microseconds)
	Dealloc(0xf43150)
	Dealloc(0xf43110)
[resize_emplace_emplace_back_push_back.cpp:void emplace_check():Exit]
	Dealloc(0xf430f0)
	Dealloc(0xf430b0)
(resize_emplace_emplace_back_push_back.cpp:int main() took 346 microseconds)
	Dealloc(0xf43070)
[resize_emplace_emplace_back_push_back.cpp:int main():Exit]
	Dealloc(0xf42c20)

*/

/*
Notes:
    *) after resize(), if push_back() invoked, it will append after resized' size only
*/
