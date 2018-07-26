#include <iostream>
#include <cstdlib>

class CMemLeakChecker
{
public:
    // overload global new operator
    friend void* operator new(size_t t)
    {
        void * p = malloc(t);

        if(p)
            ++_count;

        return p;
    }

    // overload global operato delete
    friend void operator delete(void * p)
    {
        std::cout << "delete " << p << std::endl;
        if(p)
            --_count;
        free(p);
    }

    // overload per class delete having size parameter
    friend void operator delete(void * p, size_t t)   // TO DO - When it will get invoked
    {
        std::cout << "delete " << p << " size: " << t << std::endl;
        if(p)
        {
            --_count;
            free(p);
        }
    }

    // overload global operator new[]
    friend void* operator new[](size_t t)
    {
        void * p = nullptr;

        if(t)
        {
            void * p = malloc(t);

            if(p)
                ++_count;
        }

        return p;
    }

    // overload global operato delete[]
    friend void operator delete[](void * p)
    {
        std::cout << "delete[] " << p << std::endl;
        if(p)
        {
            --_count;
            free(p);
        }
    }

    // overload per class deletep[] having size parameter
    friend void operator delete[](void * p, size_t t)   // TO DO - When it will get invoked
    {
        std::cout << "delete[] " << p << " size: " << t << std::endl;
        if(p)
        {
            --_count;
            free(p);
        }
    }

    static void CheckLeak(void)
    {
        if(_count == 0)
            std::cout << "No memory leaks\n";
        else
            std::cout << _count << " allocations yet to be released\n";
    }

private:
    CMemLeakChecker(const CMemLeakChecker &) = delete;  // No Copy constructor
    CMemLeakChecker& operator=(const CMemLeakChecker &) = delete;        // No assignment consturctor

private:
    static int _count;
};

int CMemLeakChecker::_count = 0;

int main()
{
    CMemLeakChecker::CheckLeak();

    int * pI = new int;
    CMemLeakChecker::CheckLeak();
    delete pI;
    CMemLeakChecker::CheckLeak();

    int * pA = new int[10];
    CMemLeakChecker::CheckLeak();
    delete pA;
    CMemLeakChecker::CheckLeak();
}

/*
Notes:
    Another way to overload global new/delete
    In per class delete, additionally delete with size can be overloaded (which is not possible with global delete)
*/

/*
Links:
    https://www.quora.com/Can-we-overload-new-and-delete-operators-by-using-the-friend-function-in-C++
        Sergey Zubkov, C++ programmer reply in this question
    http://www.scs.stanford.edu/~dm/home/papers/c++-new.html
*/