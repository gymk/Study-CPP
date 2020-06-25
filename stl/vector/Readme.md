# std::vector

## std::vector\<bool\>

    *) std::vector<bool> is not a container
    *) It will give proxy container only, so if you want to modify iterator value, you need to use rvalue reference (&&) not a lvalue reference (&)

### push_back

    When you do push_back
    *) A temporary object is created with the input argument
    *) And then temporary object is moved into container

### emplace_back

    When you do emplace_back
    *) new object is created in container itself
    *) copy constructor is invoked over the newly created object with the parameters passed to emplace_back
        - basically it invokes the constructor of the object (deduced from the emplace_back args)
    *) instead of push_back, insertion happens in single step

## TO DO

    - clear vector memory
        swap() 
    - vector<int> bigarray(N);
        memory set to 0
        why?
