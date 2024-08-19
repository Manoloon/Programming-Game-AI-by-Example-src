#ifndef OBSTACLE_H
#define OBSTACLE_H
//------------------------------------------------------------------------
//
//  Name:   Obstacle.h
//
//  Desc:   Simple obstacle class
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------
#include "../2d/Vector2D.h"
#include "../Game/BaseGameEntity.h"
#include "../misc/Cgdi.h"
#include <windows.h>

class Obstacle : public BaseGameEntity
{
public:

  Obstacle(double x,
           double y,
           double r):BaseGameEntity(0, Vector2D(x,y), r)
  {}

  Obstacle(Vector2D pos, double radius):BaseGameEntity(0, pos, radius)
  {}

  explicit Obstacle(std::ifstream& in) {Read(in);}

  ~Obstacle() override = default;

  //this is defined as a pure virtual function in BasegameEntity so
  //it must be implemented
  void      Update([[maybe_unused]] double time_elapsed) override {};

  void      Render() override {gdi->BlackPen();gdi->Circle(Pos(), BRadius());}

  void      Write(std::ostream& os)const override;
  void      Read(std::ifstream& in) override;
  bool      HandleMessage([[maybe_unused]] const Telegram& msg) override {return false;};
};

#endif
