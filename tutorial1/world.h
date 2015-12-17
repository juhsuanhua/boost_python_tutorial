#ifndef WORLD_H
#define WORLD_H

#include <string>

namespace my
{

class World
{
public:
  World(std::string msg);
  World(double a, double b);
  void set(std::string msg);
  std::string get() const;

protected:
  std::string msg;
  std::string romsg;

};

}; // namespace my

#endif  // WORLD_H
