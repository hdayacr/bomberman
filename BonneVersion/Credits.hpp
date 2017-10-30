
#ifndef CREDITS
# define CREDITS

#include	<iostream>
#include	<string>
#include	<map>
#include	"Textgame.hpp"
#include	"Shape.hpp"
#include	"Pos.hpp"
#include	"Camera.hpp"

# define	NBCREDITS		1

class	Credits
{
public:
  Credits();
  ~Credits();
  bool		getGo(void) const;
  void		setGo(bool);
  bool		getCredits(void) const;
  void		setCredits(bool);
  void		isTouch(void);
  void		initStruct(void);
  void		theChoice(void);
  void		chooseMap(void);
  void		goPerso(void);
  void		*ptr;
  void		*prev;

  int		x;
  int		x2;
  int		x3;
  int		x4;
  int		x5;
  int		x6;
private:
  std::map<int, credits>			pos;
  std::map<int, void (Credits::*)(void)>	choose;
  std::map<int, std::string>			namePerso;
  std::map<int, gdl::Image>			avatarPerso;

  Camera	camera_;
  Textbomby	text;
  gdl::Color	color;

  int		posabsolue;
  int		xpos;
  int		ypos;
  int		creditsFace;
  bool		go;
  bool		credits_;
};

#endif
