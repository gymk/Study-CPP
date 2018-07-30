/*
g++ std_equal.cpp -std=c++11

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
#include <vector>

void case1(void)    // Tries to compare with == operator and std::equal
{
    std::vector<int> v1 { 10, 11, 12, 13 };
    std::vector<int> v2 { 10, 11, 12 };

    std::cout << "v1: ";
    for(auto & m : v1)
        std::cout << m << ' ';
    std::cout << std::endl;
    std::cout << "v2: ";
    for(auto & m : v2)
        std::cout << m << ' ';
    std::cout << std::endl;

    std::cout << "(v1 == v2): " << (v1 == v2) << std::endl;
    std::cout << "std::equal(v1.begin(), v1.end(), v2.begin()): " << std::equal(v1.begin(), v1.end(), v2.begin()) << std::endl;
    std::cout << "std::equal(v2.begin(), v2.end(), v1.begin()): " << std::equal(v2.begin(), v2.end(), v1.begin()) << std::endl;
}

void case2(void)    // TO DO: set intersection...
{
    //
}

void case3(void)    // TO DO: std::mismatch
{
    //
}

int main()
{
    case1();
    case2();
}

/*
Output:

v1: 10 11 12 13 
v2: 10 11 12 
(v1 == v2): 0
std::equal(v1.begin(), v1.end(), v2.begin()): 0
std::equal(v2.begin(), v2.end(), v1.begin()): 1
*/

/*
Notes:
    std::vector ==
        checks whether lengh of both vectors are having same length
        if it has same length, will invoke std::equal to check equality
*/

/*
Links:
    *) https://www.daniweb.com/programming/software-development/threads/168611/comparing-vectors
    *) https://stackoverflow.com/questions/5225820/compare-two-vectors-c
*/