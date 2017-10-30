#include "Intro.hpp"
#include "MyGame.hpp"

Intro::Intro(void)
{
  this->go = false;
  this->text.initialize();
  this->color = gdl::Color(0, 0, 0);
}

Intro::~Intro(void)
{
}

bool	Intro::getGo(void) const
{
  return (this->go);
}

void	Intro::setGo(bool Go)
{
  this->go = Go;
}

void	Intro::isTouch(void)
{
  text.write("PRESS SPACE TO CONTINUE", 25, 270, 500, color);
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("See you !");
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Space)) == true)
    this->setGo(true);
}
