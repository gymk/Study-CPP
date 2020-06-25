#include <iostream>

int main()
{
    int i = 10;

    std::cout << "i = " << i << "\n";
    // Below lambda gives error, because by default values captured by lambda are const
    // so those are immutable, meaning we cant change its value
    //auto f1 = [](i) { i = 20 };
    //std::cout << "i = " << i << "\n";

    auto f2 = [i]()mutable{i = 20;};
    f2();
    std::cout << "i = " << i << "\n";

    auto f3 = [&i]()mutable{i = 30;};
    f3();
    std::cout << "i = " << i << "\n";
}

/*
Output:

i = 10
i = 10  - Since f2 captured argument as 'Pass by Value', i = 20 didn't get reflected
i = 30  - Since f3 captured argument as 'Pass by reference', i = 30 got reflected
*/