## std::vector<bool>
    *) std::vector<bool> is not a container
    *) It will give proxy container only, so if you want to modify iterator value, you need to use rvalue reference (&&) not a lvalue reference (&)

# TO DO
    - clear vector memory
        swap() 
    - vector<int> bigarray(N);
        memory set to 0
        why?