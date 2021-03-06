# std::unique_ptr

    Object memory is managed by std::unique_ptr
    Ownership of object memory lies within std::unique_ptr
    So ownership can only be moved, can't be copied or assigned

## types

        - Scalar: to hold single object
            - std::unique_ptr<int>
    
        - Array: to hold array of objects
            - std::unique_ptr<int[]>

## creating std::unique_ptr

        *) C++14 and above
            auto p = std::make_unique<type>(constructor to invoke for that type)
            auto p = std::make_unique<type[]>(n)(constructor to invoke for that type)
        *) C++11
            std::unique_ptr<type> variable(new type(constructor to invoke for that type));
        *) < C++11
            not supported

## operations

### copy

        - Not possible
        - std::unique<int> p(q);   // if q also of type std::unique<int> compile error

### assignment

        - Not possible
        - std::unique<int> p = q;   // if q also of type std::unique<int> compile error

### move

        std::unique<int> p = std::move(q);

### obtaining object address

    Dereferencing
        *p
        Once object release() or reset(), you should never try to deference it, because it will have nullptr after release/reset, dereferencing nullptr is undefined (mostly crash)
    p.get()
        will give the address of the object owned by std::unique_ptr
        If it has valid object, it will give the address of the object, otherwise nullptr

### releasing ownership

    - get object address (releasing the ownership but not releasing the memory)
        int * pI = p.release();

### empty

    - to delete the object
        p.reset()
        This will delete the object
    - Once released/reset you should never try to deference p
        *p  // will crash the program, because after release/reset it will have nullptr, so defering nullptr is undefined behaviour, mostly crash