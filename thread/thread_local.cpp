#include <iostream>
#include <thread>
#include <memory>

#define MAX_THREADS		10

using namespace std;

// Thread thread local variables
// that will be unique to each thread
thread_local int TLS_id;
thread_local int TLS_1;
thread_local int TLS_2;

typedef struct tagThreadParams
{
	int id;
	int a;
	int b;
} TH_PARAM;

void IncTLS1(void)
{
	++TLS_1;
}

void IncTLS2(void)
{
	++TLS_2;
}

// Based on calling thread TLS_id, TLS_1 and TLS2 will have its corresponding values
// TO VERIFY : What happens if I call this from main()????
// TO DO: No protection over accessing global shared resource cout
// Need to have mutual access to avoid garbled output.
void PrintTLSInfo(const char * pDebugStr)
{
	// How to get thread id??
	//cout << pDebugStr << this_thread::get_id() << ' ' << TLS_1 << ' ' << TLS_2 << endl;
	cout << pDebugStr << TLS_id << ' ' << TLS_1 << ' ' << TLS_2 << endl;
}

/*
You can argue that since unique memory we have why do we need
thread local again.
This code is for study/checking thread local behaviour
so I am using it, otherwise since we have unique memory,
it is best to live with that without thread local.
*/
// Since it is a unique pointer, we need to get arugment
// as pointer to const with reference
// TO UNDERSTAND: Why reference? why const? what is behind this logic?
void Thread(unique_ptr<TH_PARAM> const & pParam)
{
	PrintTLSInfo("Uninitialized : ");

	TLS_id = pParam->id;
	TLS_1 = pParam->a;
	TLS_2 = pParam->b;
	
	PrintTLSInfo("Initialized : ");

	for(int i = 0; i < 10000; i++)
	{
		IncTLS1();
		IncTLS2();
	}
	
	PrintTLSInfo("Incremeneted : ");
}

int main()
{
	thread	astThreads[MAX_THREADS];
	TH_PARAM	th_param;

	srand(0);
	for(int i = 0; i < MAX_THREADS; i++)
	{
		/*
		Thread IDs are 64-bit integer values, hard to track/understand
		So, I am assigning my id for easy verification of execution
		*/
		th_param.id = i+1;
		th_param.a = rand() % 256;
		th_param.b = rand() % 256;

		// Since more than one thread is created, passing
		// same local struct to each thread will result in
		// corrupted data to threads
		// So creating a heap struct over unique_ptr (to ensure it is release when thread get terminated automatically)
		// and passing it to thread
		unique_ptr<TH_PARAM> param(new TH_PARAM);
		*param = th_param;

		// Since it is unique_ptr, no copy constructor
		// so we need to std::move
		astThreads[i] = thread(Thread, std::move(param));
	}

	// Join to all threads, otherwise program may terminate abnormally
	for(int i = 0; i < MAX_THREADS; i++)
	{
		astThreads[i].join();
	}
}
