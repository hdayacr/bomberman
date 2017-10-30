#ifndef CAMERA_HH
# define CAMERA_HH

# include <GameClock.hpp>
# include <Input.hpp>
# include <GL/gl.h>
# include <GL/glu.h>
# include "Vector3f.hpp"


class Camera
{
public:
  Camera(void);
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
  void view(float, float, float);
private:
  Vector3f position_;
  Vector3f rotation_;
};

#endif
