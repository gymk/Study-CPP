/*
elemos@elemos-virtual-machine:/mnt/hgfs/Jupyter_Notebooks/github/Study-CPP/lambda$ g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/x86_64-linux-gnu/7/lto-wrapper
OFFLOAD_TARGET_NAMES=nvptx-none
OFFLOAD_TARGET_DEFAULT=1
Target: x86_64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 7.5.0-3ubuntu1~18.04' --with-bugurl=file:///usr/share/doc/gcc-7/README.Bugs --enable-languages=c,ada,c++,go,brig,d,fortran,objc,obj-c++ --prefix=/usr --with-gcc-major-version-only --program-suffix=-7 --program-prefix=x86_64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-bootstrap --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-vtable-verify --enable-libmpx --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib --enable-objc-gc=auto --enable-multiarch --disable-werror --with-arch-32=i686 --with-abi=m64 --with-multilib-list=m32,m64,mx32 --enable-multilib --with-tune=generic --enable-offload-targets=nvptx-none --without-cuda-driver --enable-checking=release --build=x86_64-linux-gnu --host=x86_64-linux-gnu --target=x86_64-linux-gnu
Thread model: posix
gcc version 7.5.0 (Ubuntu 7.5.0-3ubuntu1~18.04) 
*/

/*
Compile Command:
g++ lambda_mutable2.cpp -std=c++11 -lpthread
*/

#include <iostream>
#include <thread>

using namespace std;

void mutable_call_by_value(void)
{
    cout << "mutable_call_by_value:" << endl;
    int count = 0;
    thread thread1(
        [=]() mutable {
            while (count < 10)
                cout << "thread1: " << ++count << "\n";
        });
    cout << "this is main\n";
    thread1.join();
    cout << "i = " << count << "\n\n\n ";
}

void mutable_call_by_ref(void)
{
    cout << "mutable_call_by_ref:" << endl;
    int count = 0;
    thread thread1(
        [&]() mutable {
            while (count < 10)
                cout << "thread1: " << ++count << "\n";
        });
    cout << "this is main\n";
    thread1.join();
    cout << "i = " << count << "\n\n\n ";
}

int main()
{
    mutable_call_by_value();
    mutable_call_by_ref();

    return 0;
}

/*
Output:

mutable_call_by_value:
this is main
thread1: 1
thread1: 2
thread1: 3
thread1: 4
thread1: 5
thread1: 6
thread1: 7
thread1: 8
thread1: 9
thread1: 10
i = 0


 mutable_call_by_ref:
this is main
thread1: 1
thread1: 2
thread1: 3
thread1: 4
thread1: 5
thread1: 6
thread1: 7
thread1: 8
thread1: 9
thread1: 10
i = 10

*/

/*
*/