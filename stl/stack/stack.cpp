#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <cstdlib>

// TO DO - Try to use allocator, emplace, comparisons...

/*

*) std::stack<> is a container adapter
    *) internally it uses sequence container to provide this container adapter
    *) we can select which sequence container stack can use
        *) std::deque
        *) std::list
        *) std::vector
    *) if none specified, default std::deque will be used

pros:
    *) provides stack functionality - LIFO

cons:
    *) std::stack don't expose any iterators

*/


void StackDefContainer(void)
{
    std::stack<int> s;

    if(s.empty())
        std::cout << "Stack is Empty\n";

    std::cout << "Size of stack: " << s.size() << "\n";

    for(int i = 0; i < 10; i++)
        s.push(std::rand() % 256);

    std::cout << "Size of stack: " << s.size() << "\n";

    for(int i = 0; i < 5; i++)
    {
        std::cout << "Pop(ed): " << s.top() << "\n";
        s.pop();
    }

    std::cout << "Size of stack: " << s.size() << "\n";
}

#if 0 // TO DO - Try to change container type and try
void StackDefVector(void)
{
    std::stack<int, Container=std::vector> s;

    if(s.empty())
        std::cout << "Stack is Empty\n";

    std::cout << "Size of stack: " << s.size() << "\n";

    for(int i = 0; i < 10; i++)
        s.push(std::rand() % 256);

    std::cout << "Size of stack: " << s.size() << "\n";

    for(int i = 0; i < 5; i++)
    {
        std::cout << "Pop(ed): " << s.top() << "\n";
        s.pop();
    }

    std::cout << "Size of stack: " << s.size() << "\n";
}
#endif

int main()
{
    StackDefContainer();
}