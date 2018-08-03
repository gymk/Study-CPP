#include <iostream>

template<class T>
inline T max(T a, T b)
{
    return a > b ? a : b;
}

int main(int argc, char * argv[])
{
    std::cout << "max(3, 4) " << max(3, 4) << "\n";
    std::cout << "max(3.0, 4) " << max<double>(3, 4.0) << "\n";
    return 0;
}
