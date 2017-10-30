#include	"MyGame.hpp"
#include	"LaunchGame.hpp"

LaunchGame::LaunchGame()
{
  this->posabsolue = 0;
  this->go = false;
  this->option_ = false;
  this->initStruct();
  this->text.initialize();
  this->credits_ = false; 
  this->color = gdl::Color(50, 100, 130);
}

LaunchGame::~LaunchGame()
{
}

bool		LaunchGame::getGo(void) const
{
  return (this->go);
}

void		LaunchGame::setGo(bool Go)
{
  this->go = Go;
}

bool		LaunchGame::getOption(void) const
{
  return (this->option_);
}

void		LaunchGame::setOption(bool opt)
{
  this->option_ = opt;
}

bool		LaunchGame::getCredits(void) const
{
  return (this->credits_);
}

void		LaunchGame::setCredits(bool credi)
{
  this->credits_ = credi;
}

void		LaunchGame::credits(void)
{
  this->credits_ = true;
  ((MyGame *)(this->ptr))->getAudio().stopMusicSound();
  ((MyGame *)(this->ptr))->getAudio().startCreditsSound();

}

void		LaunchGame::newGame(void)
{
  this->option_ = true;
  ((MyGame *)(this->ptr))->option.setGo(true);
}

void		LaunchGame::exitChoice(void)
{
  throw End("Game is Over !");
}

void		LaunchGame::option(void)
{
  this->option_ = true;
}

void		LaunchGame::loadGame(void)
{
  this->setGo(true);
  ((MyGame *)(this->ptr))->load.setGo(false);
}

void		LaunchGame::initStruct(void)
{
  choicePos	xy;

  xy.x = 20;
  xy.y = 120;
  while (this->posabsolue != NBCHOICE)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->posabsolue = 0;
  this->choose[0] = &LaunchGame::newGame;
  this->choose[1] = &LaunchGame::loadGame;
  this->choose[2] = &LaunchGame::option;
  this->choose[3] = &LaunchGame::credits;
  this->choose[4] = &LaunchGame::exitChoice;
}

void		LaunchGame::isTouch(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text.writeItem(-this->xpos - 500, -this->ypos + 400, 70, 70, text.getBomb());
  this->camera_.view(0, 0, 1000);
  this->text.write("NEW GAME", 60, 100, 140, color);
  this->text.write("LOAD GAME", 60, 100, 220, color);
  this->text.write("OPTIONS", 60, 100, 300, color);
  this->text.write("CREDITS", 60, 100, 380, color);
  this->text.write("EXIT", 60, 100, 460, color);
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBCHOICE - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBCHOICE)
        this->posabsolue = 0;
      else
        ++this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      if (this->choose[this->posabsolue])
	(this->*(choose[this->posabsolue]))();
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("See you !");
  usleep(50000);
}
