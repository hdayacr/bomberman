
#ifndef TOUCH_HPP__
# define TOUCH_HPP__

# include "Input.hpp"
# include "Bomberman.hpp"
# include "MyGame.hpp"

struct		stockPerso
{
  int		perso;
  MyGame	*t;
  Bomb		*bomb;
};


class Touch
{
public:
  Touch();
  virtual ~Touch();
  void		catchTouch(gdl::Keys::Key, MyGame *);
  void		doEscape(MyGame *);
  void		doUp(MyGame *);
  void		doDown(MyGame *);
  void		doLeft(MyGame *);
  void		doRight(MyGame *);
  void		doRShift(MyGame *);
  void		doZup(MyGame *);
  void		doSdown(MyGame *);
  void		doQleft(MyGame *);
  void		doDright(MyGame *);
  void		doSpace(MyGame *);
  void		doBack(MyGame *);
  void		doS(MyGame *);
  void		doPause(MyGame *);
private:
  std::map<gdl::Keys::Key, void (Touch::*)(MyGame *)>	functionTouch;
  int		i;
  int	        j;
};

#endif // !TOUCH_HPP__
