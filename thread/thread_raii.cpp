/*
g++ -std=c++11 thread_raii.cpp -lpthread
*/
#include <iostream>
#include <thread>
#include <chrono>

class CThreadRAII
{
public:
	CThreadRAII(std::thread & thread): m_thread(thread)
	{
	}
	~CThreadRAII()
	{
		if(m_thread.joinable())
		{
			//m_thread.join();
			m_thread.detach();
		}
	}
private:
	std::thread &	m_thread;
};

void thread_function(void)
{
	for(int i = 0; i < 10; i++)
		std::cout << "thread function executing\n";
}

int main()
{
	std::thread th(thread_function);
	CThreadRAII th_raii(th);
	std::this_thread::sleep_for(std::chrono::milliseconds(1));
}

/*
Outpout:

thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
thread function executing
*/