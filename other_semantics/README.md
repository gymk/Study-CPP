# Other Semantics

## Before Main

- In any if we want to execute some function before entering into main
  - We can do so by creating a function and assign its return value (can be dummy)
  - to a global variable

## [`std::exit`](std_exit.cpp)

- When std::exit() get invoked
  - local destructor is not getting invoked
  - However local static destructor is getting invoked
  - The destructors for both static and global variables are invoked in the same order it is created
- When main() is returned normally
  - First local variable destructors are get invoked
  - Next local static variable destructors are get invoked
  - Finally in order of its creation, global and static variable destructors are invoked

## [`std::set_terminate`](run_after_main.cpp)

- Post main(), we can execute required function for final clean-up if any

## TO DO

- `std::terminate`
  - std::atexit and std::terminate togetherness???
  - The result of std::terminate in a thread? Does it terminate only the thread of whole program?
- `[[noreturn]]` >= C++11
  - <https://en.cppreference.com/w/cpp/language/attributes/noreturn>
  - <https://stackoverflow.com/questions/10538291/what-is-the-point-of-noreturn>
  - <https://riptutorial.com/cplusplus/example/18670/--noreturn-->
- `[[deprecated]]` and `[[deprecated("reason")]]` >= C++14
  - <https://riptutorial.com/cplusplus/example/18756/--deprecated---and---deprecated--reason---->
- `[[nodiscard]]` >= C++17
  - <https://riptutorial.com/cplusplus/example/19006/--nodiscard-->
- `[[fallthrough]]` >= C++17
  - <https://riptutorial.com/cplusplus/example/18747/--fallthrough-->
- `[[maybe_unused]]`

## Links

- `[std::exit]`
  - <https://en.cppreference.com/w/cpp/utility/program/exit>
- `[std::terminate]`
  - <https://en.cppreference.com/w/cpp/error/terminate>
  - Using `std::terminate`
    - <https://akrzemi1.wordpress.com/2011/10/05/using-stdterminate/>
  - Who call's `std::terminate`?
    - <https://akrzemi1.wordpress.com/2011/09/28/who-calls-stdterminate/>
