/*
Link: https://leimao.github.io/blog/CPP-Closure/#:~:text=According%20to%20the%20definition%20of,with%20first%2Dclass%20functions%E2%80%9D.&text=The%20only%20nested%20functions%20allowed%20in%20C%2B%2B%20are%20lambda%20expression.
*/

/*
g++ --version
g++.exe (x86_64-posix-seh-rev0, Built by MinGW-W64 project) 8.1.0
Copyright (C) 2018 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/

#include <iostream>
#include <functional>

std::function<void(void)> closureWrapper1()
{
  int x = 10;

  return [x]() { std::cout << "Value of x = " << x << std::endl; };
}

std::function<void(void)> closureWrapper2()
{
  int x = 10;

  return [&x]() { x += 1; std::cout << "Value of x = " << x << std::endl; };
}

int main() {
  int x = 10;
  auto func0 = [&x]() { x += 1; std::cout << "Value of x = " << x << std::endl; };
  std::function<void(void)> func1 = closureWrapper1();
  std::function<void(void)> func2 = closureWrapper2();

  std::cout << "---------------------\n" ;
  func0();
  func0();
  func0();
  std::cout << "---------------------\n" ;
  func1();
  func1();
  func1();
  std::cout << "---------------------\n" ;
  func2();
  func2();
  func2();
  std::cout << "---------------------\n" ;

  return 0;
}

/*
Output:

---------------------
Value of x = 11
Value of x = 12
Value of x = 13
---------------------
Value of x = 10
Value of x = 10
Value of x = 10
---------------------
Value of x = 1
Value of x = 2
Value of x = 3
---------------------
*/

/*
func0: it is a Closure.
  It captured reference to x in the scope of main.
  Hence in every call, the Value of x get incremented by 1.

func1 and func2 are not Closure.
  These are std::function wrapper objects that wrapped closures

  func1
    It captured the value of the variable x in the scope of closureWrapper1.
    Hence in each call, we see the same value of 10.
  func2
    It captured x as reference in the scope of closureWrapper2.
    The address of x is invalid once closureWrapper2 is out of scope.
    The value of x is undefined.
*/