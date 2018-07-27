/*
g++ shared_ptr_reset.cpp -std=c++11 -lpthread
*/

#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <memory>
#include <mutex>

#define MAX_THREAD      10
#define TEST_THRES_VAL  5

typedef struct test
{
    int _i;

    test(int i):_i{i}
    {
        std::cout << "constructor " << i << std::endl;
    }
    ~test()
    {
        std::cout << "destructor " << _i << std::endl;
    }
} test;

int main()
{
    std::vector<std::future<void>> th_list;
    std::mutex th_sync;
    std::shared_ptr<test>   p = std::make_shared<test>(MAX_THREAD);

    auto f1 =[&](int id)
    {
        std::lock_guard<std::mutex> lc(th_sync);

        std::cout << "id: " << id << std::endl;

        if(p) {
            std::cout << "user-count: " << p.use_count() << std::endl;
            --p->_i;
            std::cout << p->_i << std::endl;

            if(p->_i == TEST_THRES_VAL)
                p.reset();
        } else {
            std::cout << "no valid std::shared_ptr found" << std::endl;
        }
        std::cout << std::endl;
    };
    for(int i = 0; i < MAX_THREAD; i++)
        th_list.push_back(std::async(std::launch::async,f1, i+1));

    for(auto & m : th_list)
        m.wait();
}

/*
Output:

id: 1
user-count: 1
9

id: 2
user-count: 1
8

id: 3
user-count: 1
7

id: 5
user-count: 1
6

id: 4
user-count: 1
5

id: 6
no valid std::shared_ptr found

id: 7
no valid std::shared_ptr found

id: 8
no valid std::shared_ptr found

id: 9
no valid std::shared_ptr found

id: 10
no valid std::shared_ptr found

*/