
## Memory
In C++, data can be stored in three kinds of places

    1. On stack (local variables)
    2. On heap (new/ delete)
    3. In static section (static variables)

## new and delete
### new

performs following actions in behind

    CTest* pTest = new CTest;
    - Makes an OS call to allocate a chunk of memory (of size CTest)
    - Call the constructor of CTest
        - Since no arguments passed, it will invoke default constructor CTest()
    - Assign the address to pTest

### delete

Performs following actions in behind

    delete pTest;
    - Invokes CTest's destructor ~CTest()
    - Make an OS call to release the given memory

### Overloading new and delete

    - there are more than one new and delete operator available in C++
        - normal new and delete
            - void * operator new(std::size_t n);
            - void * operator new[](std::size_t n);
            - void operator delete(void * p);
            - void operator delete[](void * p);
            - it is advisable not to use this overload, instead use std::allocator
        - placement new (there is no delete for this available)
            - void * operator new(std::size_t n, void * p);
            - void * operator new[](std::size_t n, void * p);
    - you can overload normal new and delete operators in a file if you want. But be cautious.
    - you can overload normal new and delete with your own arguments
        - void* operator new(std::size n, <your arguments)
            - example
                - void* operator new(std::size n, MEM_TYPE enRequiredMemType);
                - void operator delete(void * p)
                    Note here that there is no mem type for delete. be cautious. you can't delete as you expect, you need to use normal delete.
                    Otherwise std::allocator might be a saviour (TO DO)

#### placement new


    *) Apart from new and delete, C++ provides another overload new operator named 'placement new' which allows to create an object from existing memory, providing facility to invoke that relevant class constructor (In C++ you can't call a constructor, to enable such thing from existing memory placement new can be used)

    *) Since placement new creates object from existing memory, we can't call delete
    *) So we have any resource get released, we have to call that relevant class destructor (In C++, unlike constructor, we are allowed to invoke destructors)



# Links

    - http://www.drdobbs.com/cpp/calling-constructors-with-placement-new/232901023
    - http://www.scs.stanford.edu/~dm/home/papers/c++-new.html
    - http://jrruethe.github.io/blog/2015/08/23/placement-new/
    - http://blog.aaronballman.com/2011/08/the-placement-new-operator/