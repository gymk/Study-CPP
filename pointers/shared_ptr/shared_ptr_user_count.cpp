#include <iostream>
#include <thread>
#include <future>
#include <vector>
#include <mutex>

#define MAX_THREADS 10

typedef struct test
{
    int _i;
    test(int i):_i{i}
    {
        std::cout << "constructor " << i << std::endl;
    };
    ~test()
    {
        std::cout << "destructor " << _i << std::endl;
    }
} test;

int main()
{
    int id;
    std::mutex mu;
    std::vector<std::future<int>> th_list;
    
    auto p = std::make_shared<test>(MAX_THREADS);
    std::cout << "initial use-count (before lambda): " << p.use_count() << std::endl;
    auto f1 = [&mu, p](int id){  //if you pass p as reference, then use_count will always be 1, so passing p by value
        std::lock_guard<std::mutex> lc(mu);

        std::cout << "id: " << id << std::endl;
        if(p)
        {
            std::cout << "use-count: " << p.use_count() << std::endl;
            p->_i--;
            std::cout << "i: " << p->_i << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "no valid shared_ptr available" << std::endl;
        }

        return id;
    };
    std::cout << "use-count after lamba: " << p.use_count() << std::endl;

    // Invoking lambda didn't increase use-count
    f1(0);

    for(id = 0; id < MAX_THREADS + 2; id++)
        th_list.push_back(std::async(std::launch::async, f1, id+1));

    for(auto & m : th_list)
    {
        // get return value and then lock mc
        // otherwise deadlock will happen
        id = m.get();
        std::lock_guard<std::mutex> lc(mu);
        std::cout << "id: " << id << " now use-count: " << p.use_count() << std::endl;
    }
}

/*
Output:

constructor 10
initial use-count (before lambda): 1
use-count after lamba: 2
id: 0
use-count: 2
i: 9

id: 1
use-count: 5
i: 8

id: 2
use-count: 6
i: 7

id: 3
use-count: 6
i: 6

id: 4
use-count: 7
i: 5

id: 5
use-count: 8
i: 4

id: 6
use-count: 9
i: 3

id: 7
use-count: 10
i: 2

id: 8
use-count: 11
i: 1

id: 9
use-count: 12
i: 0

id: 10
use-count: 13
i: -1

id: 12
use-count: 13
i: -2

id: 11
use-count: 13
i: -3

id: 1 now use-count: 13
id: 2 now use-count: 12
id: 3 now use-count: 11
id: 4 now use-count: 10
id: 5 now use-count: 9
id: 6 now use-count: 8
id: 7 now use-count: 7
id: 8 now use-count: 6
id: 9 now use-count: 5
id: 10 now use-count: 4
id: 11 now use-count: 3
id: 12 now use-count: 2
destructor -3

*/