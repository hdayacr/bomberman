#ifndef BOMB_HPP__
#define BOMB_HPP__

# include <iostream>
# include "Pos.hpp"
# include <list>

class Bomb
{
public:
  Bomb();
  ~Bomb();
  std::list<tBomb>	getListExplo(void) const;
  void			createExplo(void *);
  int			getX(void) const;
  int			getY(void) const;
  bool			getExpl(void) const;
  bool			getToken(void) const;
  bool			getTest(void) const;
  void			setX(int);
  void			setY(int);
  void			setExpl(bool);
  void			setToken(bool);
  void			setTest(bool);
  bool			coordExp(int, int, bool, void *);
  std::list<tBomb>	listExplo;
private:
  int			x;
  int			y;
  int			nbPlayer;
  bool			expl;
  bool			test;
  bool			token;
};

#endif
