/*
g++ weak_ptr -std=c++11 -lpthread

YET TO COMPLETE
*/

#include <iostream>
#include <vector>
#include <thread>
#include <memory>
#include <mutex>

#define MAX_THREAD      10
#define TEST_THRES_VAL  5

typedef struct test
{
    int _i;

    test(int i):_i{i}
    {
        //
    }
} test;

int main()
{
    std::vector<std::thread> th_list;
    std::mutex th_sync;
    std::shared_ptr<test>   p = std::make_shared<test>(20);

    //*pTest.
    
    auto f1 =[&]()
    {
        std::lock_guard<std::mutex> lc(th_sync);
        --p->_i;
        std::cout << p->_i << std::endl;
    };

    std::thread th(f1);

    th.join();
}