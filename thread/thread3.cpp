#include <iostream>
#include <thread>

int main()
{
	std::thread th([]{
			for(int i = 0; i < 1000; i++)
				std::cout << std::this_thread::get_id() << " Lamda function executing\n";
			});

	for(int i = 0; i < 1000; i++)
		std::cout << std::this_thread::get_id() << " Main funciton executing\n";

	th.join();
}
