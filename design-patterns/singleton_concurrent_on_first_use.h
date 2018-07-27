#ifndef __DESIGN_PATTERN_SINGLETON_H__
    #define __DESIGN_PATTERN_SINGLETON_H__

#include <cassert>
#include <thread>
#include <mutex>

// On first use
// Concurrency support

template <typename T>
class CSingleton
{
public:
    static CSingleton* getInstance(void)
    {
        static std::once_flag flag1;
        static CSingleton<T> * _instance = nullptr;

        std::call_once(flag1, [](){createInstance(_instance);});
        
        if(nullptr == _instance)
            _instance = new CSingleton();

        return _instance;
    }

    std::mutex & GetMutex(void) // for accessing non-const member in derived class
    {
        return _mutex;
    }

protected:
    CSingleton()    // Add any default member initialization if any
    {
        std::cout << " Singleton constructor invoked" << std::endl;
    }
    ~CSingleton()
    {
        std::cout << " Singleton destructor invoked" << std::endl;
    }

    // disable copy constructor
    CSingleton(const CSingleton &) = delete;
    // disable move constructor
    CSingleton(CSingleton &) = delete;
    // disable copy assignment constructor
    CSingleton& operator=(const CSingleton &) = delete;
    // disable move assignment constructor
    CSingleton& operator=(const CSingleton &&) = delete;

private:
    static void createInstance(CSingleton * & instancePtr)
    {
        assert(instancePtr == nullptr);
        std::cout << "Creating instance" << std::endl;
        instancePtr = new CSingleton();
    }

    CSingleton * _instance;
    std::mutex   _mutex;
};

#endif /* !__DESIGN_PATTERN_SINGLETON_H__ */