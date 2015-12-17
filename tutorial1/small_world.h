#ifndef SMALL_WORLD_H
#define SMALL_WORLD_H

#include "world.h"

namespace my
{

class SmallWorld : public World
{
public:
  SmallWorld(std::string);
  SmallWorld(double, double);
  std::string get();
};

};

#endif  //SMALL_WORLD_H