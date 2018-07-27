#ifndef __DESIGN_PATTERN_SINGLETON_GLOBAL_STATIC_H__
    #define __DESIGN_PATTERN_SINGLETON_GLOBAL_STATIC_H__

#include <mutex>

template <typename T>
class CSingleton
{
public:
    static CSingleton * getInstance(void)
    {
        static CSingleton<T>    _obj;
        
        return &_obj;
    }

    std::mutex & GetMuteX(void)
    {
        return _mutex;
    }

protected:
    CSingleton()
    {
        std::cout << "Global Static Singleton constructor invoked" << std::endl;
    }
    ~CSingleton()
    {
        std::cout << "Global Static Singleton destructor invoked" << std::endl;
    }

    // disable copy constructor
    CSingleton(const CSingleton&) = delete;
    // disable move constructor
    CSingleton(CSingleton &&) = delete;
    // disable assignment constructor
    CSingleton & operator=(const CSingleton&) = delete;
    // disable copy assignment constructor
    CSingleton & operator=(CSingleton &&) = delete;
    
private:
    std::mutex              _mutex;
};

#endif /* !__DESIGN_PATTERN_SINGLETON_GLOBAL_STATIC_H__ */