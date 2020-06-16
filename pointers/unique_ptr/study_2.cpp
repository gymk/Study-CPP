#include <iostream>
#include <memory>

class Foo {
    int x;
  public:
    explicit Foo(int x) : x{x} {}
    int getX() { return x; }

  ~Foo() { std::cout << "~Foo of x=" << x << std::endl; }
};

int main() {

  // ###########################
  // Creating Unique Pointers 
  // ###########################
  // Method 1 - Not exception safe
  std::unique_ptr<Foo> p1( new Foo(10));
  // Method 2 - Exception safe
  std::unique_ptr<Foo> p2 = std::make_unique<Foo>(20); // should use std::make_unique (there are reasons - exception safe)
  // Method 3 - Not Exception safe
  Foo * pf = new Foo(30);
  std::unique_ptr<Foo> p3(pf);

  std::cout << p1->getX() << " " << (*p2).getX() << " " << p3.get()->getX() << std::endl;

  // ######
  // Copy
  // ######
  // p1 = p2; Compilation will FAIL; Because you can not copy ownership

  // ######
  // Move
  // ######
  std::unique_ptr<Foo> p4 = std::move(p2); // PASS; Because moving ownership is allowed

  // ###########
  // Operations
  // ###########
  Foo * p = p2.get();
  std::cout << "p=" << std::hex << p << std::dec << std::endl;

  Foo * p5 = p4.release(); // Since owndership is released, we have to manually delete this object to avoid memory leak
  std::cout << "p5=" << std::hex << p5 << std::dec << std::endl;

  return 0;
}

/*
Output:

10 20 30
p=0
p5=0xe73f60
~Foo of x=30
~Foo of x=10
*/

/*
Reason:

std::unique_ptr<Foo> p1( new Foo(10)) is not exception safe
std::make_unique<Foo>(20) is exception safe
*/