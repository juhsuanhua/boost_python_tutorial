// Reference: http://www.boost.org/doc/libs/1_59_0/libs/python/doc/tutorial/doc/html/python/object.html

#include <iostream>
#include <vector>

#include <boost/python.hpp>

using namespace boost::python;

object compareUpper(str name)
{
  str in_upper = name.upper();
  tuple ret = make_tuple(in_upper, name);
  return ret;
}

void editDict(dict d)
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
  dict getVars()
  {
    dict vars;
    vars["a"] = a_;
    vars["b"] = b_;
    return vars;
  }
private:
  int a_, b_;
};

object getCObject()
{
  object ret = (
    class_<C>("C", init<int, int>())
        .def("sum", &C::sum)
        .def("get_vars", &C::getVars)
    )(3, 4);
  return ret;
}


// Extracting objects

double extractLength(object vec)
{
  // double length = extract<double>(vec.attr("length"));
  double length = extract<double>(vec.attr("length"));
  return length;
}


// Use enums

enum choice { red, blue };

// See how Boost Python deals with vectors

template<typename T>
list convertToList(const std::vector<T> &vec)
{
  list ret;
  for (auto iter = vec.begin(); iter != vec.end(); iter++)
  {
    ret.append(*iter);
  }
  return ret;
}

list getVector()
{
  std::vector<tuple> vec;
  for (unsigned int i = 0; i < 10; i++)
  {
    vec.push_back(make_tuple(i, 2 * i));
  }
  list L = convertToList(vec);
  return L;
}


BOOST_PYTHON_MODULE(T2)
{
  def("compare_upper", compareUpper);
  def("edit_dict", editDict);
  def("get_c_object", getCObject);
  def("extract_length", extractLength);
  enum_<choice>("choice")
      .value("red", red)
      .value("blue", blue)
  ;
  def("get_vector", getVector);
}
