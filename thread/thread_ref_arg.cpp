#include <iostream>
#include <thread>
// TO DO
// Passing pointer
// Pass by ref - using std::ref
// Pass by ref - const &
// rvalue as argument

void thread_function(int const & x)
{
	int & y = const_cast<int &>(x);
	y++;
	std::cout << "x: " << x << " y: " << y << std::endl;
}

int main()
{
	int x = 10;
	std::cout << "x: " << x << std::endl;
	std::thread th(thread_function, x);
	th.join();
	std::cout << "x: " << x << std::endl;
}

/*
Output:

x: 10
x: 11 y: 11
x: 10
*/