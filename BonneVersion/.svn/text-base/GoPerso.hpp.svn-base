
#ifndef GOPERSO
# define GOPERSO

#include	<iostream>
#include	<string>
#include	<map>
#include	"Textgame.hpp"
#include	"Shape.hpp"
#include	"Pos.hpp"
#include	"Camera.hpp"

# define	NBPERSO		3

class	GoPerso
{
public:
  GoPerso();
  ~GoPerso();
  bool		getGo(void) const;
  void		setGo(bool);
  bool		getGoPerso(void) const;
  void		setGoPerso(bool);
  void		isTouch(void);
  void		initStruct(void);
  void		theChoice(void);
  void		chooseMap(void);
  void		goPerso(void);
  void		bot(void);
  void		*ptr;
  void		*prev;
private:
  Camera	camera_;
  Textbomby	text;
  std::map<int, choicePerso>			pos;
  std::map<int, void (GoPerso::*)(void)>	choose;
  std::map<int, std::string>			namePerso;
  std::map<int, gdl::Image>			avatarPerso;
  int		posabsolue;
  int		xpos;
  int		ypos;
  int		chooseYourFace;
  int		chooseYourFace2;
  bool		go;
  bool		goPerso_;
  int		nbBot;
  gdl::Color	color;
};

#endif
