# nothrow.md

## STL

- STL uses `std::allocator` under the hood
  - If unable to allocate memory, it will raise `std::bad_alloc` exception
- There is no way to use `nothrow` to STL containers
  - An example scenario, see Q4 in [q_and_a](../q_and_a/questions/README.md)
- Example custom allocator code
  - Stack/Heap
    - <https://blog.demofox.org/2015/02/25/avoiding-the-performance-hazzards-of-stdfunction/>
