#include <iostream>
#include <thread>

// Running a lambda function as a std::thread
void lambda_as_thread(void)
{
	std::thread th([]{
			for(int i = 0; i < 1000; i++)
				std::cout << std::this_thread::get_id() << " Lambda function executing\n";
			});

	for(int i = 0; i < 1000; i++)
		std::cout << std::this_thread::get_id() << " Main function executing\n";

	th.join();
}

// Running a class member function which is non-static as std::thread
void class_member_as_thread(void)
{
	class CTest
	{
	public:
		void PrintTest(void)
		{
			std::cout << "Member function as thread\n";
		}
	};

	CTest test;

	std::thread th(&CTest::PrintTest, &test);	// without & to function, it is not compiling
	th.join();
}

int main()
{
	lambda_as_thread();
	class_member_as_thread();
}
