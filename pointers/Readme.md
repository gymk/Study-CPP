
# Memory

In C++, data can be stored in three kinds of places

    1. On stack (local variables)
    2. On heap (new/ delete)
    3. In static section (static variables)

## new and delete

### new

performs following actions in behind

    ```c++
    CTest* pTest = new CTest;
    ```

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

## Smart Pointers

- It is class which wraps a raw pointer, to manage the life time of the raw pointer
- The most fundamental job of smart pointer is to remove the chances of memory leak
- It makes sure that the object is deleted if it is not referenced any more

### Types

- Basically all these pointers are templates

#### std::unique_ptr

- Allows only one owner to the underlying pointer
- use *, -> to deference the underlying pointer (these operators are overloaded in std::unique_ptr)
- This will delete the underlying pointer even when exception occurs

#### std::shared_ptr

- Allows multiple owner to the underlying pointer (Reference counting is maintained)

#### std::weak_ptr

- A special type of shared_ptr which doesn't count the reference

### Guidelines

- Memory Management
  - Avoid `std::xx_ptr(type) obj(new type)`
    - Avoid these type of smart pointer creation
    - It will create `obj` of type `type`, and then it will create `std::shared_ptr` object.
      - Unnecessary of creating two objects
- Use `make_X`
  - Use `std::shared_ptr` only if necessary
    - Only if you are planning to share the pointer
    - Otherwise `std::unique_ptr` is preferred
- Use `make_x` to create smart pointers

## Links

- <http://www.drdobbs.com/cpp/calling-constructors-with-placement-new/232901023>
- <http://www.scs.stanford.edu/~dm/home/papers/c++-new.html>
- <http://jrruethe.github.io/blog/2015/08/23/placement-new/>
- <http://blog.aaronballman.com/2011/08/the-placement-new-operator/>
- <https://www.modernescpp.com/index.php/c-core-guidelines-rules-to-smart-pointers>
- <https://www.internalpointers.com/post/quick-primer-type-traits-modern-cpp#:~:text=What%20is%20a%20type%20trait,or%20the%20transformation%20it%20performs.>
  - A quick primer on type traits in modern C++

## Video Links

- <https://www.youtube.com/watch?v=wUzn0HljjRE&list=PLk6CEY9XxSIAI2K-sxrKzzSyT6UZR5ObP>
