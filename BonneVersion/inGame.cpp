#include "inGame.hpp"
#include "MyGame.hpp"

inGame::inGame()
{
  this->go = true;
  this->text.initialize();
  this->posabsolue = 0;
  this->initStruct();
  affichSave = false;
  this->onOffMusic = 0;
  sonTrueOrFalse[true] = 0;
  sonTrueOrFalse[false] = 100;
  this->color = gdl::Color(0, 0, 0);
}

inGame::~inGame()
{

}

bool inGame::getGo()const
{
  return (this->go);
}

void inGame::setGo(bool goo)
{
  this->go = goo;
}

void inGame::rePlay()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      setGo(true);
      affichSave = false;
      ((MyGame *)(this->ptr))->pauseGame = false;
    }
}

void inGame::reStart()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      setGo(true);
      ((MyGame *)(this->ptr))->pauseGame = false;
      ((MyGame *)(this->ptr))->reStart();
    }
}

void	*retardAffich(void *t)
{
  inGame	*tmp = (inGame*)t;

  sleep(2);
  tmp->affichSave = false;
  pthread_exit(0);
}

void inGame::save()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      ((MyGame *)(this->ptr))->saveGame();
      affichSave = true;
      pthread_create(&tAffich, NULL, retardAffich, this);
    }
}

void inGame::isMusic()
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
  if (this->onOffMusic == 100)
    {
      ((MyGame *)(this->ptr))->son = false;
      ((MyGame *)(this->ptr))->getAudio().pauseSound();
    }
  else
    {
      if (((MyGame *)(this->ptr))->son == false)
	((MyGame *)(this->ptr))->getAudio().startMusicSound();
      ((MyGame *)(this->ptr))->son = true;
    }
  this->text.write("on", 30, this->xpos + 550 + 0, 420, color);
  this->text.write("off", 30, this->xpos + 550 + 100, 420, color);
  this->text.write("^", 45, this->xpos + 560 + this->onOffMusic, this->ypos + 155, color);
}

void inGame::exit()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      setGo(true);
      ((MyGame *)(this->ptr))->launchgame.setGo(false);
      ((MyGame *)(this->ptr))->menu.setGo(false);
      ((MyGame *)(this->ptr))->goForPerso.setGo(false);
      ((MyGame *)(this->ptr))->option.setGo(false);
      ((MyGame *)(this->ptr))->option.setOption(false);
      ((MyGame *)(this->ptr))->launchgame.setGo(false);
      ((MyGame *)(this->ptr))->launchgame.setOption(false);
      ((MyGame *)(this->ptr))->pauseGame = false;

    }
}

void inGame::initStruct()
{
  tPos xy;

  xy.x = 20;
  xy.y = 60;
  while (this->posabsolue != NBPAUSE)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->posabsolue = 0;
  this->choose[0] = &inGame::rePlay;
  this->choose[1] = &inGame::reStart;
  this->choose[2] = &inGame::save;
  this->choose[3] = &inGame::isMusic;
  this->choose[4] = &inGame::exit;
}

void inGame::inPause()
{
  this->onOffMusic = sonTrueOrFalse[((MyGame *)(this->ptr))->son];
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  this->text.writeItem(-this->xpos - 500, -this->ypos + 300, 60, 60, text.getBomb());
  this->camera_.view(0, 0, 1000);
  text.write("PAUSE", 50, 25, 10, color);
  this->text.write("CONTINUE", 45, 100, 180, color);
  this->text.write("RESTART", 45, 100, 260, color);
  this->text.write("SAVE", 45, 100, 340, color);
  this->text.write("SOUND", 45, 100, 420, color);
  this->text.write("EXIT", 40, 100, 500, color);
  if (this->choose[this->posabsolue])
    (this->*(choose[this->posabsolue]))();
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBPAUSE - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBPAUSE)
        this->posabsolue = 0;
      else
        ++this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Escape)) == true)
    throw End("See you !");
  if (affichSave == true)
    text.write("Game saved !", 50, 100, 100, color);
  usleep(50000);
}
