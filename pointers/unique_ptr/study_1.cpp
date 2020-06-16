#include <iostream>
#include <memory>

class Foo {
    int x;
  public:
    explicit Foo(int x): x{x} {}
    int getX() { return x; }

  ~Foo() { std::cout << "~Foo of x=" << x << std::endl; }
};

int main() {
  
  // Foo * f = new Foo(10);
  // std::cout << f->getX() >> std::endl;

  std::unique_ptr<Foo> p(new Foo(10));
  std::cout << p->getX() << std::endl;

  return 0;
}

/*
Output:

10
~Foo of x=10
*/