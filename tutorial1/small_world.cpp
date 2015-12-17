#include "small_world.h"

namespace my
{

SmallWorld::SmallWorld(std::string msg): World(msg) {}

SmallWorld::SmallWorld(double a, double b): World(a, b) {}

std::string SmallWorld::get()
{
  std::string prefix = "msg: ";
  return prefix + msg;
}

};