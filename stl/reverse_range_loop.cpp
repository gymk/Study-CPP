/*
TO DO

NOT COMPILING
HOW TO DO - ANALYSE MORE

similarly check for iterators to other primitive types
*/

#include <iostream>
#include <iterator>

// Defining a tempalte to have a reverse range looop
template <typename T>
struct reverse_range
{
    T & _iterable;   // A reference to the iterable

    reverse_range(T & iterable):_iterable{iterable}
    {
        //
    }

    //auto begin() const -> decltype(this->_iterable.rbegin())
    auto begin() const -> decltype(std::rbegin(this->_iterable))
    {
        //return _iterable.rbegin();
        return std::rbegin(_iterable);
    }

    //auto end() const -> decltype(this->_iterable.rend())
    auto end() const -> decltype(std::rend(_iterable))
    {
        //return _iterable.rend();
        return std::rend(_iterable);
    }
};

// Function which accepts iterator and returns a reverse iterator for that iterator (of type struct reverse_range)
template <typename T>
reverse_range<T> reverse_iterate (T & x)
{
    return reverse_range<T> (x);
}


int main()
{
    int a[] { 1, 2, 3, 4, 5 };

    for(auto & m : a)
        std::cout << m << ' ';
    std::cout << std::endl;

    for(auto & m : reverse_iterate(a))
        std::cout << m << ' ';
    std::cout << std::endl;
}

/*
Links:
    *) https://www.codesynthesis.com/~boris/blog/2012/05/16/cxx11-range-based-for-loop
    *) https://stackoverflow.com/questions/8542591/c11-reverse-range-based-for-loop
*/