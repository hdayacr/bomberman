#ifndef BOMBERMAN_HPP__
# define BOMBERMAN_HPP__

# include <fstream>
# include <iostream>
# include <list>
# include <map>
# include "Character.hpp"
# include "Error.hpp"
# include "Menu.hpp"
# include "Pos.hpp"
# include "Intro.hpp"
# include "LaunchGame.hpp"
# include "Option.hpp"
# include "Bomb.hpp"
# include "GoPerso.hpp"
# include "inGame.hpp"
# include "Credits.hpp"
# include "Classique.hpp"
# include "Load.hpp"

typedef enum
  {
    SOLO = 1,
    DUEL = 2
  }	modeGame;


#define	CERCUEIL	20

class Bomberman
{
public:
  Bomberman();
  virtual ~Bomberman();
  void					addMapByFile(char const * const fileName);
  void					stockPosInList(int, int);
  void					stockPosInlistFakeWall(int, int);
  void					stockPosInlistBonus(int, int, int);
  void					demolitionWall(int, int, Bomb *);
  bool					checkwall(int, int);
  bool					checkTrueWall(int, int);
  bool					checkBomb(int, int);
  void					death(int, int);
  void					addExplo(int, int);
  void					createPlayer(int, int, std::string &, int, int);
  int					getXMap(void) const;
  int					getYMap(void) const;
  std::map<int, Character*>		getlistPlayer(void) const;
  int					getRandomItem(void);
  bool					checkFakeWall(int, int);
  void					takeOffFakeWall(int, int);
  Menu					menu;
  inGame				pausegame;
  LaunchGame                            launchgame;
  Intro                                 intro;
  Option				option;
  GoPerso				goForPerso;
  Credits				credit;
  Classique				classique;
  Load					load;
protected:
  std::map<int, Character*>		listPlayer;
  std::list<t_pos>			listMur;
  std::list<t_pos>			listFakeWall;
  std::list<t_posBonus>			listBonus;
  std::map<int, gdl::Image>		Item;
  Textbomby				bonus_;
  int					xMap;
  int					yMap;
};

typedef struct s_push
{
  int		x;
  int		y;
  int		p;
  int		xB;
  int		yB;
  Bomberman	*ptr;
}		pushBomb;

#endif
