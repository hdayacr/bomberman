#include	"MyGame.hpp"
#include	"GoPerso.hpp"
#include	<sstream>

GoPerso::GoPerso()
{
  this->go = false;
  this->goPerso_ = false;
  this->posabsolue = 0;
  this->chooseYourFace = 2 * 50;
  this->chooseYourFace2 = 4 * 50;
  this->initStruct();
  this->text.initialize();
  this->namePerso[0] = "Moutau";
  this->namePerso[1] = "Jeromin";
  this->namePerso[2] = "Raff";
  this->namePerso[3] = "Osika";
  this->namePerso[4] = "Loic";
  this->namePerso[5] = "Nathan";

  this->avatarPerso[0] = text.getMouto();
  this->avatarPerso[1] = text.getJeromin();
  this->avatarPerso[2] = text.getRaff();
  this->avatarPerso[3] = text.getOsika();
  this->avatarPerso[4] = text.getLoic();
  this->avatarPerso[5] = text.getNathan();

  this->color = gdl::Color(150, 100, 200);
  this->nbBot = 0;
}

GoPerso::~GoPerso()
{

}

bool		GoPerso::getGo(void) const
{
  return (this->go);
}

void		GoPerso::setGo(bool Go)
{
  this->go = Go;
}

bool		GoPerso::getGoPerso(void) const
{
  return (this->goPerso_);
}

void		GoPerso::setGoPerso(bool perso)
{
  this->goPerso_ = perso;
}

void		GoPerso::bot(void)
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      if (this->nbBot - 1 < 0)
        this->nbBot = 0;
      else
        this->nbBot -= 1;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      if (this->nbBot + 1 == 11)
        this->nbBot = 10;
      else
        this->nbBot += 1;
    }
}

void		GoPerso::theChoice(void)
{
  //PLAYER1
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      if (this->chooseYourFace - 1 < 0)
        this->chooseYourFace = 250;
      else
        this->chooseYourFace -= 50;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      if (this->chooseYourFace + 50 == 300)
        this->chooseYourFace = 0;
      else
        this->chooseYourFace += 50;
    }

  //PLAYER2
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::A)) == true)
    {
      if (this->chooseYourFace2 - 1 < 0)
        this->chooseYourFace2 = 250;
      else
        this->chooseYourFace2 -= 50;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::E)) == true)
    {
      if (this->chooseYourFace2 + 50 == 300)
        this->chooseYourFace2 = 0;
      else
        this->chooseYourFace2 += 50;
    }

  this->text.write("^", 45, this->xpos + 400 + this->chooseYourFace, this->ypos + 50, color);
  if (((MyGame *)(this->ptr))->mode == DUEL)
    this->text.write("*", 45, this->xpos + 400 + this->chooseYourFace2, this->ypos + 50, color);
  this->camera_.view(0, 0, 600);
  this->text.writeItem(-5, 350, 75, 75, this->avatarPerso[0]);
  this->text.writeItem(70, 350, 75, 75, this->avatarPerso[1]);
  this->text.writeItem(145, 350, 75, 75, this->avatarPerso[2]);
  this->text.writeItem(220, 350, 75, 75, this->avatarPerso[3]);
  this->text.writeItem(295, 350, 75, 75, this->avatarPerso[4]);
  this->text.writeItem(370, 350, 75, 75, this->avatarPerso[5]);
  this->camera_.view(0, 0, 1000);
}

void		GoPerso::chooseMap(void)
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      this->go = true;
      ((MyGame *)(this->ptr))->pl1 = namePerso[chooseYourFace / 50];
      ((MyGame *)(this->ptr))->pl2 = namePerso[chooseYourFace2 / 50];
      ((MyGame *)(this->ptr))->setPlayer(((MyGame *)(this->ptr))->getPlayer() + nbBot);
    }
}

void		GoPerso::initStruct(void)
{
  choicePerso	xy;

  xy.x = 20;
  xy.y = 120;
  while (this->posabsolue != NBPERSO)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->pos[this->posabsolue].x = xy.x;
  this->pos[this->posabsolue].y = xy.y + 200;
  this->posabsolue = 0;
  this->choose[0] = &GoPerso::theChoice;
  this->choose[1] = &GoPerso::bot;
  this->choose[2] = &GoPerso::chooseMap;
}

static std::string		convertToString(int nb)
{
  std::ostringstream		n;

  n << nb;
  return (n.str());
}

void		GoPerso::isTouch(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text.writeItem(-this->xpos - 495, -this->ypos + 400, 70, 70, text.getBomb());
  this->camera_.view(0, 0, 1000);
  this->text.write("PLAYERS", 45, 100, 140, color);
  this->text.write("BOTS", 45, 100, 220, color);
  this->text.write("CHOOSE YOUR MAP", 45, 100, 300, color);

  if (this->choose[this->posabsolue])
    (this->*(choose[this->posabsolue]))();
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBPERSO - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBPERSO)
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
      ((LaunchGame *)prev)->setOption(false);
      ((MyGame *)(this->ptr))->option.setOption(false);
      ((MyGame *)(this->ptr))->option.setGo(false);
    }

  if (((MyGame *)(this->ptr))->mode == DUEL)
    {
      this->text.write("VS", 50, 300, 500, color);
      this->text.write(namePerso[chooseYourFace2 / 50], 30, this->xpos + 350 + 100, 350, color);
    }
  this->text.write(namePerso[chooseYourFace / 50], 30, this->xpos + 50, 350, color);

  this->text.write(convertToString(nbBot), 30, this->xpos + 400 + 100, 230, color);

  this->text.write("PLAYER 1 : <- / ->", 15, 550, 700, color);
  if (((MyGame *)(this->ptr))->mode == DUEL)
    this->text.write("PLAYER 2 : A / E", 15, 550, 730, color);

  this->camera_.view(0, 0, 600);
  this->text.writeItem(-500, 0, 300, 300, this->avatarPerso[chooseYourFace / 50]);
  if (((MyGame *)(this->ptr))->mode == DUEL)
    this->text.writeItem(50, 0, 300, 300, this->avatarPerso[chooseYourFace2 / 50]);
  this->camera_.view(0, 0, 1000);
  usleep(50000);
}
