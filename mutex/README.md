# Mutex support in C++

- [Mutex support in C++](#mutex-support-in-c)
  - [std::mutex](#stdmutex)
  - [std::shared_mutex (from C++17)](#stdshared_mutex-from-c17)
  - [Links](#links)

## std::mutex

- The `mutex` that internal to a class **want to be mutable**[1]
  - Because they are already synchronized (thread-safe)
  - To maintain const guarantees
    - People use this to cast-away const in a member function which is `const`.
    - Eg., `info get_info() const { lock_guard<mutex> hold(m); ... }`

- Refer `const.md` under _Notes_ section to know more on `bitwise const` and `logical const`

## std::shared_mutex (from C++17)

- From [2]
  - Can be used to protect shared data from being simultaneously accessed by multiple threads
    - **_share_**
      - several threads can share ownership of the same mutex
    - **_exclusive_**
      - only one thread can own the mutex
    - Example:
      - `mutable std::shared_mutex mutex_;`
        - `std::unique_lock lock(mutex_);`
        - `std::shared_lock lock(mutex_);`
- From [3]
  - Normal `std::mutex` can guarantee exclusive access to some kind of critical resource and nothing else
  - Shared `std::shared_mutex` extend this feature by allowing two level access
    - **_share_** and **_exclusive_** as follows:
      - **_exclusive_**
        - Exclusive access prevents any other thread from acquiring mutex, just as with the normal mutex
        - It does not mater if the other thread tries to acquire **_share_** or **_exclusive_** access
      - **_share_**
        - Shared access allows multiple access to acquire the mutex, but _all_ of them in shared mode.
        - Exclusive access is not granted until all of the previous shared holders have returned the mutex
          - Typically as long as an exclusive request is waiting, new shared ones are queued to be granted _after_ the exclusive access
    - Example: scenario in a database
      - Read
        - It does not matter if several threads read one and the same data simultaneously
      - Write
        - But modification of the database is critical
        - if some thread reads data while another one is writing it might receive inconsistent data
        - So all reads must have finished before writing is allowed
        - And new reading must wait until writing has finished
        - After writing, further reads can occur simultaneously again

## Links

- [1] <https://channel9.msdn.com/posts/C-and-Beyond-2012-Herb-Sutter-You-dont-know-blank-and-blank>
- [2] [std::shared_mutex](https://en.cppreference.com/w/cpp/thread/shared_mutex)
- [3] <https://stackoverflow.com/questions/46049803/difference-between-shared-mutex-and-mutex-why-do-both-exist-in-c-11>
