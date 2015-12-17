#ifndef HELLO_EXT_H
#define HELLO_EXT_H

#include <boost/python.hpp>

using namespace boost::python;

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


#endif  // HELLO_EXT_H