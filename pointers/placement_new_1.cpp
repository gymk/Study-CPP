#include <iostream>

class alignas(sizeof(void*))  CTest  // Note that alignas to have aligned memory
{
public:
    CTest():_i{50},_a{'a'}
    {
        std::cout << "default constructor invoked" << std::endl;
    }
    CTest(int i, char a):_i{i},_a{a}
    {
        std::cout << "(i,a) constructor invoked: " << _i << ' ' << _a << std::endl;
    }
    ~CTest()
    {
        std::cout << "default destructor invoked: " << _i << ' ' << _a << std::endl;
        std::cout << std::endl;
    }

private:
    int     _i;
    char    _a;
};

void HexDump(unsigned char * pui8Buff, int size)
{
    for(int i = 0; i < size; i++)
        std::cout << static_cast<int>(pui8Buff[i]) << ' ';
    
    std::cout << std::endl;
}

int main()
{
    /* alignas(sizeof(void*)) */ unsigned char aui8Buffer[sizeof(CTest)];

    std::cout << "aui8Buffer address: " << static_cast<void*>(aui8Buffer) << std::endl;
    std::cout << "aui8Buffer size: " << sizeof(aui8Buffer) << std::endl;
    std::cout << "aui8Buffer alignof: " << alignof(aui8Buffer) << std::endl;
    std::cout << "size of CTest: " << sizeof(CTest) << std::endl;
    std::cout << "size of void*: " << sizeof(void*) << std::endl;

    // using placement new, create CTest object from memory - default constructor
    for(auto & m : aui8Buffer)
        m = 'c';
    HexDump(aui8Buffer, sizeof(aui8Buffer));
    CTest *pTest = new (&aui8Buffer) CTest;
    std::cout << "pTest address: " << static_cast<void*>(aui8Buffer) << std::endl;

    HexDump(aui8Buffer, sizeof(aui8Buffer));

    // manualy invoke destructor
    pTest->~CTest();

    // using placement new, create CTest object from memory - overloaded constructor
    for(auto & m : aui8Buffer)
        m = 'c';
    CTest *pTest2 = new (&aui8Buffer) CTest(60, 'b');
    std::cout << "pTest2: " << static_cast<void*>(aui8Buffer) << std::endl;
    HexDump(aui8Buffer, sizeof(aui8Buffer));
    // manualy invoke destructor
    pTest->~CTest();
}

/*
Output:

aui8Buffer address: 0x7fff52e22060
size of CTest: 8
size of void*: 8
99 99 99 99 99 99 99 99 
default constructor invoked
pTest address: 0x7fff52e22060
50 0 0 0 97 99 99 99 
default destructor invoked: 50 a

(i,a) constructor invoked: 60 b
pTest2: 0x7fff52e22060
60 0 0 0 98 99 99 99 
default destructor invoked: 60 b

*/

/*
Notes:
    *) we need to invoke desctructor manually to release any resource acquired by constructor (which is invoked by 'placement new')
    *) Ensure that the memory you are providing has enough space to accomodate whole struct/class
        invalid: unsigned char aui8Buff[sizeof(CTest)];
        valid: alignas(align size) unsigned char aui8Buff[sizeof(CTest)];
*/