/*
https://www.modernescpp.com/index.php/c-core-guidelines-type-erasure
*/
#include <iostream>
#include <string>
#include <vector>

struct BaseStruct
{
  virtual std::string getName() const = 0;
};

struct Foo: BaseStruct {
  std::string getName() const {
    return "Foo";
  }
};

struct Bar: BaseStruct {
  std::string getName() const {
    return "Bar";
  }
};

void PrintNames(std::vector<const BaseStruct*> & vec)
{
  for (auto c: vec)
    std::cout << c->getName() << std::endl;
}

int main() {
  Foo foo;
  Bar bar;

  std::vector<const BaseStruct*> vec{&foo, &bar};

  PrintNames(vec);
  return 0;
}