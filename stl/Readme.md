# Standard Template Library

## C++ Objects, Containers and Maps

- _Objects_: a way to make parts of the program more self-contained, tying together data and behaviour. Objects can be related to other objects.
- _Containers_: ways of clumping together variables of the same type so that sorting, searching, etc., becomes easy
- _Maps_: ways of setting up a mapping between 2 set of values

- Containers are datatypes (actually templates) from STL which contain data
- Adaptors are datatypes (actually templates) from STL that adapt a container to provide specific interface. For example, stcak provides stack interface on top of the chosen container.

## Container

A container is an object which is used to store other objects and taking care of management of the memory used by the objects it contains.

Three types of containers supported by STL

1. Sequence Container
2. Associate Container
3. Container Adaptor

## Sequence Container

- vector
- deque
- array
- list
- forward_list

A sequence container is a container that stores objects of the same type in a linear arrangement.

Sequence containers are usually implemented as arrays or linked-lists.

## Associative Container

- Ordered
  - set
  - multiset
  - map
  - multimap
- Unordered
  - unordered_set
  - unordered_multiset
  - unordered_map
  - unordered_multimap

Ordered Associative containers are usually implemented as 
binary trees
Unordered Associate Containers are usually implemented as hash tables

## Container Adaptor

Container adaptor are interfaces created by limiting the underlying container functionality, to provide a set of functionality

- stack
  - is a container adaptor providing LIFO (Last-In-First-Out) functionality over the chosen container
    - Eg., std::stack<int, std::deque\<int\> stack;
      - A stack of int using deque (the chosen container in this example) as the underlying container.
      - deque container functionality is limited by stack interface
      - only back(), push_back() and pop_back() are supported.
    - Eg., std::queue
- queue
  - is a container adaptor providing FIFO (First-In-First-Out) functionality over the chosen container
    - Eg., std::queue<int, std::list\<int\> queue;
      - A queue of int using list (the chosen container in this example) as the underlying container.
      - list container functionality is limited to queue interface
      - only back(), front(), push_back(), pop_front() are supported.
      - Even though list has so many functions, queue interface limits its functionality to above functions.
- priority queue
  - is a container adaptor providing priority based (largest or smallest) queuing of elements
    - Eg., std::priority_queue<int, std::vector\<int\> largest;
      - A priority queue providing largest element as first in queue
    - Eg., std::priority_queue<int, std::vector\<int\>, std::greater\<int\> smallest
      - A priority queue providing smallest element as first in queue

----

## References

- <http://www-h.eng.cam.ac.uk/help/tpl/languages/C++/1BComputingOO/>
