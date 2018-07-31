/*
g++ priority_queue_largest.cpp -std=c++11

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
#include <queue>
#include <vector>

template <typename T>
void print_priority_queue(T & pq)
{
    while(!pq.empty())
    {
        std::cout << pq.top() << ' ';
        pq.pop();
    }
    std::cout << std::endl;
}

int main()
{
    // Max Priority Queue
    std::priority_queue<int> max_pq;    // default container std::vector, default comparator std::less

    std::initializer_list<int> list({ 1, 5, 3 ,6,  4, 123, 5 });

    for(auto i : list)
        max_pq.push(i);

    print_priority_queue(max_pq);


    // Min Priority Queue
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_pq;

    for(auto i : list)
        min_pq.push(i);

    print_priority_queue(min_pq);

    // Custom comparator - TO DO

    // custom allocator - TO DO
}

/*
Output:

123 6 5 5 4 3 1 
1 3 4 5 5 6 123 

*/

/*
Notes:
    *) std::priority_queue<T, container_type<T>=std::vector<T>, Compare=std::less<T>>
    *) Expects binary predicate, which follows strict weak ordering
*/