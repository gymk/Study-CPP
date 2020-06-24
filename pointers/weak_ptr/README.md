# std::weak_ptr

It is a smart pointer that holds a non-owning reference (temporary ownership)
 to an object maintained by std::shared_ptr.
To use std::weak_ptr, it must be converted to std::shared_ptr, in order to
reference the object

| Category             | Function     | Description                                                       |   |   |
|----------------------|--------------|-------------------------------------------------------------------|---|---|
| Member Functions     | constructor  | creates a new weak_ptr                                            |   |   |
|                      | destructor   | destroys a weak_ptr                                               |   |   |
|                      | operator=    | assigns the weak_ptr                                              |   |   |
| Modifiers            | reset        | releases the ownership of the managed object                      |   |   |
|                      | swap         | swaps the managed objects                                         |   |   |
| Observers            | use_count    | returns the number of shared_ptr objects that manages the object  |   |   |
|                      | expired      | checks whether the referenced object was already deleted          |   |   |
|                      | lock         | creates a shared_ptr which manages the referenced object          |   |   |
|                      | owner_before | provides owner-based ordering of weak pointers                    |   |   |
| Non-member functions | std::swap    | specializes the std::swap algorithm                               |   |   |

## Modifiers

## Observers

## Links

- <https://en.cppreference.com/w/cpp/memory/weak_ptr>
- <https://www.modernescpp.com/index.php/std-weak-ptr>
