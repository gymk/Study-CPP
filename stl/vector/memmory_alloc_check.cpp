/*
g++ memmory_alloc_check.cpp -std=c++11

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
#include <cstdlib>
#include <vector>
#include "../../utils/timemeasure.h"
#include "../../utils/scopelog.h"
#include "../../utils/custom_alloc.h"


int main()
{ LOG_CALL; MESAURE_FUNC_EXECUTION_TIME;
    std::vector<int> v;

    for(int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }
}

/*
Output:

A	Alloc(24,0x88ec20)
[memmory_alloc_check.cpp:int main():Enter]
	Alloc(24,0x88f050)
	Alloc(4,0x88f070)
	Alloc(8,0x88f090)
	Dealloc(0x88f070)
	Alloc(16,0x88f070)
	Dealloc(0x88f090)
	Alloc(32,0x88f0b0)
	Dealloc(0x88f070)
	Alloc(64,0x88f0e0)
	Dealloc(0x88f0b0)
	Alloc(128,0x88f130)
	Dealloc(0x88f0e0)
	Alloc(256,0x88f1c0)
	Dealloc(0x88f130)
	Alloc(512,0x88f2d0)
	Dealloc(0x88f1c0)
	Alloc(1024,0x88f4e0)
	Dealloc(0x88f2d0)
	Alloc(2048,0x88f8f0)
	Dealloc(0x88f4e0)
	Alloc(4096,0x890100)
	Dealloc(0x88f8f0)
	Alloc(8192,0x891110)
	Dealloc(0x890100)
	Alloc(16384,0x893120)
	Dealloc(0x891110)
	Alloc(32768,0x897130)
	Dealloc(0x893120)
	Alloc(65536,0x89f140)
	Dealloc(0x897130)
	Alloc(131072,0x8af150)
	Dealloc(0x89f140)
	Alloc(262144,0x7f074d757010)
	Dealloc(0x8af150)
	Alloc(524288,0x7f074d6d6010)
	Dealloc(0x7f074d757010)
	Dealloc(0x7f074d6d6010)
(memmory_alloc_check.cpp:int main() took 5473 microseconds)
	Dealloc(0x88f050)
[memmory_alloc_check.cpp:int main():Exit]
	Dealloc(0x88ec20)

*/

/*
Notes:
    *) even-though push_back() for each i, memory is allocated in multiples of 2
*/