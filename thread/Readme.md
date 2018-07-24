# C++ std::thread

[Creating and running a thread](#Creating and running a thread)

[Running a Function as thread](#Running a Function as thread)

 ## Creating and running a thread

>> ### Running a Function as thread
Funtions can be executed as a thread

```
void thread_function(void)
{
	for(int i = 0; i < 1000; i++)
		std::cout << "thead function executing..." << std::endl;

	std::cout << "Exit of thread function" << std::endl;
}

std::thread th(thread_function)
```

>> ### Running a Functor as thread
Functors can be executed as a seperate thread


```
class CFunctor
{
public:
	void operator()()
	{
		for(int i = 0; i < 1000; i++)
			std::cout << "Functor executing...\n";
	}
};

std::thread th((CFunctor()))
```

*Note here that functor is wrapper around paranthesis. Otherwise it will assume th as a function wil arugment having a functor. To avoid mis-interpretation by compiler, functor is wrapped around paranthesis*

>> ### Running a Lamda as thread
Lamba functions can be executed as a seperate thread

```
std::thread th([]{
		for(int i = 0; i < 1000; i++)
			std::cout << std::this_thread::get_id() << " Lamda function executing\n";
		});
```

> ## Thread join(), detach()

Once thread is created, it need to be joined() or detached(), otherwise at the end of thread execution
a) if it is joinable, it will terminate the program, resulting crash
b) if it is detached, it will release the resources acquired by thread


To join a thread
```
th.join()
```

To detach a thread
```
th.detach();
```

*Once detached, you cannot join again. ALso once joined, don't try to join again. Both will result in undefined behaviour*



# Pending Notes

```
C++ std::thread

std::thread vs pthread
	*) pthread_cancel not available in std::thread
	*) pthread provides control over the size of the stack created, but c++ std::thread don't. Linux provides setrlimit(), but it affects all the threads running in the system.
	*) withouth pthread_join(), it will create only resource leak, but in C++, without join(), it will terminate the program
	*) Object lifetime and exception management is easy using RAII over mutex, condition variables and locks.
	*) RAII is the center of design of the C++ thread library
	*) pthread requires predefined thread function signature for its running. std:;thread we can use any callable object such as lambda functions or functor can be used to as a seperate thread.
	*) std::thread cannot return a value like pthread_exit(). You need to use std::future to get return from std::thread

std::thread
	*) std::thread cannot be copied
		std::thread th1(thread_function);
		std::thread th2 = th1;				// KO: won't compile. no copy constructor. only move possible
		std::thread th2 = std::move(th1);	// OK ownership moved to th2, now th1 has no thread associated with it
	*) thread id
		std::this_thread::get_id() to get thread id of current running thread
		th.get_id() to get thread id from the thread instance varaible
	*) no. of threads
		std::thread::hardware_concurrency()
	*) lambda functions
		std::thread th([]{ std::cout << "From lambda function"" << std::endl });
	*) always parameters get 'passed by value'
	*) to 'pass value by reference', we need to pass with std::ref 	==> TO DO: Elaborate more
		std::thread th(thread_function, std::ref(s));
	*) alternative is using std::move, which avoids copying and not sharing memory between the threads.
		std::thread th(thread_function, std::move(s));

std::future
	*) provides a mechanism to obtain result from a std::thread

std::async
	*) Executes the provided function asynchronously (based on specified policy)
	*) returns std::future object, which provides obtaining a return value from a std::thread
		*) std::launch::deferred
			performs lazy evaluation
			Eventhough async thrad is created it will not get spawned until first call to future.wait() invoked.
			Note that unlike std::lauch::async (which runs in seperate thread) it will run on the thread in which wait() is invoked.
		*) std::launch:async
			executes the function as a seperate thread
			result will be stored in the std::future which can be obtained later

multithread programming in C++
	std::promise
	Condition Variables
	Mutex and Locks
		std::recursive_mutex
		std::timed_mutex
		std::unique_lock
		std::defer_lock
		std::try_to_lock
	Class Templates
		duration and time_point, which is used in all time-related interfaces e.g., ::this_thread::sleep_for and std::this_thread_sleep_until
	Atomic types and functions on Atomic types
	Memory fence functions
		for memory ordering between operations
	Variadic templates
		which enable simple means of passing arguments to a thread functions
	Lambda expressions (anonymous closure objects)
		which can be used in place of functions
	rvalue references
		which enable 'perfect forwarding' to a thread functions
	Function objects
		e.g., std::function and std::bind

		

		
Book
	C++ concurrency in action
	
References
	https://indico.cern.ch/event/199138/contributions/378651/attachments/295442/412882/c11-threads-paper.pdf
```