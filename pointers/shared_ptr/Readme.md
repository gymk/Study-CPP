# std::shared_ptr

    - it uses atomic integers for synchronized reference count increment (in std::shared_ptr (copy) constructor) and decrement (in std:sahred_ptr destructor)
    - if possible moving ownership or referencing is best (which asks why do we need a constly shared_ptr as a first-hand) [refer](http://seanmiddleditch.com/dangers-of-stdshared_ptr/)

## creating
    *) std::shared_ptr<type> p = std::make_shared<type>(constructor to invoke)
    *) auto p = std::make_shared<type>(constructor to invoke)

## accessing object
    *) p->
        can access object members
    *) *p // TO VERIFY
        gives object address

## reset
    *) if pointer is no more needed, it can be reset using p.reset()

## Checking pointer validity
    - when pointers get reset, both object and std::shared_ptr get deleted, std::shared_ptr will have nullptr
        - so checking like below will give undefined behaviour (mostly crash)
            p->
            *p
    - you can whether p is nullptr or not for checking its validity
        if(p) {
            ...
        }

## pass by value

    *) Each time you pass a shared_ptr as 'pass by value' its use_count will increase by 1
    *) NOTE: if you define a lambda having shared_ptr as 'pass by value', while defining itself it will increase the use-count so that whenever lambda invoked it will have valid shared_ptr.

## pass by reference
    *) you can pass shared_ptr as reference, it will not increase use-count

## use-count
    *) when use-count becomes 0, it will release the object and the shared_ptr memory

## Operators
    TO DO

### copy
    TO DO

### assignemnt
    TO DO

## Array in shared_ptr
TO DO