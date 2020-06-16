#include <iostream>
#include <memory>

class Foo {
    int x;
  public:
    explicit Foo(int x) : x{x} {}
    int getX(void) { return x; }

  ~Foo() { std::cout << "~Foo for x=" << x << std::endl; }
};

int main() {
  std::unique_ptr<Foo> p = std::make_unique<Foo>(10);

  std::cout << "p=" << p->getX() << std::endl;

  p = std::make_unique<Foo>(20);
  std::cout << "p=" << p->getX() << std::endl;

  p = std::unique_ptr<Foo>(new Foo(30));
  std::cout << "p=" << p->getX() << std::endl;

  return 0;
}

/*
Output:

p=10
~Foo for x=10
p=20
~Foo for x=20
p=30
~Foo for x=30

*/