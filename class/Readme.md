# C++

_In C++, there are three things that every object should be able to do:_

- An object should be able to initialize itself to a default state
  - default constructors
    - e.g., `TFoo::TFoo()`
- An object should be able to initialize itself from another instance of same class
  - copy constructor
    - e.g., `TFoo::TFoo(const TFoo & rhs)`
    - __const rhs__ is _required_ to have construction from const objects, otherwise we can't construct from const object
    - __get rhs by reference__, otherwise unnecessarily temp object will be created for rhs (since it is pass-by-value)
- An object should be able to assume the same semantic state of another instance of the same class
  - assignment operator
    - e.g., `TFoo& TFoo::operator=(const TFoo & rhs)`
    - __const rhs__ is _required_ to have assignment from const objects
    - __get rhs by reference__, otherwise unnecessarily temp object will be created for rhs (since it is pass-by-value)
    - if you do not want chaining, you can have return type as void. i.e., if void is return type then you can't do e.g., `x = y = z = 16`.

_C++11 and above:_

From C++11 onwards additionally following things can be done:

- An object should be able to initialize itself by moving members from another rvalue instance of same class
  - move constructor
    - e.g., `TFoo::TFoo(TFoo && rhs)`
    - since we are moving, __rhs object should NOT be const__
    - note __&&__ to rhs, we are taking _rvalue object_
- An object should be able to assume semantice state of another rvalue instance of same class by moving its members
  - move assignment operator
    - e.g., `TFoo& TFoo::operator=(TFoo && rhs)`
    - since we are moving, __rhs object should NOT be const__
    - note __&&__ to rhs, we are taking _rvalue object_

_Uniform Initialization: (braced initialization list)_

if you define list-constructor, better define list-assignment operator as well

- An object should be able to initialize itself from a std::initializer-list which enables uniform initialization
  - list copy constructor
    - e.g., `TFoo::TFoo(const std::initializer_list<T> & list)`
    - __const rhs__ is _required_, otherwise unnecessarily temp list initializer object will be created (since it is pass-by-value)
    - _T_ can be required data that need to assigned to this object
- An object should be able to assume the semantics from a list
  - list assignment operator
    - e.g., `void operator=(const std::initializer_list<T> & list)`
    - __const rhs__ is _required_, otherwise unnecessarily temp list initializer object will be created (since it is pass-by-value)
    - since it assigning values to current object, there is no return value from this operator=
    - _if you want chaining assignment operator, return this as reference_
      - e.g., `TFoo& operator=(const std::initializer_list<T> & list)`
      - x  y = z = { 1, 2, 3, 4 };

## Links

  Assignment Operator

    *) <http://icu-project.org/docs/papers/cpp_report/the_anatomy_of_the_assignment_operator.html>
    *) <http://icu-project.org/docs/papers/cpp_report/the_assignment_operator_revisited.html>
    *) <https://brskari.wordpress.com/2011/02/24/c-assignment-operator-or-how-i-learned-to-stop-worrying-and-not-check-for-self-assignment/>
