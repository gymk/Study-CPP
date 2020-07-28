
/*
Validate paranthesis in a given expression

g++ validate_parenthesis.cpp

./a.out "(a + b) + (((x * y) - (a / b)) / 4)"
*/

#include <iostream>
#include <stack>

int main(int argc, char * argv[]) {
    const char * str = argv[1];
    std::stack<char> st;

    while(*str != '\0') {
        if(*str == '(') {
            st.push(*str);
        } else if (*str == ')') {
            if(st.empty()) {
                st.push(*str);
                break;
            } else {
                st.pop();
            }
        }
        str++;
    }

    std::cout << "Validation: " << std::boolalpha << st.empty() << " " << st.size() << std::endl;

    return 0;
}

