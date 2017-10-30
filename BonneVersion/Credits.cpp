#include	"MyGame.hpp"
#include	"Credits.hpp"

Credits::Credits()
{
  this->go = false;
  this->credits_ = false;
  this->posabsolue = 0;
  this->creditsFace = 2 * 50;
  this->initStruct();
  this->text.initialize();
  this->color = gdl::Color(255, 102, 0);
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

  this->x = -1000;
  this->x2 = -1400;
  this->x3 = -1800;
  this->x4 = -2200;
  this->x5 = -2600;
  this->x6 = -3000;
}

Credits::~Credits()
{

}

bool		Credits::getGo(void) const
{
  return (this->go);
}

void		Credits::setGo(bool Go)
{
  this->go = Go;
}

bool		Credits::getCredits(void) const
{
  return (this->credits_);
}

void		Credits::setCredits(bool perso)
{
  this->credits_ = perso;
}

void		Credits::theChoice(void)
{
  usleep(50);
  this->text.writeItem(this->x, 300, 300, 300, this->avatarPerso[0]);
  usleep(50);
  this->text.writeItem(this->x2, 300, 300, 300, this->avatarPerso[1]);
  usleep(50);
  this->text.writeItem(this->x3, 300, 300, 300, this->avatarPerso[2]);
  usleep(50);
  this->text.writeItem(this->x4, 300, 300, 300, this->avatarPerso[3]);
  usleep(50);
  this->text.writeItem(this->x5, 300, 300, 300, this->avatarPerso[4]);
  usleep(50);
  this->text.writeItem(this->x6, 300, 300, 300, this->avatarPerso[5]);
  usleep(50);
  this->text.write("Moutau_a", 20, this->x +500, 410, color);
  usleep(50);
  this->text.write("Lebon_j", 20, this->x2 +500, 410, color);
  usleep(50);
  this->text.write("Hdayac_r", 20, this->x3+500, 410, color);
  usleep(50);
  this->text.write("Osika_a", 20, this->x4+500, 410, color);
  usleep(50);
  this->text.write("Lebacq_l", 20, this->x5+500, 410, color);
  usleep(50);
  this->text.write("Tourre_n", 20, this->x6+500, 410, color);
  usleep(50);

  this->x = (x > 1100) ?  x6 - 400 :  (this->x + 10);
  this->x2 = (x2 > 1100) ? x - 400 :  (this->x2 + 10);
  this->x3 = (x3 > 1100) ? x2 - 400 :  (this->x3 + 10);
  this->x4 = (x4 > 1100) ? x3 - 400 :  (this->x4 + 10);
  this->x5 = (x5 > 1100) ? x4 - 400 :  (this->x5 + 10);
  this->x6 = (x6 > 1100) ? x5 - 400 :  (this->x6 + 10);

  this->text.write("This game was created by ...", 30, 100, 80, color);
  this->text.write("No robots was hurted during this project", 18, 100, 755, color);
  this->text.write("Popop and co", 10, 690, 790, color);
}

void		Credits::initStruct(void)
{
  credits	xy;

  xy.x = 20;
  xy.y = 120;
  while (this->posabsolue != NBCREDITS)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->pos[this->posabsolue].x = xy.x;
  this->pos[this->posabsolue].y = xy.y + 200;
  this->posabsolue = 0;
  this->choose[0] = &Credits::theChoice;
}

void		Credits::isTouch(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  this->camera_.view(0, 0, 1000);
  if (this->choose[this->posabsolue])
    (this->*(choose[this->posabsolue]))();
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBCREDITS - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBCREDITS)
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
      this->setCredits(false);
      ((LaunchGame *)prev)->setCredits(false);
      ((MyGame *)(this->ptr))->getAudio().stopCreditsSound();
    }
  usleep(50000);
}
