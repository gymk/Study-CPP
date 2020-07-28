# C++ Type Traits

## Usage in iterators

- Functions such as `std::distance` use the information about the iterator to achieve the fastest result in execution
  - For example, the `distance()` function between
    - two bidrectional iterators takes a linear time of execution
    - two random access iterators takes a constant time

    A sample pseudocode without traits usage:
    ```cpp
    template <typename Iter>
    std::size_type distance(Iter first, Iter, second) {
        if(Iter is a random_access_iterator) {
            return second - first;
        }
        std::size_type count = 0;
        for( ; frst != last; ++count, first++ ) {}
        return count;
    }
    ```
    Above code uses runtime checking for distance calculation. To have compile time, we need to use templace specialization. Use `std::is_same` type trait, defined in `<type_traits>`

    A sample pseudocode using traits:
    ```cpp
    #include <iterator>
    #include <type_traits>

    template <typename Iter>
    typename std::iterator_traits<Iter>::difference_type distance(Iter first, Iter last) {
        using category = std::iterator_traits<Iter>::iterator_category;
        if constexpr (std::is_same_v<category, std::random_access_iterator_tag>) {
            return last-first;
        }
        typename std::iterator_traits<Iter>::difference_type count;
        for( ; first != last; ++count, ++first) {}
        return count;
    }
    ```

    `std::is_same_v` is a helper template for the `std::is_same`
    ```cpp
    template <class T, class U>
    inline constexpr bool is_same_v = is_same<T, U>::value;
    ```

## Links

- [A quick primer on type traits in modern C++](https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp#:~:text=What%20is%20a%20type%20trait,or%20the%20transformation%20it%20performs.)
