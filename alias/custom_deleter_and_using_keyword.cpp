#include <iostream>
#include <forward_list>

template <typename T>
using MyCustomerDeleter = void (*)(void *p);
/*
{
    std::cout << "Customer deleter invoked " << std::endl;
};
*/

template <typename T>
class CMemPool
{
public:
    CMemPool(int max):_max{max}
    {
        _array = new T[max];
        if(nullptr != _array)
        {
            _free_list.reserve(max);
            for(int i = 0; i < max; i++)
                _free_list.push_front(&_array[i]);
        }
    }
    ~CMemPool()
    {
        if(nullptr != _array)
            delete [] _array;
    }

    T * GetBuffer(void)
    {
        T * pBuffer = _free_list.pop_front();

        return pBuffer;
    }
    void ReleaseBuffer(T * pBuffer)
    {
        _free_list.push_back(pBuffer);
    }
private:
    int _max;
    T   * _array;
    std::forward_list<T>  _free_list;
};

int main()
{
    //
}