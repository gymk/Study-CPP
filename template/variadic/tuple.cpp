/* https://eli.thegreenplace.net/2014/variadic-templates-in-c/ */

/* g++ tuple.cpp -std=c++11 */

#include <iostream>
#include <string>

const std::string msg()
{
    return "";
}

int main()
{
    std::cout << msg << std::endl;
}
