#ifndef MENU_HPP
# define MENU_HPP

#include <map>
#include <iostream>
#include <string>
# include <fstream>
#include "Camera.hpp"
#include "Textgame.hpp"

# define NBOPTION 5

typedef struct spos
{
  int	x;
  int	y;
}		tPos;

class		Menu
{
public:
  Menu();
  ~Menu();
  void				initStruct(void);
  void				chooseMap(void);
  void				drawInventaire(std::string, std::string, std::string, std::string, std::string, int, int);
  bool				getGo(void) const;
  void				setGo(bool);
  std::string			getMap(void) const;
  void				*ptr;
  void				*prev;
  std::string			map;
private:
  std::map<int, tPos>		pos;
  std::map<int, std::string>	name;
  int				xpos;
  int				ypos;
  int				posabsolue;
  bool				go;
  Textbomby			text_;
  int				max;
  Camera			camera_;
  gdl::Color			color;
};

#endif // !MENU_HPP
