#ifndef LOAD_HPP
# define LOAD_HPP

#include <map>
#include <iostream>
#include <string>
# include <fstream>
#include "Camera.hpp"
#include "Textgame.hpp"
#include "Menu.hpp"

# define NBOPTION 5


class		Load
{
public:
  Load();
  ~Load();
  void				initStruct(void);
  void				chooseLoad(void);
  void				drawInventaire(std::string, std::string, std::string, int);
  bool				getGo(void) const;
  void				setGo(bool);
  void				*ptr;
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

#endif // !LOAD_HPP
