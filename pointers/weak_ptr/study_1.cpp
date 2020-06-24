/*
https://www.modernescpp.com/index.php/std-weak-ptr
*/

#include <iostream>
#include <memory>

struct Son;
struct Daughter;

struct Mother {
  Mother() {
    std::cout << "Mother" << std::endl;
  }
  ~Mother() {
    std::cout << "~Mother" << std::endl;
  }

  void setSon(const std::shared_ptr<Son> son) {
    mySon = son;
  }

  void setDauther(const std::shared_ptr<Daughter> daughter) {
    myDaughter = daughter;
  }

  std::shared_ptr<const Son> mySon;
  std::weak_ptr<const Daughter> myDaughter;
};

struct Son {
  Son(std::shared_ptr<Mother> mother) : myMother(mother) {
  }

  ~Son() {
    std::cout << "~Son" << std::endl;
  }

  std::shared_ptr<Mother> myMother;
};

struct Daughter {
  Daughter(std::shared_ptr<Mother> mother) : myMother(mother) {
    std::cout << "Daughter" << std::endl;
  }

  ~Daughter() {
    std::cout << "~Daughter" << std::endl;
  }

  std::shared_ptr<Mother> myMother;
};

int main() {
  std::cout << std::endl;

  {
    std::shared_ptr<Mother> m(new Mother);
    std::shared_ptr<Son> s(new Son(m));
    std::shared_ptr<Daughter> d(new Daughter(m));

    m->setSon(s);
    m->setDauther(d);
  }
  
  std::cout << std::endl;
  return 0;
}

/*
Output:

Mother
Daughter
~Daughter
*/

/*
Since Daughter is shared with Mother as a Weak pointer, its reference count is not incremented
Hence, on its scope end, it is getting deleted automatically

Since Son is shared with Mother as shared_ptr, its reference count is incremented
Hence, during its out-of-scope, it is not deleted

Since Son holds Mother, mother also didn't get deleted
*/