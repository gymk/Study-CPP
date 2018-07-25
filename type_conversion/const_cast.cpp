#include <iostream>
#include <string>

class CPrintClass
{
public:
	explicit CPrintClass(const char *pStr)
	{
		std::cout << __FUNCTION__ << ": " << pStr << std::endl;
	}
};

int main()
{
	std::string	str {"A1234"};

	std::cout << str << std::endl;

	const char * pConstStr = str.c_str();

	std::cout << pConstStr << std::endl;

	char * modStr = const_cast<char*>(pConstStr);

	std::cout << modStr << std::endl;

	*modStr = 'b';
	std::cout << pConstStr << std::endl;
	std::cout << modStr << std::endl;

	const char * pConstStr2 = modStr;

	CPrintClass a(pConstStr);
	CPrintClass b(pConstStr2);
	CPrintClass c(modStr);
}

/*
Output:

A1234
A1234
A1234
b1234
b1234
CPrintClass: b1234
CPrintClass: b1234
CPrintClass: b1234

*/

/*
Notes:
	*) const_cast removes the const qualifies from the objects for modification
*/
