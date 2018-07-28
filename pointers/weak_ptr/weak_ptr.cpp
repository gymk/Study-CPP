/*
g++ weak_ptr.cpp -std=c++11 -lpthread

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
#include <vector>
#include <thread>
#include <memory>
#include <mutex>
#include <chrono>

#define MAX_TEST_THREADS    20
#define TEST_THRES_VAL      5

typedef struct test
{
    int _i;

    test(int i):_i{i}
    {
        std::cout << "constructor invoked " << i << std::endl;
    }
    ~test()
    {
        std::cout << "destructor invoked " << _i << std::endl;
    }
    void print(void)
    {
        std::cout << "Value: " << _i << std::endl;
    }
} test;

void shared_ptr_thread(std::shared_ptr<test> sharedPtr, std::mutex & mutex, int wait_time)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(wait_time));
    std::lock_guard<std::mutex> lc(mutex);

    std::cout << "shared_ptr_thread: " << std::this_thread::get_id() << std::endl;
    
    std::cout << "use-count: " << sharedPtr.use_count() << std::endl;
    sharedPtr->print();
    sharedPtr->_i--;
}

void weak_ptr_thread(std::weak_ptr<test> weakPtr, std::mutex & mutex, int wait_time)
{
    for(int i = 0; i < wait_time; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::lock_guard<std::mutex> lc(mutex);

    std::cout << "thread: " << std::this_thread::get_id() << std::endl;
    
    auto s = weakPtr.lock();
    if(s)
    {
        std::cout << "use-count: " << s.use_count() << std::endl;
        s->print();
        s->_i--;

#if 0   // reset doesn't help in resetting actual shared pointer
        if(s->_i == TEST_THRES_VAL)
        {
            std::cout << "Resetting shared pinter\n";
            s.reset();
            std::cout << "After reset use-count: " << s.use_count() << std::endl;
        }
#endif
    }
}

int main()
{
    std::cout << "main thread: " << std::this_thread::get_id() << std::endl;
    std::thread th_list[MAX_TEST_THREADS];
    //std::vector<std::thread> th_list;
    std::mutex th_sync;

    {
        std::shared_ptr<test>   p = std::make_shared<test>(10);
        std::weak_ptr<test> w(p);

        std::thread th(shared_ptr_thread, p, std::ref(th_sync), 25);    // use shared_ptr after 25 milli seconds

        for(auto & th : th_list )
            th = std::thread(weak_ptr_thread, w, std::ref(th_sync), 10);   // each thread try to use after 10 millisecond

        th.join();
    }

    for(auto & th: th_list)
        th.join();

}

/*
Output:

main thread: 140216633739072
constructor invoked 10
thread: 140216590341888
use-count: 3
Value: 10
thread: 140216531592960
use-count: 3
Value: 9
thread: 140216498022144
use-count: 3
Value: 8
thread: 140216481236736
use-count: 3
Value: 7
thread: 140216506414848
use-count: 3
Value: 6
thread: 140216456058624
use-count: 3
Value: 5
thread: 140216472844032
use-count: 3
Value: 4
shared_ptr_thread: 140216615520000
use-count: 2
Value: 3
thread: 140216447665920
use-count: 2
Value: 2
destructor invoked 1
thread: 140216556771072
thread: 140216548378368
thread: 140216514807552
thread: 140216581949184
thread: 140216598734592
thread: 140216565163776
thread: 140216607127296
thread: 140216464451328
thread: 140216573556480
thread: 140216489629440
thread: 140216539985664
thread: 140216523200256

*/