#include <iostream>
#include <mutex>

int main()
{
    std::mutex  mut;

    // Pass by reference
    auto f1 = [&]()
                {
                    std::lock_guard<std::mutex> lc(mut);
                    std::cout << "Passed by refernce\n";
                };
    f1();

    // Pass by value - not possible - no operator()=
    /*
    auto f1 = [=]()
                {
                    std::lock_guard<std::mutex> lc(mut);
                    std::cout << "Passed by refernce\n";
                };
    */
}

/*
Output:
    Passed by reference
*/

/*
Notes:
    *) cannot pass mutex as 'Pass by Value', no copy constructor nor assignment operator
    *) sample applies to all BasicLockable types (mutex, recursivemutex, timed_mutex, recursive_timed_mutex, unique_lock)
*/