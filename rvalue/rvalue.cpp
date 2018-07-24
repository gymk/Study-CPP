#include <iostream>

class CTest
{
public:
	void PrintMsg(std::string & msg)	// Pass by reference - accepting lvalue std::string
	{
		std::cout << "lvalue_ref: Received msg: " << msg << static_cast<const void*>(msg.c_str()) << std::endl;
	}
	void PrintMsg(std::string && msg)	// Pass by reference - accepting rvalue std::string
	{
		std::cout << "rvalue_ref: Received msg: " << msg << static_cast<const void*>(msg.c_str()) << std::endl;
	}
};

int main()
{
	CTest test;

	test.PrintMsg("quoted_string");
	test.PrintMsg(std::string("wrapped_quoted_string"));

	std::string t = "assigned_string";
	test.PrintMsg(t);
}

/*
Output:

rvalue_ref: Received msg: quoted_string0x7ffe3a2740d0
rvalue_ref: Received msg: wrapped_quoted_string0x161d030
lvalue_ref: Received msg: assigned_string0x7ffe3a2740d0
*/

/*
Notes:
	Looks like it is possible to overload by lvalue, rvalue argument types
*/

/*
TO-DO:
	Do the same test over customer string library and check which constructors are invoked for each of the above case
*/
