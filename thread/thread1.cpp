#include <iostream>
#include <thread>

void thread_function(void)
{
	for(int i = 0; i < 1000; i++)
		std::cout << "thead function executing..." << std::endl;

	std::cout << "Exit of thread function" << std::endl;
}

int main()
{
	std::thread th(thread_function);
	for(int i = 0; i < 1000; i++)
		std::cout << "main function executing..." << std::endl;

	th.join();

	std::cout << "Exit of Main function" << std::endl;
}
