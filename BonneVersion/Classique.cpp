#include "Classique.hpp"
#include "MyGame.hpp"
#include <sstream>

Classique::Classique()
{
  this->posabsolue = 0;
  initStruct();
  this->go = true;
  this->color = gdl::Color(255, 200, 214);
  this->text.initialize();
  this->longueur = 10;
  this->largeur = 10;
}

Classique::~Classique()
{

}

bool Classique::getGo(void)const
{
  return this->go;
}

void Classique::setGo(bool Go)
{
  this->go = Go;
}

int Classique::getLongueur()const
{
  return this->longueur;
}

int Classique::getLargeur()const
{
  return this->largeur;
}

void Classique::changeClassique()
{
  std::ofstream fichier("./map/Classique", std::ios::out | std::ios::trunc);  
  if (fichier)
    {
      for(int i = 0; i <= this->largeur; ++i)
	fichier << "#" ;
      fichier << std::endl;
      for (int y = 0; y <= longueur; ++y)
	{
	  fichier << "#";
	  if (y % 2 == 0)
	    for (int x = 0; x <= largeur; ++x)
	      fichier << "x";
	  else
	    for (int x = 0; x <= largeur; ++x)
	      {
		if (x % 2 == 0)
		  fichier << "x";
		else
		  fichier << "X";
	      }
	  fichier << "#" << std::endl;
	}
      for(int i = 0; i <= this->largeur; ++i)
	fichier << "#" ;
    }
  else
    std::cerr << "Impossible to save!" << std::endl;
}


void Classique::goPlay()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Return)) == true)
    {
      ((MyGame *)(this->ptr))->menu.setGo(true);
      this->go = true;
      this->changeClassique();
      ((MyGame *)(this->ptr))->reStart();
    }
}

void Classique::goLargeur()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      this->largeur += 10;
      if (this->largeur > 500)
	this->largeur = 10;    
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      this->largeur -= 10;
      if (this->largeur < 10)
	this->largeur = 500;
    }
}

void Classique::goLongueur()
{
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Right)) == true)
    {
      this->longueur += 10;
      if (this->longueur > 500)
	this->longueur = 10;    
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Left)) == true)
    {
      this->longueur -= 10;
      if (this->longueur < 10)
	this->longueur = 500;
    }
}

void		Classique::initStruct(void)
{
  t_pos	xy;

  xy.x = 20;
  xy.y = 120;
  while (this->posabsolue != NBXY - 1)
    {
      this->pos[this->posabsolue].x = xy.x;
      this->pos[this->posabsolue].y = xy.y;
      xy.y += 80;
      ++this->posabsolue;
    }
  this->pos[this->posabsolue].x = xy.x;
  this->pos[this->posabsolue].y = xy.y;
  this->posabsolue = 0;
  this->choose[0] = &Classique::goLongueur;
  this->choose[1] = &Classique::goLargeur;
  this->choose[2] = &Classique::goPlay;
}

void		Classique::isTouch(void)
{
  this->xpos = this->pos[this->posabsolue].x;
  this->ypos = this->pos[this->posabsolue].y;
  this->camera_.view(0, 0, 600);
  text.writeItem(-this->xpos - 500, -this->ypos + 275, 60, 60, text.getBomb()); 
  this->camera_.view(0, 0, 1000);
  this->text.write("SIZE MAP", 45, 100, 180, color);
  this->text.write("HEIGHT", 45, 100, 260, color);
  this->text.write("WIDTH", 45, 100, 340, color);
  this->text.write("PLAY", 40, 100, 420, color);
  if (this->choose[this->posabsolue])
    (this->*(choose[this->posabsolue]))();
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Up)) == true)
    {
      if (this->posabsolue - 1 < 0)
        this->posabsolue = NBXY - 1;
      else
        --this->posabsolue;
    }
  if ((((MyGame *)(this->ptr))->
       getInput_().isKeyDown(gdl::Keys::Down)) == true)
    {
      if (this->posabsolue + 1 == NBXY)
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

    }
  std::ostringstream oss;
  oss << this->longueur;
  std::string result = oss.str();
  this->text.write(result, 30, this->xpos + 550 + 0, 260, color);
  this->text.write("<", 45, this->xpos + 520, 260, color);
  this->text.write(">", 45, this->xpos + 630, 260, color);
  std::ostringstream os;
  os << this->largeur;
  std::string res = os.str();
  this->text.write(res, 30, this->xpos + 550 + 0, 350, color);
  this->text.write("<", 45, this->xpos + 520, 350, color);
  this->text.write(">", 45, this->xpos + 630, 350, color);
  usleep(50000);
}
