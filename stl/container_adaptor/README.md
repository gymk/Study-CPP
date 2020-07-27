# STL Container Adapters

- `std::stack`
- `std::queue`
- `std::priority_queue`

All of the above adapters are by default providers its interface using the sequence container `std::deque`.

The underlying sequence container can be changed, provided, it supports `push_back` memeber function

## `std::stack`

```cpp
void push(const T& value);
void push(T && value);
```

## `std::queue`

- TO DO

## Links

- [1] Expert C++ <https://learning.oreilly.com/library/view/expert-c/9781838552657/83d855cc-c7c7-443a-9c6f-8f54a187b7be.xhtml>
  - by Vardan Grigoryan; Shunguang Wu
Published by Packt Publishing, 2020
