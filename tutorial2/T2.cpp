// Reference: http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/python/object.html

#include <iostream>
#include <vector>

#include <boost/python.hpp>


boost::python::object compareUpper(boost::python::str name)
{
  boost::python::str in_upper = name.upper();
  boost::python::tuple ret = make_tuple(in_upper, name);
  return ret;
}

void editDict(boost::python::dict d)
{
  d["field"] = 3;
}

// class_<T> as objects

class C
{
public:
  C(int a, int b): a_(a), b_(b){}
  int sum()
  {
    return a_ + b_;
  }
  boost::python::dict getVars()
  {
    boost::python::dict vars;
    vars["a"] = a_;
    vars["b"] = b_;
    return vars;
  }
private:
  int a_, b_;
};

boost::python::object getCObject()
{
  boost::python::object ret = (
    boost::python::class_<C>("C", boost::python::init<int, int>())
        .def("sum", &C::sum)
        .def("get_vars", &C::getVars)
    )(3, 4);
  return ret;
}


// Extracting objects

double extractLength(boost::python::object vec)
{
  // double length = extract<double>(vec.attr("length"));
  double length = boost::python::extract<double>(vec.attr("length"));
  return length;
}


// Use enums

enum choice { red, blue };

// See how Boost Python deals with vectors

template<typename T>
boost::python::list convertToList(const std::vector<T> &vec)
{
  boost::python::list ret;
  for (auto iter = vec.begin(); iter != vec.end(); iter++)
  {
    ret.append(*iter);
  }
  return ret;
}

boost::python::list getVector()
{
  std::vector<boost::python::tuple> vec;
  for (unsigned int i = 0; i < 10; i++)
  {
    vec.push_back(boost::python::make_tuple(i, 2 * i));
  }
  boost::python::list L = convertToList(vec);
  return L;
}


BOOST_PYTHON_MODULE(T2)
{
  boost::python::def("compare_upper", compareUpper);
  boost::python::def("edit_dict", editDict);
  boost::python::def("get_c_object", getCObject);
  boost::python::def("extract_length", extractLength);
  boost::python::enum_<choice>("choice")
      .value("red", red)
      .value("blue", blue)
  ;
  boost::python::def("get_vector", getVector);
}
