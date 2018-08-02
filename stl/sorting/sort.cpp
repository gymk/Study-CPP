#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> sl { "effect", "effective", "effectiveness", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

    std::sort(
        sl.begin(),
        sl.end(),
        [](const std::string & l, const std::string & r){ return l.size() < r.size(); }
        );

    for(auto & m : sl)
        std::cout << m << std::endl;
}

/*
Output:
one
two
six
ten
four
five
nine
three
seven
eight
effect
effective
effectiveness

*/

/*
Links:
    *) TO DO https://www.youtube.com/watch?v=zt7ThwVfap0
*/