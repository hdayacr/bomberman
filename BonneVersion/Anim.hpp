#ifndef ANIM_HPP
# define ANIM_HPP

#include "Aobject.hpp"
#include "Model.hpp"
#include "AnimStates.hpp"
#include "Camera.hpp"

class Anim : public AObject
{
public:
  Anim(void);
  ~Anim(void);
  void initialize(void);
  void update(gdl::GameClock const &, gdl::Input &);
  void draw(void);
  int getColor() const;
  void setColor(int);
  void drawmBomb(float, float);
  void *game;
public:
  gdl::Model model_;
  gdl::Color color_;
  gdl::Model bomb_;
  int colori_;
};

#endif
