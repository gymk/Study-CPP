/*
g++ singleton_concurrent.cpp -std=c++11 -lpthread

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
#include <mutex>
#include "singleton_concurrent_on_first_use.h"

#define MAX_TEST_THREADS    10

void SingletonTest_ThreadFunc(int id)
{
    //std::cout << "Entering " << __FUNCTION__ << ' ' << id << std::endl;
    CSingleton<int> * pIntSingleton = CSingleton<int>::getInstance();

    {
        std::lock_guard<std::mutex> lc(pIntSingleton->GetMutex());
        std::cout << "Entering thread " << id << std::endl;
    }
    {
        std::lock_guard<std::mutex> lc(pIntSingleton->GetMutex());
        std::cout << "Leaving thread " << id << std::endl;
    }
}

int main()
{
    int count = 0;
    std::thread th_list[MAX_TEST_THREADS];

    for(auto & th : th_list)
        th = std::thread(SingletonTest_ThreadFunc, ++count);

    for(auto & th : th_list)
        th.join();
}

/*
Output:

Creating instance
 Singleton constructor invoked
Entering thread 1
Leaving thread 1
Entering thread 2
Leaving thread 2
Entering thread 7
Leaving thread 7
Entering thread 5
Leaving thread 5
Entering thread 8
Leaving thread 8
Entering thread 3
Leaving thread 3
Entering thread 6
Leaving thread 6
Entering thread 4
Leaving thread 4
Entering thread 9
Leaving thread 9
Entering thread 10
Leaving thread 10

*/