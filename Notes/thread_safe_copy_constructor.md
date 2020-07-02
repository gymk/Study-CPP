# Thread-safe Copy Constructor

- From C++11, we can forward one constructor to another
- This is particularly useful when we need to have thread-safe copy/move constructors

```cpp
class A {
private:
  // Private constructor which takes source object as well as its lock_guard
  A(const A & a, std::lock_guard<std::mutex> &): i(a.i), i_squared(a.i_squared) {}
public:
  // Default constructor
  A(int i = 0) { set_i(i); }
  // Copy Constructor
  A(const A & a) : A(a, std::lock_guard<std::mutex>(a.mtx)) {}

  void set_i(int _i) {
    std::lock_guard<std::mutex> lock(mtx);
    i = _i;
    i_squared = i * i;
  }

private:
  std::mutex mtx;
  int i;
  int i_squared;
}

A a2 = a; // Content of a will be copied to a2 with thread-safe
```

## Links

- [1]<https://www.justsoftwaresolutions.co.uk/threading/thread-safe-copy-constructors.html>
- [2]<https://hownot2code.com/2016/06/09/how-to-properly-call-one-constructor-from-another/>
- [3]<https://docs.microsoft.com/en-us/cpp/cpp/delegating-constructors?view=vs-2019>
