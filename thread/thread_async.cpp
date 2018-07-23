#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>

int thread_function(int id)
{
    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    return id;
}

// I see that each thread return value obtained in 1 second interval
// meaning thread is launched only when get() invoked
// since I am getting each thread status in loop, looks like it is giving results like this
void check_std_thread_ret_val_1(void)
{
    std::cout << __FUNCTION__ << std::endl;
    int max_thread = std::thread::hardware_concurrency();

    std::vector<std::future<int>> fut_list;
    
    for(int i = 0; i < max_thread; i++)
    {
        fut_list.push_back(std::async(thread_function, i+1));
    }

    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    for(int i = 0; i < max_thread; i++)
    {
        std::cout << "Fuction returned: "<< fut_list[i].get() << std::endl;
    }

}

// In this I get all the thread value immediately
void check_std_thread_ret_val_2(void)
{
    std::cout << __FUNCTION__ << std::endl;
    int max_thread = std::thread::hardware_concurrency();

    std::vector<std::future<int>> fut_list;
    
    for(int i = 0; i < max_thread; i++)
    {
        fut_list.push_back(std::async(std::launch::async,thread_function, i+1));
    }

    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    for(int i = 0; i < max_thread; i++)
    {
        std::cout << "Fuction returned: "<< fut_list[i].get() << std::endl;
    }

}

int main()
{
    check_std_thread_ret_val_1();   // sync launch - default
    check_std_thread_ret_val_2();   // async launch
    // pass by ref
    // ret by ref ???
}
