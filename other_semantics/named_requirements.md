# C++ Named Requirements

Given
  - `T` is a type
  - `m` is one the allocators
  - `p` a `T*`
  - `rv` an rvalue of type `T`
  - `v` an expression of type `T`

## [CopyInsertable](https://en.cppreference.com/w/cpp/named_req/CopyInsertable)

- `T` is `CopyInsertable` into `X` means that the following expression is well-formed

    `std::allocator_traits<A>::construct(m, p, v)`
    `T` is `CopyInsertable` into `X`: The allocator of `X` can placement-new construct an element of `T`, passing a xpression of type `T`

- Allocator invokes

    `m.construct(p, v); // CopyInsertable`

- And the `construct` uses _**placement new**_ to construct the object from the pre-allocated memory

    `::new ((void*)p) T(v); // CopyInsertable`

## [MoveConstructible](https://en.cppreference.com/w/cpp/named_req/MoveInsertable)

- `T` is `MoveInsertable` into `X` means that the following expression is well-formed
  
    `std::allocator_traits<A>::construct(m, p, rv)`
    `T` is `MoveInsertable` into `X`: The allocator of `X` can placement-new construct an element of `T`, passing an rvalue of type `T`

- Allocator invokes

    `m.construct(p, rv); // MoveInsertable`

- And the `construct` uses _**placement new**_ to construct the object from the pre-allocated memory

    `::new ((void*)p) T(rv); // MoveInsertable`

## [EmplaceConstructible](https://en.cppreference.com/w/cpp/named_req/EmplaceConstructible)

- `T` is `EmplaceConstructible` into X means that the following expression is well-formed

    `std::allocator_traits<A>::construct(m, p, args)` is `EmplaceConstructible` into `X`: The allocator of `X` can placement-new construct an element of `T`, passing zero or more arguments to type `T`

## TO DO

- https://en.cppreference.com/w/cpp/named_req
- [`std::advance`](https://en.cppreference.com/w/cpp/iterator/advance)
  - `LegacyIterator`
    - `LegacyInputIterator`
    - `LegacyRandomAccessIterator`

## Links

- <https://en.cppreference.com/w/cpp/named_req>
- <https://stackoverflow.com/questions/14916005/difference-between-moveinsertable-and-copyinsertable>
