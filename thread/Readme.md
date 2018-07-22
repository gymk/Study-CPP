# C++ std::thread

> ## Creating and running a thread

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
