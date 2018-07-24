#include <iostream>
#include <vector>

class origin
{
public:
    int o;
};

class extens
{
public:
    int e;
};

class rectangle
{
public:
    int r;
    rectangle(origin o, extens e)
    {
        // do something
        std::cout << "rectable constructor invoked\n";
    }
};

int main()
{
    std::cout << "Member Initialization !!!" << std::endl;
    int x1 = 10; // C-like initialization
    int x2 (10); // Constuctor initialization
    int x3 {10}; // Uniform initialization

    int ar[] = {1, 2, 3, 4};
    std::vector<int> v1 (100);   // Creates a vector having 100 elements
    std::cout << "std::vector<int> v1 (100); ==> size " << v1.size() << std::endl;
    std::vector<int> v2 {100};   // Create a vector having 1 element of value 100
    std::cout << "std::vector<int> v2 {100}; ==> size " << v2.size() << std::endl;

    /*
    #############################
    ### std::initializer_list ###
    #############################
    */

    std::vector<int> v3 = { 1, 2, 3, 4 };   // Creates a vector having 4 elements of value 1, 2, 3, 4 respectively
    std::cout << "std::vector<int> v3 = { 1, 2, 3, 4 }; ==> size " << v3.size() << std::endl;

    std::vector<int> v4 { 1, 2, 3, };   // Creates a vector having 3 elements of value 1, 2, 3 respectively
    std::cout << "std::vector<int> v4 { 1, 2, 3 }; ==> size " << v4.size() << std::endl;

    // most vexing parse
    rectangle r(origin(), extens());    // TO DO - shouldn't compile @#$%^&*()
}
/*
Output:

std::vector<int> v1 (100); ==> size 100
std::vector<int> v2 {100}; ==> size 1
std::vector<int> v3 = { 1, 2, 3, 4 }; ==> size 4
std::vector<int> v4 { 1, 2, 3 }; ==> size 3
*/

/*
Notes:
    *) if it is primitive data types, C-like initialization will be better
    *) If it is class, uniform initialization is better
        eg: 1
            std::vector<v> (100);   // Will create a vector having 100 elements
            std::vector<v> {100};   // Will create a vector having single element of value 100
            Hence where possible brac-initialization is preferred
        eg: 2
            int ar[] = { 1, 2, 3, 4 };  // Creates a array having 1, 2, 3, 4 as values
            std::vector<v> = { 1, 2, 3, 4}; // Creates a vector having 4 elements having values 1, 2, 3, 4 respectively. Note that '=' is optional
                std::vector<v> { 1, 2, 3, 4};
            In this example {} creates std::initializer_list
*/

/*
TO DO:
    *) Add more test/ doc to std::initializer_list
*/

/*
Links:
    https://stackoverflow.com/questions/24953658/what-are-the-differences-between-c-like-constructor-and-uniform-initialization
*/
