/*
g++ template_and_using_keyword.cpp -std=c++11

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

/* Create a alias to std::vector<T> */
template <typename T>
using MyVector = std::vector<T>;

/* Create a function template which accepts MyVector and prints its values */
template <typename T>
void PrintMyVector(MyVector<T> list)
{
    for(auto & m : list)
        std::cout << m << ' ';
    std::cout << std::endl;
}

int main()
{
    // try with int
    MyVector<int>   int_list { 1, 2, 3, 4};
    PrintMyVector<int>(int_list);

    // try with float
    MyVector<float>   fl_list { 5., 6., 7., .3};
    PrintMyVector<float>(fl_list);

    // try with std::string
    MyVector<std::string>   str_list { "one", "two", "three", "four"};
    PrintMyVector<std::string>(str_list);
}

/*
Output:

1 2 3 4 
5 6 7 0.3 
one two three four
*/