/*
https://en.cppreference.com/w/cpp/utility/program/exit
*/
#include <iostream>

class Global {
  public:
    Global(int i) : _i{i} {
      std::cout << "Global " << _i << " ctor\n";
    }
    ~Global() {
      std::cout << "Global " << _i << " dtor\n";
    }
private:
  int _i;
};

class Static {
  public:
    Static(int i) : _i{i} {
      std::cout << "Static " << _i << " ctor\n";
    }
    ~Static() {
      std::cout << "Static " << _i << " dtor\n";
    }
private:
  int _i;
};

class Local {
  public:
    Local(int i) : _i{i} {
      std::cout << "Local " << _i << " ctor\n";
    }
    ~Local() {
      std::cout << "Local " << _i << " dtor\n";
    }
private:
  int _i;
};

void atexit_handler() {
  std::cout << "atexit handler\n";
}

Global global_variable_1{1};
static Static static_variable_1{2};
Global global_variable_2{3};
static Static static_variable_2{4};

int main() {
  Local local_variable{5}; // dtor of this object will *not* be called
  static Static static_variable_3{6};
  const int result = std::atexit(atexit_handler); // handler will be called

  if(result != 0) {
    std::cerr << "atexit registration failed\n";
    return EXIT_FAILURE;
  }

  std::cout << "Before std::exit() call...\n";
  std::exit(EXIT_FAILURE);
}

/*
Output:

Global 1 ctor
Static 2 ctor
Global 3 ctor
Static 4 ctor
Local 5 ctor
Static 6 ctor
Before std::exit() call...
atexit handler
Static 6 dtor
Static 4 dtor
Global 3 dtor
Static 2 dtor
Global 1 dtor
*/

/*
Notes:
  *) when std::exit() get invoked
    *) local destructor is not getting invoked
    *) However local static destructor is getting invoked
    *) The destructors for both static and global variables are invoked in the same order it is created
  *) When main() is returned normally
    *) First local variable destructors are get invoked
    *) Next local static variable destructors are get invoked
    *) Finally in order of its creation, global and static variable destructors are invoked
*/