/* 
Reference: http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/index.html#python.quickstart
*/

#include <iostream>

#include <boost/python.hpp>

#include "world.h"
#include "small_world.h"

using namespace boost::python;

// Exporting classes

void world(my::World* w) {}

void smallWorld(my::SmallWorld* s) {}

my::World* function()
{
  return new my::SmallWorld("");
}

// Call policies

struct A
{
  A(int val): value(val) {}
  int value;
};

struct B
{
  B(int val): value(val), a1(A(val)), a2(A(2 * val)) {}
  int value;
  A a1, a2;
};

A& f(B& b, A* a)
{
  b.a2 = *a;
  return b.a1;
}

// Overloading

struct X
{
  bool f(int a)
  {
    return true;
  }

  bool f(int a, double b)
  {
    return true;
  }

  bool f(int a, double b, char c)
  {
    return true;
  }

  int f(int a, int b, int c)
  {
    return a + b + c;
  };
};

bool    (X::*fx1)(int)              = &X::f;
bool    (X::*fx2)(int, double)      = &X::f;
bool    (X::*fx3)(int, double, char)= &X::f;
int     (X::*fx4)(int, int, int)    = &X::f;


// Default arguments

void foo (int a, char b = 'b', unsigned c = 2, double d = 3)
{
  std::cout << "a: " << a;
  std::cout << " b: " << b;
  std::cout << " c: " << c;
  std::cout << " d: " << d << "\n";  // Boost Python doesn't seem to recognize std::endl...
}
BOOST_PYTHON_FUNCTION_OVERLOADS(foo_overloads, foo, 1, 4);

struct George
{
  George(int w, char x = 'X', std::string y = "y", double z = 0.0):
    w(w), x(x), y(y), z(z) {}

  void wack_em(int a, int b = 0, char c = 'x')
  {
    std::cout << "a: " << a;
    std::cout << " b: " << b;
    std::cout << " c: " << c << "\n";
  }

  int w;
  char x;
  std::string y;
  double z;
};
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(george_overloads, George::wack_em, 1, 3);


BOOST_PYTHON_MODULE(hello_ext)
{

  // Exporting classes
  class_<my::World>("World", init<std::string>())
      .def(init<double,double>())
      .def("get", &my::World::get)
      .def("set", &my::World::set)
      .add_property("msg", &my::World::get, &my::World::set)
      .add_property("romsg", &my::World::get)
  ;

  class_<my::SmallWorld, bases<my::World> >("SmallWorld", init<std::string>())
      .def(init<double,double>())
      .def("get", &my::SmallWorld::get)
      .def("set", &my::SmallWorld::set)
      .add_property("msg", &my::SmallWorld::get, &my::SmallWorld::set)
      .add_property("romsg", &my::SmallWorld::get)
  ;

  def("world", world);
  def("small_world", smallWorld);
  def("function", function, return_value_policy<manage_new_object>());


  // Call policies
  class_<A>("A", init<int>())
      .def_readonly("val", &A::value)
  ;
  class_<B>("B", init<int>())
      .def_readonly("a1", &B::a1)
      .def_readonly("a2", &B::a2)
  ;
  def("f", f,
      return_internal_reference<1,
          with_custodian_and_ward<1, 2> >());

  // Overloading
  class_<X>("X")
      .def("f", fx1)
      .def("f", fx2)
      .def("f", fx3)
      .def("f", fx4)
  ;

  // Default arguments
  def("foo", foo, foo_overloads());
  class_<George>("George", init<int, optional<char, std::string, double> >())
      .def("wack_em", &George::wack_em, george_overloads());
}
