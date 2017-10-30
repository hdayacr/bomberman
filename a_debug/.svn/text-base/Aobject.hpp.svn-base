#ifndef AOBJECT_HH
# define AOBJECT_HH

# include <GL/gl.h>
# include <GL/glu.h>
# include <GameClock.hpp>
# include <Input.hpp>
# include "Vector3f.hpp"

class AObject
{
public:
  AObject(void)
    : position_(0.0f, 0.0f, 0.0f), rotation_(0.0f, 0.0f, 0.0f)
  {
  }
  virtual void initialize(void) = 0;
  virtual void update(gdl::GameClock const &, gdl::Input &) = 0;
  virtual void draw(void) = 0;
public:
  Vector3f position_;
  Vector3f rotation_;
};

#endif
