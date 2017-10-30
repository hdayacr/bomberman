
#ifndef OPTION
# define OPTION

#include	<iostream>
#include	<string>
#include	<map>
#include	"Textgame.hpp"
#include	"Shape.hpp"
#include	"Pos.hpp"

# define	NBOPTIONS	4

class	Option
{
public:
  Option();
  ~Option();
  bool		getGo(void) const;
  void		setGo(bool);
  bool		getOption(void) const;
  void		setOption(bool);
  void		isTouch(void);
  void		initStruct(void);
  void		choiceNbPlayer(void);
  void		level(void);
  void		isMusic(void);
  void		goPerso(void);
  void		*ptr;
  void		*prev;
private:
  Textbomby	text;
  std::map<int, choicePos>			pos;
  std::map<int, void (Option::*)(void)>		choose;
  std::map<int, bool>				sonOnOff;
  int		posabsolue;
  int		xpos;
  int		ypos;
  int		choiceNb;
  int		onOffMusic;
  int		choiceLevel;
  bool		go;
  bool		option_;
  Camera	camera_;
  gdl::Color	color;
};

#endif
