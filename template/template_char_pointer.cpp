
#include <iostream>


#include "print_auto_type.cpp"

using namespace std;



template<typename T>
auto m_min(T a, T b) -> decltype((a < b) ? a : b)
{
	cout << "Arg1 - " << a << " is of type - " << type_name<decltype(a)>() << endl;
	cout << "Arg2 - " << b << " is of type - " << type_name<decltype(b)>() << endl;

    return a < b ? a : b;
}

template<typename T1, typename T2>
auto m_min2(T1 a, T2 b) -> decltype((a < b) ? a : b)
{
	cout << "Arg1 - " << a << " is of type - " << type_name<decltype(a)>() << endl;
	cout << "Arg2 - " << b << " is of type - " << type_name<decltype(b)>() << endl;

    return a < b ? a : b;
}


int main(int argc, char * argv[])
{
    auto d1 = m_min<int>(1, 2);
    auto d2 = m_min<float>(2.0, 1.0);
	const char * pHello = "Hello";
	const char * pWorld = "World";

	std::cout << std::fixed;

    cout << "m_min<int>(1, 2) " << d1 << endl;
    cout << "m_min<float>(2.1, 1.1) " << d2 << endl;

    cout << "m_min(pHello, pWorld) " << m_min(pHello, pWorld) << endl;
    cout << "m_min(\"Hello\", \"World\") " << m_min("Hello", "World") << endl;
    cout << "m_min<string>(\"Hello\", \"World\") " << m_min<string>("Hello", "World") << endl;
	cout << "m_min(\"World\", \"Hello\") " << m_min<string>("World", "Hello") << endl;


    cout << "m_min2(1, 2) " << m_min2(1, 2)<< endl;
    cout << "m_min2(1.0, 2) " << m_min2(1.0, 2) << endl;
    cout << "m_min2(1, 2.0) " << m_min2(1, 2.0) << endl;

	cout << 1 << " " << 1.0 << endl;


    return 0;
}
