#include "world.h"

namespace my
{

World::World(std::string msg): msg(msg) {}

World::World(double a, double b): msg(std::to_string(a + b))
{
  romsg = msg;
}

void World::set(std::string msg)
{
  this->msg = msg;
}

std::string World::get() const
{
  return msg;
}

};