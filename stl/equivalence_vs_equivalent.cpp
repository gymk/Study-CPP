/* Bo Qian */

/*
g++ equivalence_vs_equivalent.cpp -std=c++11

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
#include <set>
#include <algorithm>

// Functor
class LessThanComparator
{
public:
    bool operator()(int x, int y) const
    {
        // compare last numeric digit of the given number
        // radix sort
        return(x%10) < (y%10);
    }
};

using Myset = std::set<int, LessThanComparator>;

void print_set(Myset & s)
{
    std::cout << "Count of s: ";
    for(auto & i : s)
        std::cout << i << ' ';
    std::cout << std::endl;
}

void test_equivalent(Myset & s)
{
    // using find alogithm search 
    // Algorithm find searches for equality: if(x == y)
    auto it1 = std::find(s.begin(), s.end(), 36);   // Search '36' using algorithm find
    if(it1 == s.end())
        std::cout << "36 not found\n";
    else 
        std::cout << "Found " << *it1 << std::endl;
}

void test_equivalence(Myset & s)
{
    // using set's find member function
    // Set's find() function searches for equivalence: if( !(x<y) && !(y < x) )
    auto itr2 = s.find(36);
    if(itr2 == s.end())
        std::cout << "36 not found\n";
    else 
        std::cout << "Found " << *itr2 << std::endl;
}

int main()
{
    // Ordered set - ordered using LessThan
    Myset s = { 22, 45, 26, 78, 29 };

    print_set(s);
    test_equivalent(s);
    test_equivalence(s);

    s.clear();
    for(auto i : { 21, 23, 26, 27 })
        s.emplace(i);
    print_set(s);
    test_equivalent(s);
    test_equivalence(s);

    int x1 = 1;  // An Instance
    int & x2 = x1;   // A Reference

    if(&x1 == &x2)  // Identify
        std::cout << "x1 and x2 refers to the same object" << std::endl;

    if(x1 == x2)    // Equality
        std::cout << "x1 and x2 are Equal" << std::endl;

    s.clear();
    for(int i = 0; i < 100; i++) {
        int x = rand() % 100;
        std::cout << x << ' ';
        s.emplace(rand() % 100);
    }
    std::cout << std::endl;
    print_set(s);
    test_equivalent(s);
    test_equivalence(s);

    std::vector<int> v{0, 0, 0, 0};
    std::cout << "Default: " << std::binary_search(v.begin(), v.end(), 0) << std::endl;
    std::cout << "std::less: " << std::binary_search(v.begin(), v.end(), 0, std::less<int>()) << std::endl;
    std::cout << "std::greater: " << std::binary_search(v.begin(), v.end(), 0, std::greater<int>()) << std::endl;
    std::cout << "std::less_equal: " << std::binary_search(v.begin(), v.end(), 0, std::less_equal<int>()) << std::endl;
    std::cout << "std::greathre_equal: " << std::binary_search(v.begin(), v.end(), 0, std::greater_equal<int>()) << std::endl;
}

/*
Output:

Count of s: 22 45 26 78 29 
36 not found
Found 26
Count of s: 21 23 26 27 
36 not found
Found 26
x1 and x2 refers to the same object
x1 and x2 are Equal
83 77 93 86 49 62 90 63 40 72 11 67 82 62 67 29 22 69 93 11 29 21 84 98 15 13 91 56 62 96 5 84 36 46 13 24 82 14 34 43 87 76 88 3 54 32 76 39 26 94 95 34 67 97 17 52 1 86 65 44 40 31 97 81 9 67 97 86 6 19 28 32 3 70 8 40 96 18 46 21 79 64 41 93 34 24 87 43 27 59 32 37 75 74 58 29 35 18 43 28 
Count of s: 30 21 92 23 24 15 86 27 68 59 
36 not found
Found 86

*/

/*
Notes:
    *) If a function is using operator< or its like, it is checking equivalence
        - Typically data required to be sorted
            - Ordered Associative containers
    *) If a function is using operator== or its like, it is checking for equality
        - Typically data is not required to be sorted
            - Unordered Associative containers

    Algorithms that use equivalence
        binary_search
        inclues
        lower_bound
        upper_bound
    Alogrithms that use equality
        search
        find_end
        find_first_of
        adjacent_search
*/

/*
Links:
    *) https://github.com/bashrc-real/Codearchive/blob/master/cpp/Strict_weak_ordering_and_stl.md
    *) TO DO - http://www.drdobbs.com/identity-and-equality-syntax-and-semanti/184401714
    *) TO DO - http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2015/n4367.html
        weak ordering
        partial ordering
        total ordering

        enum class partial_ordering { less, unorderd, greater };
        enum class weak_ordering { less, equivalent, greater };
        enum clas total_ordering { less, equal, greater };
    *) TO DO http://sidd-reddy.blogspot.com/2011/01/i-was-going-over-c-stl-when-i-noticed.html
        strict
            refers to fucntion f being of the form < as opposed to <=
        weak
            refers to an order in total. i.e., for any two elements a, b either f(a,b)
            or f(b.a) is true.
        strickt-weak-ordering
            binary predicate
                (!(a<b) && !(b<a))
                a<b => !(b<a)

    *) http://fusharblog.com/3-ways-to-define-comparison-functions-in-cpp/
*/

/*
    int x1 = 1;     // An Instance
    int & x2 = x1;  // A Reference

    if(&x1 == &x2)  // Identify
        std::cout << "x1 and x2 are Identical" << std::endl;

    if(x1 == x2)    // Equality
        std::cout << "x1 and x2 are Equal" << std::endl;
*/