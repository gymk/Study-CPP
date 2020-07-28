# `std::stack`

- `std::stack<>` is a container adapter
  - internally it uses sequence container to provide this container adapter
  - we can select which sequence container stack can use
    - `std::deque`
    - `std::list`
    - `std::vector`
  - if none specified, default `std::deque` will be used

**pros:**

  - provides stack functionality - LIFO

**cons:**
  - `std::stack` don't expose any iterators

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    std::cout << st.top();    // prints 3
    st.pop();
    std::cout << st.top();    // prints 2
    st.pop();
    std::cout << st.top();    // prints 1
    st.pop();
    std::cout << st.top();    // crashes application

    return 0;
}
```

## Links

- <https://stackoverflow.com/questions/38136137/does-stack-have-iterators-in-c#:~:text=std%3A%3Astack%20does%20not%20have%20iterators.&text=std%3A%3Astack%20provides%20a,it%20does%20not%20provide%20iteration.>
