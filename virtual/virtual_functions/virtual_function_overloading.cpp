/*
g++ object_address.cpp

*/
#include <iostream>
#include <typeinfo>

class A
{
public:
    virtual ~A()
    {
        std::cout << __PRETTY_FUNCTION__ << " invoked" << std::endl;
    }
    virtual void PrintMsg(void) const
    {
        std::cout << ' ' << this << ' ' << __PRETTY_FUNCTION__ << std::endl;
    }
protected:
    int a;
};

class B : public A
{
public:
    virtual ~B()
    {
        std::cout << __PRETTY_FUNCTION__ << " invoked" << std::endl;
    }
    virtual void PrintMsg(void) const
    {
        std::cout << ' ' << this << ' ' << __PRETTY_FUNCTION__ << std::endl;
    }
protected:
    int b;
};

#if 0
int main()
{
    class B * b = new B;

    std::cout << reinterpret_cast<void*>(b) << std::endl;
    b->PrintMsg();

    //class A * a = dynamic_cast<A*>(b);
    class A * a = static_cast<A*>(b);

    std::cout << reinterpret_cast<void*>(a) << std::endl;
    a->PrintMsg();
}
#else
int main()
{
    //class A * a = new B;
    class A * a = dynamic_cast<A*>(new B);

    std::cout << "A: " << typeid(A).name() << " a: " << typeid(a).name() << ' ' << reinterpret_cast<void*>(a) << std::endl;
    a->PrintMsg();

    //class A * a = dynamic_cast<A*>(b);
    class B * b = static_cast<B*>(a);
    //class B * b = dynamic_cast<B*>(a);

    std::cout << "B: " << typeid(B).name() << " b: " << typeid(b).name() << ' ' << reinterpret_cast<void*>(b) << std::endl;
    b->PrintMsg();

    delete a;
}
#endif