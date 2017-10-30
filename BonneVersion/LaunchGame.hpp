
#ifndef LAUNCHGAME
# define LAUNCHGAME

#include	<iostream>
#include	<string>
#include	<map>
#include	"Textgame.hpp"
#include	"Shape.hpp"
#include	"Pos.hpp"

# define	NBCHOICE	5

class	LaunchGame
{
public:
  LaunchGame();
  ~LaunchGame();
  bool		getGo(void) const;
  void		setGo(bool);
  bool		getOption(void) const;
  void		setOption(bool);
  void		isTouch(void);
  void		initStruct(void);
  void		newGame(void);
  void		optionGame(void);
  void		exitChoice(void);
  void		option(void);
  bool		getCredits(void) const;
  void		setCredits(bool);
  void		credits(void);
  void		loadGame(void);
  void		*ptr;
private:
  Textbomby	text;
  std::map<int, choicePos>			pos;
  std::map<int, void (LaunchGame::*)(void)>	choose;
  int		posabsolue;
  int		xpos;
  int		ypos;
  bool		go;
  bool		option_;
  Camera	camera_;
  bool		credits_;
  gdl::Color	color;
};

#endif
