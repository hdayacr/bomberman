#include "Menu.hpp"
#include "MyGame.hpp"

Menu::Menu(void)
{
  this->posabsolue = 0;
  this->go = false;
  initStruct();
  this->text_.initialize();
  color = gdl::Color(0, 255, 255);
}

Menu::~Menu(void)
{
}

std::string	Menu::getMap(void) const
{
  return (this->map);
}

bool	Menu::getGo(void) const
{
  return (this->go);
}

void	Menu::setGo(bool Go)
{
  this->go = Go;
}

void Menu::drawInventaire(std::string nbVies, std::string name, std::string bomb, std::string shoe ,std::string flame, int inc, int player)
{
  int   x = inc;
  int   y = 0;

  if (player <= 6)
    {
      this->camera_.view(0, 0, 600);
      text_.writeItem((x * 1.4) - 550, -y + 300, 25, 25, text_.getFlame());
      text_.writeItem((x * 1.4) - 550, -y + 375, 25, 25, text_.getHeart());
      text_.writeItem((x * 1.4) - 550, -y + 325, 25, 25, text_.getShoe());
      text_.writeItem((x * 1.4) - 550, -y + 350, 25, 25, text_.getBomb());
      this->camera_.view(0, -800, 1000);
      text_.write(name, 15, x + 40, y + 25, color);
      text_.write(nbVies, 15, x + 70, y + 45, color);
      text_.write(bomb, 15, x + 70, y + 70, color);
      text_.write(shoe, 15, x + 70, y + 95, color);
      text_.write("+", 15, x + 55, y + 120, color);
      text_.write(flame, 15, x + 70, y + 120, color);

    }
  else
    {
      this->camera_.view(0, 0, 600);
      text_.writeItem((x * 1.4) - 550, -y + 120, 25, 25, text_.getFlame());
      text_.writeItem((x * 1.4) - 550, -y + 195, 25, 25, text_.getHeart());
      text_.writeItem((x * 1.4) - 550, -y + 145, 25, 25, text_.getShoe());
      text_.writeItem((x * 1.4) - 550, -y + 170, 25, 25, text_.getBomb());
      this->camera_.view(0, -800, 1000);
      text_.write(name, 15, x + 40, y + 195, color);
      text_.write(nbVies, 15, x + 70, y + 215, color);
      text_.write(bomb, 15, x + 70, y + 240, color);
      text_.write(shoe, 15, x + 70, y + 265, color);
      text_.write("+", 15, x + 55, y + 290, color);
      text_.write(flame, 15, x + 70, y + 290, color);

    }
}

void Menu::initStruct(void)
{
  tPos xy;
  int	i = 0;
  std::string t = "./map/map.txt";
  std::ifstream argfile(t.c_str());
  std::string	tmp = "";


  system("ls ./map/ > ./map/map.txt");
  while (std::getline(argfile, tmp))
    {
      if (tmp != "map.txt")
	{
	  this->name[i] = tmp;
	  ++i;
	}
    }
  this->max = i;
  xy.x = 20;
  xy.y = 40;
  while (this->posabsolue != this->max)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 20;
      ++this->posabsolue;
    }
  this->posabsolue = 0;
}

void Menu::chooseMap(void)
{
  int	a = 0;
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text_.writeItem(-this->xpos - 530, -this->ypos + 415, 30, 30, text_.getBomb());
  this->camera_.view(0, 0, 1000);
  text_.write("CHOOSE YOUR MAP :", 20, 25, 10, color);
  for (int i = 0; i < this->max; ++i)
    {
      text_.write(this->name[i], 20, 40, 40 + a, color);
      a += 20;
    }
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
	this->posabsolue = this->max - 1;
      else    
	--this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == this->max)
	this->posabsolue = 0;
      else
	++this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      this->map = "./map/" + this->name[this->posabsolue];

      if (this->map == "./map/Classique")
	{
	  ((MyGame *)(this->ptr))->classique.setGo(false);
	  this->setGo(false);
	}
      else
	this->setGo(true);
    }
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("Game is Over");
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Back)) == true)
    {
      this->setGo(false);
      ((MyGame *)(this->ptr))->goForPerso.setGo(false);
      ((MyGame *)(this->ptr))->option.setGo(false);
      ((MyGame *)(this->ptr))->option.setOption(false);
      ((MyGame *)(this->ptr))->launchgame.setGo(false);
      ((MyGame *)(this->ptr))->launchgame.setOption(false);
      ((LaunchGame *)prev)->setGo(false);
      ((MyGame *)(this->ptr))->setPlayer(2);
    }
  this->text_.write("COMMANDS :", 30, 500, 100, color);
  this->text_.write("PLAYER 1 :", 12, 400, 140, color);
  this->text_.write("DIRECTION : LEFT, RIGHT, UP, DOWN", 12, 440, 160, color);
  this->text_.write("BOMBS : RIGHT SHIFT", 12, 440, 180, color);
  this->text_.write("PLAYER 2 :", 12, 400, 200, color);
  this->text_.write("DIRECTION : Z, Q, S, D", 12, 440, 220, color);
  this->text_.write("BOMBS : SPACE", 12, 440, 240, color);
  this->text_.write("PAUSE : P", 15, 400, 265, color);
  usleep(50000);
}
