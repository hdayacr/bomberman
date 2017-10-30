#include "Bomb.hpp"

#include "Bomberman.hpp"

Bomb::Bomb()
{
  this->token = false;
  this->test = false;
}

Bomb::~Bomb()
{
}

std::list<tBomb>	Bomb::getListExplo(void) const
{  
  return this->listExplo;
}

int			Bomb::getX(void) const
{
  return this->x;
}

int			Bomb::getY(void) const
{
  return this->y;
}

bool			Bomb::getExpl(void) const
{
  return this->expl;
}

bool		Bomb::getToken(void) const
{
  return this->token;
}

bool		Bomb::getTest(void) const
{
  return this->test;
}

void			Bomb::setX(int x_)
{
  this->x = x_;
}

void			Bomb::setY(int y_)
{
  this->y = y_;
}

void			Bomb::setExpl(bool ex)
{
  this->expl = ex;
}

void		Bomb::setToken(bool token)
{
  this->token = token;
}

void		Bomb::setTest(bool test)
{
  this->test = test;
}

bool			Bomb::coordExp(int xE, int yE, bool flag, void *t)
{
  if (((Bomberman *)t)->checkTrueWall(xE, yE) == true && flag == false)
    {
      tBomb	newBomb;

      newBomb.x = xE;
      newBomb.y = yE;
      this->listExplo.push_back(newBomb);
      return (false);
    }
  return (true);
}

void			Bomb::createExplo(void *t)
{
  int	a = 0; 
  bool xAdd = false, xMin = false, yAdd = false, yMin = false;

  int xE = this->x;
  int yE = this->y;

  for (; a < 3; ++a)
    {
      xAdd = this->coordExp(xE + a, yE, xAdd, t);
      yAdd = this->coordExp(xE, yE + a, yAdd, t);
      xMin = this->coordExp(xE - a, yE, xMin, t);
      yMin = this->coordExp(xE, yE - a, yMin, t);
    }
}
