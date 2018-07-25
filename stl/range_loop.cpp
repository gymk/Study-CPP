#include <iostream>
#include <vector>

void vector_bool_proxy_iterator(void)
{
    std::vector<bool>   bv = { true, true, true, true };

    // Print current bv content
    for(const auto & m : bv)
        std::cout << m << ' ';
    std::cout << "\n\n";        /* Output 1 1 1 1 */

    // toggle all values in bv
    for(auto && m : bv) // it is a proxy iterator, so use m is a rvalue reference as it is to change bv (m returned by iterator is an rvalue)
        m = !m;
    for(const auto & m : bv)
        std::cout << m << ' ';
    std::cout << "\n\n";        /* Output 1 1 1 1 */
}

void vector_char_not_proxy(void)
{
    std::vector<char> bv = { true, true, true, true };
    
    // Print current bv content
    for(const auto & m : bv)
        std::cout << static_cast<int>(m) << ' ';
    std::cout << "\n\n";        /* Output 1 1 1 1 */

    // toggle all values in bv
    for(auto & m : bv) // it is NOT a proxy iterator, so we can reference m as it is (m returned by iterator is an lvalue)
        m = !m;
    for(const auto & m : bv)
        std::cout << static_cast<int>(m) << ' ';
    std::cout << "\n\n";        /* Output 1 1 1 1 */}

int main()
{
    vector_bool_proxy_iterator();
    vector_char_not_proxy();
}

/*
Output:
1 1 1 1 

0 0 0 0 

1 1 1 1 

0 0 0 0
*/

/*
Notes:
    *) if you are observing element
        for(const auto & elem : container)
    *) if you are modifying element
        for(auto && elem : container)
            This will work for both generic and proxy iterators
*/

/*
Link:
    [What is the correct way of using c++11's range-based for?]
    (https://stackoverflow.com/questions/15927033/what-is-the-correct-way-of-using-c11s-range-based-for)
*/