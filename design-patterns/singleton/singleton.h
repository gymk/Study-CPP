#ifndef __DESIGN_PATTERN_SINGLETON_H__
    #define __DESIGN_PATTERN_SINGLETON_H__

#include <mutex>

// On first use
// Assumes it is single threaded - so no guard again creating instance
// if concurrent (multi-threaded), better guard against instantiation
template <typename T>
class CSingleton
{
public:
    static CSingleton* getInstance(void)
    {
        static CSingleton<T> * _instance = nullptr;
        
        if(nullptr == _instance)
            _instance = new CSingleton();

        return _instance;
    }

    std::mutex & GetMuteX(void)
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
    std::mutex  _mutex;
};

#endif /* !__DESIGN_PATTERN_SINGLETON_H__ */