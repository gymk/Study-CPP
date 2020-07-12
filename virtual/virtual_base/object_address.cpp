#include <iostream>

class A
{
public:
    virtual void PrintMsg(void) const
    {
        std::cout << this << ' ' << __PRETTY_FUNCTION__ << std::endl;
    }
protected:
    int a;
};

class B : public virtual A
{
public:
    virtual void PrintMsg(void) const
    {
        std::cout << this << ' ' << __PRETTY_FUNCTION__ << std::endl;
    }
protected:
    int b;
};
  
#if 1
int main()
{
    class B * b = new B;

    std::cout << "reinterpret_cast<void*>(b): " << reinterpret_cast<void*>(b) << std::endl;
    b->PrintMsg();

    //class A * a = dynamic_cast<A*>(b);
    class A * a = static_cast<A*>(b);

    std::cout << "reinterpret_cast<void*>(a): " << reinterpret_cast<void*>(a) << std::endl;
    a->PrintMsg();
}
#else
int main()
{
    class A * a = new B;

    std::cout << reinterpret_cast<void*>(a) << std::endl;
    a->PrintMsg();

    //class A * a = dynamic_cast<A*>(b);
    class B * b = static_cast<B*>(a);

    std::cout << reinterpret_cast<void*>(b) << std::endl;
    b->PrintMsg();
}
#endif

/*
Output:

reinterpret_cast<void*>(b): 0xdf2530
0xdf2530 virtual void B::PrintMsg() const
reinterpret_cast<void*>(a): 0xdf2540
0xdf2530 virtual void B::PrintMsg() const
*/