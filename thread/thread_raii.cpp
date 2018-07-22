#include <iostream>
#include <thread>

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
	for(int i = 0; i < 1000; i++)
		std::cout << "thread function executing\n";
}

int main()
{
	std::thread th(thread_function);
	CThreadRAII th_raii(th);
}
