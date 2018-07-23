#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <list>
#include <cstdlib>

// TO DO - Try to use allocator, emplace, comparisons...
// TO DO - if possible, print container type in below functions

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

void StackDefVector(void)
{
    // Note that stack data type and sequence container data type should be same - here it is 'int'
    std::stack<int, std::vector<int> > s;   // Space between >> is need otherwise it assume '>>' operator

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
    std::cout << s.container_type << std::endl;
}

void StackDefList(void)
{
    // Note that stack data type and sequence container data type should be same - here it is 'int'
    std::stack<int, std::list<int> > s;   // Space between >> is need otherwise it assume '>>' operator

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

int main()
{
    StackDefContainer();
    StackDefVector();
    StackDefList();
}