#include <iostream>
#include <thread>

class CThreadClass
{
public:
	void operator()()
	{
		for(int i = 0; i < 1000; i++)
			std::cout << "Thread Class function executing...\n";
	}
};

int main()
{
	std::thread th((CThreadClass()));
	std::thread th2;

	for(int i = 0; i < 1000; i++)
		std::cout << "main function executing...\n";

	th.join();

	std::cout << "get_id() for not-created thread: " << th2.get_id() << std::endl;
}
