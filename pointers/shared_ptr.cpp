#include <iostream>
#include <memory>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>

#define MAX_THREADS         10

class CThreadGuard
{
public:
    CThreadGuard(std::thread & th):_thread(th)
    {
    }
    ~CThreadGuard()
    {
        if(_thread.joinable())
        {
            _thread.join();
        }
    }
private:
    std::thread & _thread;
};

typedef struct tagTestStruct
{
    tagTestStruct(int val):_val(val)
    {
        std::cout << "TEST_STRUCT Constructor invoked\n\n";
    }
    ~tagTestStruct()
    {
        std::cout << "TEST_STRUCT Destructor invoked\n\n";
    }

    int _val;
} TEST_STRUCT;

void SharePtr_Test1(void)   // Passing shared_ptr to a thread as a argument
{
    typedef std::unique_ptr<CThreadGuard>   LC_TH_TR;
    
    std::vector<LC_TH_TR>           th_list;
    std::shared_ptr<TEST_STRUCT>    pTestStruct = std::make_shared<TEST_STRUCT>(10);
    auto f = [pTestStruct]()
             {
                 std::cout << "Current Val: " << pTestStruct.get()->_val++ << std::endl;
                 std::cout << "RefCount: " << pTestStruct.use_count() << std::endl;
             };

    for(int i = 0; i < 1/*MAX_THREADS*/; i++)
    {
        std::thread th(f);
        LC_TH_TR lc(new CThreadGuard(th));
        th_list.push_back(std::move(lc));   // unique pointer do not have copy constructor, so we need to move
    }
}

void WeakPtr_Test1(void)   // Passing shared_ptr to a thread as a argument
{
    typedef std::unique_ptr<CThreadGuard>   LC_TH_TR;
    
    std::mutex mut;
    std::vector<LC_TH_TR>           th_list;
    std::shared_ptr<TEST_STRUCT>    pTestStruct = std::make_shared<TEST_STRUCT>(10);
    std::weak_ptr<TEST_STRUCT>      weakPtr(pTestStruct);
    auto f = [&mut, weakPtr]()
             {
                 //std::cout << weakPtr.expired() << std::endl;
                 if(auto obj = weakPtr.lock()) {
                    std::lock_guard<std::mutex> t(mut);
                    
                    std::cout << "Current Val: " << ++obj.get()->_val << std::endl;
                    std::cout << "RefCount: " << obj.use_count() << std::endl;
                 } else {
                     std::cout << "No valid shared_ptr\n";
                 }
             };

    for(int i = 0; i < MAX_THREADS; i++)
    {
        #if 0   // Threads are not getting executed
        //CThreadGuard cth(std::thread(f));
        #endif
        
        #if 0
        std::thread th(f);
        CThreadGuard cth(th);
        #endif
        
        #if 1   // crash happens
        std::thread th(f);
        th.detach();
        LC_TH_TR lc(new CThreadGuard(th));
        //th_list.push_back(std::move(lc));   // unique pointer do not have copy constructor, so we need to move
        #endif

        std::cout << "i: " << i << std::endl;
    }

    th_list.clear();
}


int main()
{
    //SharePtr_Test1(); gives crash - yet to find the cause
    WeakPtr_Test1();
}

/*
Output:

TEST_STRUCT Constructor invoked

i: 0
i: 1
Current Val: 11
RefCount: i: 2
2
Current Val: 12
RefCount: 3
Current Val: 13
RefCount: 2
i: 3
Current Val: 14
RefCount: 2
i: 4
Current Val: 15
RefCount: 2
i: Current Val: 16
RefCount: 52

i: 6
Current Val: 17
RefCount: 2
i: 7
Current Val: 18
RefCount: 3
i: 8
i: 9
Current Val: 19
RefCount: 2

*/

/*
Notes:
    TODO
        *) Why no destructor print?
        *) Why other '#if 0' cases not working???
 */