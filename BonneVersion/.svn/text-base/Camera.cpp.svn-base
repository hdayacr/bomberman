#include "Camera.hpp"

Camera::Camera(void) : position_(0.0f, 0.0f, 900.0f), rotation_(0.0f, 0.0f ,0.0f)
{
}

void Camera::initialize(void)
{
  view(0, 0, 0);
}

void Camera::update(gdl::GameClock const &gameClock, gdl::Input &input)
{
  (void)gameClock;
  (void)input;
}

void Camera::view(float x, float y, float z)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);
  gluLookAt(x, y, z, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, 0.0f);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}
