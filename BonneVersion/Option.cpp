#include	"MyGame.hpp"
#include	"Option.hpp"

Option::Option()
{
  this->posabsolue = 0;
  this->go = false;
  this->option_ = false;
  this->choiceNb = 100;
  this->choiceLevel = 0;
  this->onOffMusic = 0;
  this->initStruct();
  this->text.initialize();
  sonOnOff[0] = true;
  sonOnOff[100] = false;
  this->color = gdl::Color(150, 100, 200);
}

Option::~Option()
{

}

bool		Option::getGo(void) const
{
  return (this->go);
}

void		Option::setGo(bool Go)
{
  this->go = Go;
}

bool		Option::getOption(void) const
{
  return (this->option_);
}

void		Option::setOption(bool opt)
{
  this->option_ = opt;
}

void		Option::choiceNbPlayer(void)
{
 if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      if (this->choiceNb - 1 < 0)
        this->choiceNb = 100;
      else
        this->choiceNb -= 100;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      if (this->choiceNb + 100 == 200)
        this->choiceNb = 0;
      else
        this->choiceNb += 100;
    }

  this->text.write("solo", 30, this->xpos + 550 + 0, 180, color);
  this->text.write("duo", 30, this->xpos + 570 + 100, 180, color);
  this->text.write("^", 45, this->xpos + 580 + this->choiceNb, this->ypos + 85, color);
}

void		Option::level(void)
{
 if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      if (this->choiceLevel - 1 < 0)
        this->choiceLevel = 100;
      else
        this->choiceLevel -= 100;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      if (this->choiceLevel + 100 == 300)
        this->choiceLevel = 0;
      else
        this->choiceLevel += 100;
    }
  this->text.write("easy", 20, this->xpos + 500 + 0, 260, color);
  this->text.write("medium", 20, this->xpos + 500 + 85, 260, color);
  this->text.write("hard", 20, this->xpos + 500 + 200, 260, color);
  this->text.write("^", 45, this->xpos + 520 + this->choiceLevel, this->ypos + 85, color);
}

void		Option::isMusic(void)
{

 if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      if (this->onOffMusic - 1 < 0)
        this->onOffMusic = 100;
      else
        this->onOffMusic -= 100;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      if (this->onOffMusic + 100 == 200)
        this->onOffMusic = 0;
      else
        this->onOffMusic += 100;
    }

  this->text.write("on", 30, this->xpos + 550 + 0, 350, color);
  this->text.write("off", 30, this->xpos + 550 + 100, 350, color);
  this->text.write("^", 45, this->xpos + 560 + this->onOffMusic, this->ypos + 95, color);
}

void		Option::goPerso(void)
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    if (this->posabsolue == 3)
      {
	this->go = true;
	((MyGame *)(this->ptr))->son = sonOnOff[this->onOffMusic];
	if (this->choiceNb == 100)
	  {
	    ((MyGame *)(this->ptr))->setPlayer(2);
	    ((MyGame *)(this->ptr))->mode = DUEL;
	  }
	else
	  {
	    ((MyGame *)(this->ptr))->setPlayer(1);
	    ((MyGame *)(this->ptr))->mode = SOLO;
	  }
      }
}

void		Option::initStruct(void)
{
  choicePos	xy;

  xy.x = 20;
  xy.y = 120;
  while (this->posabsolue != NBOPTIONS - 1)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->pos[this->posabsolue].x = xy.x;
  this->pos[this->posabsolue].y = xy.y + 110;
  this->posabsolue = 0;
  this->choose[0] = &Option::choiceNbPlayer;
  this->choose[1] = &Option::level;
  this->choose[2] = &Option::isMusic;
  this->choose[3] = &Option::goPerso;
}

void		Option::isTouch(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text.writeItem(-this->xpos - 500, -this->ypos + 360, 60, 60, text.getBomb()); 
  this->camera_.view(0, 0, 1000);
  this->text.write("MOD", 45, 100, 180, color);
  this->text.write("DIFICULTY", 45, 100, 260, color);
  this->text.write("SOUND", 45, 100, 340, color);
  this->text.write("CHOOSE CHARACTER", 40, 100, 350 + 170, color);
  if (this->choose[this->posabsolue])
    (this->*(choose[this->posabsolue]))();
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBOPTIONS - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBOPTIONS)
        this->posabsolue = 0;
      else
        ++this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("See you !");
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Back)) == true)
    {
      this->setGo(false);
      this->setOption(false);
      ((LaunchGame *)prev)->setOption(false);
    }
  usleep(50000);
}
