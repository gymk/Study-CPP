#include <iostream>
#include <thread>

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
