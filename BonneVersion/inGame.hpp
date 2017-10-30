#ifndef INGAME_HPP
# define INGAME_HPP

#include <iostream>
#include "Textgame.hpp"
#include "Camera.hpp"
#include "Pos.hpp"
#include <map>
#include <pthread.h>

# define NBPAUSE 5

class inGame
{
public:
  inGame();
  ~inGame();
  void		initStruct();
  void		inPause();
  void		rePlay();
  void		reStart();
  void		save();
  void		isMusic();
  void		exit();
  bool		getGo()const;
  void		setGo(bool);
  void		*ptr;
  pthread_t	tAffich;
  bool		affichSave;
private:
  std::map<int, void (inGame::*)(void)>		choose;
  std::map<int, t_pos>	pos;
  std::map<bool, int>	sonTrueOrFalse;
  Textbomby	text;
  Camera	 camera_;
  int		posabsolue;
  int		onOffMusic;
  bool		go;
  int		xpos;
  int		ypos;
  gdl::Color	color;
};

# endif
