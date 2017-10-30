#include "Load.hpp"
#include "MyGame.hpp"

Load::Load(void)
{
  this->posabsolue = 0;
  this->go = true;
  initStruct();
  this->text_.initialize();
  this->color = gdl::Color(150, 100, 200);
}

Load::~Load(void)
{
}

bool	Load::getGo(void) const
{
  return (this->go);
}

void	Load::setGo(bool Go)
{
  this->go = Go;
}

void Load::initStruct(void)
{
  tPos xy;
  int	i = 0;
  std::string t = "./save/save";
  std::ifstream argfile(t.c_str());
  std::string   tmp = "";


  this->max = NBOPTION;
  xy.x = 20;
  xy.y = 180;
  while (std::getline(argfile, tmp))
    {
      this->name[i] = tmp;
      ++i;
    }
  while (this->posabsolue != this->max)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->posabsolue = 0;
}

void Load::chooseLoad(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text_.writeItem(-this->xpos - 530, -this->ypos + 415, 70, 70, text_.getBomb());
  this->camera_.view(0, 0, 1000);
  text_.write("Choose your save :", 35, 100, 10, color);
  this->text_.write("Save 1", 45, 100, 180, color);
  this->text_.write("Save 2", 45, 100, 260, color);
  this->text_.write("Save 3", 45, 100, 340, color);
  this->text_.write("Save 4", 45, 100, 420, color);
  this->text_.write("Save 5", 45, 100, 500, color);

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
      this->setGo(true);
      ((MyGame *)(this->ptr))->save = "./save/" + this->name[this->posabsolue];
      
      ((MyGame *)(this->ptr))->menu.setGo(true);
      ((MyGame *)(this->ptr))->cleanListPerso();
      ((MyGame *)(this->ptr))->loadGame();
    }
  if ((((MyGame *)(this->ptr))->getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("Game is Over");

  usleep(50000);
}
