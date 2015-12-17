#include "world.h"
#include <boost/python.hpp>
using namespace boost::python;

// namespace my
// {

// class World
// {
//   std::string msg;
//   std::string romsg;
// public:
//   World(std::string msg): msg(msg), romsg(msg) {}
//   World(double a, double b): msg(std::to_string(a + b)) { romsg = msg; }
//   void set(std::string msg) { this->msg = msg; }
//   std::string get() const { return msg; }
// };

// };

BOOST_PYTHON_MODULE(hello_ext)
{
  class_<my::World>("World", init<std::string>())
      .def(init<double,double>())
      .def("get", &my::World::get)
      .def("set", &my::World::set)
      .add_property("msg", &my::World::get, &my::World::set)
      .add_property("romsg", &my::World::get)
  ;
}