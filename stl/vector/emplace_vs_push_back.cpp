/*
g++ emplace_vs_push_back.cpp -std=c++11

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
#include <cstdlib>

typedef struct test
{
    int _i;

    test(int i=-1):_i{i}
    {
        std::cout << "Constructor(" << i << ',' << this << ")\n";
    }
    ~test()
    {
        std::cout << "Destructor(" << _i << ',' << this << ")\n";
    }

    // copy constructor
    test(const test & rhs)
    {
        std::cout << "CopyConstructor this";
        this->print();
        std::cout << " rhs";
        rhs.print();
        std::cout << std::endl;
        _i = rhs._i;
    }

    // move constructor
    test(const test && rhs)
    {
        std::cout << "MoveConstructor this";
        this->print();
        std::cout << " rhs";
        rhs.print();
        std::cout << std::endl;
        _i = rhs._i;
    }

    // copy assignment constructor
    test& operator= (const test & rhs)
    {
        std::cout << "CopyAssignmentConstructor this";
        print();
        std::cout << " rhs";
        rhs.print();
        std::cout << std::endl;
        _i = rhs._i;
    }

    // move assignment constructor
    test& operator= (const test && rhs)
    {
        std::cout << "MoveAssignmentConstructor this";
        print();
        std::cout << " rhs";
        rhs.print();
        std::cout << std::endl;
        _i = rhs._i;
    }

    void print(void) const
    {
        std::cout << "(" << _i << ',' << this << ")";
    }
} test;


void* operator new(std::size_t t)
{
    void * p = malloc(t);

    std::cout << "Alloc(" << t << ',' << p << ")\n";
    return p;
}

void operator delete(void * p)
{
    std::cout << "Dealloc(" << p << ")\n";
    free(p);
}

void* operator new[](std::size_t t)
{
    void * p = malloc(t);

    std::cout << "Alloc[](" << t << ',' << p << ")\n";
    return p;
}

void operator delete[](void * p)
{
    std::cout << "Dealloc[](" << p << ")\n";
    free(p);
}

void test_struct_test(void)
{
    int val = 1;
    std::cout << "==> Entering test struct test\n";
    std::cout << std::endl;
    std::vector<test> test_list;
    test_list.reserve(10);
    test t { val++ };
    std::cout << std::endl;

    std::cout << "Before push_back\n";
    test_list.push_back(val++);                         // unnecessary temp obj created and deleted
    std::cout << "After push_back\n";
    std::cout << std::endl;

    std::cout << "Before push_back\n";
    test_list.push_back(test(val++));                   // unnecessary temp obj created and deleted
    std::cout << "After push_back\n";
    std::cout << std::endl;

    std::cout << "Before push_back\n";
    test_list.push_back(std::move(test(val++)));        // unnecessary temp obj created and deleted
    std::cout << "After push_back\n";
    std::cout << std::endl;

    std::cout << "Before emplace_back\n";
    test_list.emplace_back(val++);                      // most efficent, only final object required constructor invokation
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    std::cout << "Before emplace_back test(val++)\n";
    test_list.emplace_back(test(val++));                // unnecessary temp object creation and then moved into vector
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    std::cout << "Before emplace_back std::move\n";
    test_list.emplace_back(std::move(test(val++)));    // unnecessary temp object creation and then moved into vector
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    std::cout << "==> Exit test struct test\n";
    std::cout << std::endl;
}

void test_std_string(void)
{
    std::cout << "==> Entering test std::string\n";
    std::vector<std::string> str_list;
    str_list.reserve(10);
    std::string mystring;

    mystring = "Hi";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Bye";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Dear";
    std::cout << "Before push_back\n";
    str_list.push_back(mystring);
    std::cout << "After push_back\n";
    std::cout << std::endl;

    mystring = "Hello";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    mystring = "Seeyou";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;

    mystring = "Anyone";
    std::cout << "Before emplace_back\n";
    str_list.emplace_back(mystring);
    std::cout << "After emplace_back\n";
    std::cout << std::endl;
    std::cout << "==> Exit test std::string\n";
}

int main()
{
    test_struct_test();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    test_std_string();
}
/*
Output:

==> Entering test struct test

Alloc(40,0x1a47030)
Constructor(1,0x7ffec1f15250)

Before push_back
Constructor(2,0x7ffec1f15260)
MoveConstructor this(0,0x1a47030) rhs(2,0x7ffec1f15260)
Destructor(2,0x7ffec1f15260)
After push_back

Before push_back
Constructor(3,0x7ffec1f15270)
MoveConstructor this(0,0x1a47034) rhs(3,0x7ffec1f15270)
Destructor(3,0x7ffec1f15270)
After push_back

Before push_back
Constructor(4,0x7ffec1f15280)
MoveConstructor this(0,0x1a47038) rhs(4,0x7ffec1f15280)
Destructor(4,0x7ffec1f15280)
After push_back

Before emplace_back
Constructor(5,0x1a4703c)
After emplace_back

Before emplace_back test(val++)
Constructor(6,0x7ffec1f15290)
MoveConstructor this(0,0x1a47040) rhs(6,0x7ffec1f15290)
Destructor(6,0x7ffec1f15290)
After emplace_back

Before emplace_back std::move
Constructor(7,0x7ffec1f152a0)
MoveConstructor this(0,0x1a47044) rhs(7,0x7ffec1f152a0)
Destructor(7,0x7ffec1f152a0)
After emplace_back

==> Exit test struct test

Destructor(1,0x7ffec1f15250)
Destructor(2,0x1a47030)
Destructor(3,0x1a47034)
Destructor(4,0x1a47038)
Destructor(5,0x1a4703c)
Destructor(6,0x1a47040)
Destructor(7,0x1a47044)
Dealloc(0x1a47030)



==> Entering test std::string
Alloc(320,0x1a47060)
Before push_back
After push_back

Before push_back
After push_back

Before push_back
After push_back

Before emplace_back
After emplace_back

Before emplace_back
After emplace_back

Before emplace_back
After emplace_back

==> Exit test std::string
Dealloc(0x1a47060)

*/

/*
Links:
    *) https://isocpp.org/blog/2014/11/push-back-and-emplace-back
    *) https://abseil.io/tips/112
*/