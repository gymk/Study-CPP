#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
#include <chrono>

int max_threads;

void GetMaxThreads(void)
{
    max_threads = 10; //std::thread::hardware_concurrency();
}

void thread_function_print_id(void)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    std::cout << "Thread: " << std::this_thread::get_id() << " exiting\n";
}

int thread_function_ret_id(int id)
{
    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    return id;
}

void check_std_thread_no_ret_val(void)
{
    std::cout << __FUNCTION__ << std::endl;
    std::vector<std::future<void>> fut_list;

    for(int i = 0; i < max_threads; i++)
    {
        //fut_list.push_back(std::async(thread_function));
        //auto fut = std::async(thread_function_print_id);
        std::future<void> fut = std::async(thread_function_print_id);
        fut_list.push_back(std::move(fut));
    }

    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    std::for_each(
        fut_list.begin(),
        fut_list.end(),
        [](std::future<void> & fut)
        {
            fut.wait();
        }
    );
}

// I see that each thread return value obtained in 1 second interval
// meaning thread is launched only when get() invoked
// since I am getting each thread status in loop, looks like it is giving results like this
// Because std::launch type is not specified, in this case, std::lauch::deferred is assumed
// by g++ compiler
void check_std_thread_ret_val_1(void)
{
    std::cout << __FUNCTION__ << std::endl;
    std::vector<std::future<int>> fut_list;
    
    for(int i = 0; i < max_threads; i++)
    {
        //fut_list.push_back(std::async(thread_function, i+1));
        auto fut = std::async(thread_function_ret_id, i+1);
        fut_list.push_back(std::move(fut));
    }

    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    for(int i = 0; i < max_threads; i++)
    {
        std::cout << "Fuction returned: "<< fut_list[i].get() << std::endl;
    }

}

// In this I get all the thread value immediately
void check_std_thread_ret_val_2(void)
{
    std::cout << __FUNCTION__ << std::endl;

    std::vector<std::future<int>> fut_list;
    
    for(int i = 0; i < max_threads; i++)
    {
        fut_list.push_back(std::async(std::launch::async,thread_function_ret_id, i+1));
    }

    for(int i = 0; i < 1000; i++)
        std::this_thread::sleep_for(std::chrono::milliseconds(1));

    for(int i = 0; i < max_threads; i++)
    {
        std::cout << "Fuction returned: "<< fut_list[i].get() << std::endl;
    }

}

int main()
{
    std::cout << __FUNCTION__ << ' ' << std::this_thread::get_id() << std::endl;
    GetMaxThreads();
    check_std_thread_no_ret_val();
    check_std_thread_ret_val_1();   // sync launch - default
    check_std_thread_ret_val_2();   // async launch
    // pass by ref
    // ret by ref ???
    // rvalue as arg
}

