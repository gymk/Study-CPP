#include <iostream>
#include <initializer_list>
#include <cassert>

template <typename T>
class CDynArray
{
public:
    CDynArray():_size{0},_list(nullptr)
    {
        std::cout << "Empty constructor invoked\n";
    }
    CDynArray(size_t size):_size{size}
    {
        std::cout << "int constructor invoked\n";
        _list = new T[size];
    }

    ~CDynArray()
    {
        std::cout << "Desctructor Invoked\n";
        reset();
    }

    // list copy constructor with std::initializer_list (copy-list-initialization)
    CDynArray(const std::initializer_list<T> & list):CDynArray(list.size())
    {
        std::cout << "copy list-initializer invoked, size: " << _size << std::endl;
        int count = 0;
        for (auto & elem : list)
            _list[count++] = elem;
    }
    // list assignment operator
    void operator=(const std::initializer_list<int> & list)
    {
        std::cout << "list-assignment-operator invoked, _size: " << _size << " newsize: " << list.size() << std::endl;
        reset(list.size());
        int count = 0;
        for (auto & elem : list)
            _list[count++] = elem;
    }

    T & operator[](int index)
    {
        assert(index >= 0 && index < _size);
        return _list[index];
    }

    int size(void) const
    {
        return _size;
    }

    const T* begin(void) const  // To support range-based looping on this class
    {
        return _list;
    }

    const T* end(void) const  // To support range-based looping on this class
    {
        return _list + _size;
    }

private:
    //CDynArray(const T&) = delete;   // No Copy constructor
    //void operator=(const T&) = delete;     // No assignment constructor

    void reset(size_t newsize = 0)
    {
        if(newsize != _size)
        {
            if(nullptr != _list)
            {
                delete [] _list;
                _list = nullptr;
            }
            _size = newsize;
            if(_size)
                _list = new T[newsize];
        }
    }

private:
    T * _list;
    size_t _size;
};

int main()
{
    /*
    ###########################################
    # Copy constructor using initializer_list #
    ###########################################
    */
    {   std::cout << "di: ";
        CDynArray<int> di { 1, 2, 3, 4 };

        std::cout << di.size() << std::endl;
        std::cout << "range-loop: ";
        for ( auto & mem : di)  // range-based loop access
        {
            std::cout << mem << ' ';
        }
        std::cout << std::endl;

        std::cout << "index-loop: ";
        for(int i = 0; i < di.size(); i++)  // indexing
        {
            std::cout << di[i] << ' ';
        }
        std::cout << std::endl;
    }


    {
        std::cout << "ds: ";
        CDynArray<std::string> ds { "123", "abc", "ABC" };

        std::cout << ds.size() << std::endl;  // range-based loop access
        std::cout << "range-loop: ";
        for ( auto & mem : ds)
        {
            std::cout << mem << ' ';
        }
        std::cout << std::endl;
        std::cout << "index-loop: ";
        for(int i = 0; i < ds.size(); i++)  // indexing
        {
            std::cout << ds[i] << ' ';
        }
        std::cout << std::endl;
    }


    {
        std::cout << "dz: ";
        CDynArray<int> dz;
        std::cout << dz.size() << std::endl;  // range-based loop access
        std::cout << "range-loop: ";
        for ( auto & mem : dz)
        {
            std::cout << mem << ' ';
        }
        std::cout << std::endl;
        std::cout << "index-loop: ";
        for(int i = 0; i < dz.size(); i++)  // indexing
        {
            std::cout << dz[i] << ' ';
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
    std::cout << std::endl;

    /*
    ##############################################
    # Assignment operator using initializer_list #
    ##############################################
    */
   std::cout << "Checking assignment using initializer list\n\n";
   {
        std::cout << "di: ";
        CDynArray<int> di = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        
        /*
        In below, if list copy constructor is not specified as explicit
        it will create a temp CDynArray using list copy constructor and then it will
        use default copy constructor (which is a shall copy) and delete temporary
        leaving di  having dangling pointer
        
        so if list copy defined, better define list assignment as well
        */
        di = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
        
        std::cout << di.size() << std::endl;
        std::cout << "range-loop: ";
        for ( auto & mem : di)  // range-based loop access
        {
            std::cout << mem << ' ';
        }
        std::cout << std::endl;

        std::cout << "index-loop: ";
        for(int i = 0; i < di.size(); i++)  // indexing
        {
            std::cout << di[i] << ' ';
        }
        std::cout << std::endl;
   }

   std::cout << std::endl;
   std::cout << std::endl;

   /*
   ######################################
   # Creating initializer_list variable #
   ######################################
   */

    {
        std::initializer_list<int> int_list { 100, 200, 300, 400 };
        CDynArray<int>  di;

        di = int_list;
        std::cout << di.size() << std::endl;
        std::cout << "range-loop: ";
        for ( auto & mem : di)  // range-based loop access
        {
            std::cout << mem << ' ';
        }
        std::cout << std::endl;

        std::cout << "index-loop: ";
        for(int i = 0; i < di.size(); i++)  // indexing
        {
            std::cout << di[i] << ' ';
        }
        std::cout << std::endl;
    }
}

/*
Output:
di: int constructor invoked
copy list-initializer invoked, size: 4
4
range-loop: 1 2 3 4 
index-loop: 1 2 3 4 
Desctructor Invoked
ds: int constructor invoked
copy list-initializer invoked, size: 3
3
range-loop: 123 abc ABC 
index-loop: 123 abc ABC 
Desctructor Invoked
dz: Empty constructor invoked
0
range-loop: 
index-loop: 
Desctructor Invoked


Checking assignment using initializer list

di: int constructor invoked
copy list-initializer invoked, size: 10
list-assignment-operator invoked, _size: 10 newsize: 12
12
range-loop: 11 12 13 14 15 16 17 18 19 20 21 22 
index-loop: 11 12 13 14 15 16 17 18 19 20 21 22 
Desctructor Invoked


Empty constructor invoked
list-assignment-operator invoked, _size: 0 newsize: 4
4
range-loop: 100 200 300 400 
index-loop: 100 200 300 400 
Desctructor Invoked
*/

/*
Notes:
    *) if you provide list constructor, it is best to provide list assignment as well to avoid errors
    *) In order to have list-initializer in your class, you need define a constructor which is accepting std::initializer as input.
    *) std::intializer should be const (since input passed will be mostly rvalue) and take it as reference (otherwise unnecessary initializer_list will get copied during constructor invoke)
*/