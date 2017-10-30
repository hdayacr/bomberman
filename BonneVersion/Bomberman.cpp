#include "Bomberman.hpp"

Bomberman::Bomberman()
{
  std::srand(unsigned (std::time(NULL)));
  this->bonus_.initialize();
  this->Item[0] = this->bonus_.getHeart();
  this->Item[1] = this->bonus_.getBomb();
  this->Item[2] = this->bonus_.getShoe();
  this->Item[3] = this->bonus_.getFlame();
}

Bomberman::~Bomberman()
{
}

int	Bomberman::getXMap(void) const
{
  return (this->xMap);
}

int	Bomberman::getYMap(void) const
{
  return (this->yMap);
}

std::map<int, Character*>	Bomberman::getlistPlayer(void) const
{
  return this->listPlayer;
}

int	Bomberman::getRandomItem(void)
{
  return std::rand() % 4;
}

void	Bomberman::takeOffFakeWall(int x, int y)
{
  for (std::list<t_pos>::iterator it = this->listFakeWall.begin(); it != this->listFakeWall.end(); ++it)
    if ((*it).x == x && (*it).y == y)
	it = listFakeWall.erase(it);
}

void	Bomberman::createPlayer(int x, int y, std::string &name, int nb, int color)
{
  Character	*player = new Character;

  player->setPosX(x);
  player->setPosY(y);
  player->setName(name);
  player->setNbPlayer(nb);
  player->link = this;
  player->marvin.setColor(color);
  player->marvin.position_.x = x;
  player->marvin.position_.y = y;
  takeOffFakeWall(x, y);
  takeOffFakeWall(x + 1, y);
  takeOffFakeWall(x - 1, y);
  takeOffFakeWall(x, y + 1);
  takeOffFakeWall(x, y - 1);
  this->listPlayer[nb] = player;
}

void	Bomberman::demolitionWall(int x, int y, Bomb *)
{
  for (std::list<t_pos>::iterator it = this->listFakeWall.begin(); it != this->listFakeWall.end(); ++it)
    if ((*it).x == x && (*it).y == y)
      {
	this->stockPosInlistBonus((*it).x, (*it).y, this->getRandomItem());
	it = listFakeWall.erase(it);
      }
}

void		Bomberman::death(int x, int y)
{
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getPosX() == x &&
      	  this->listPlayer[i]->getPosY() == y)
	if (this->listPlayer[i]->getShield() == false)
	  {
	    this->listPlayer[i]->stateOfGrace();
	      this->listPlayer[i]->setNbVies(this->listPlayer[i]->getNbVies() - 1);
	    if (this->listPlayer[i]->getNbVies() == 0)
	      {
		this->listPlayer[i]->setPosX(this->xMap + CERCUEIL);
		this->listPlayer[i]->setPosY(this->yMap);
	      }
	  }
    }
}

void		Bomberman::stockPosInList(int x, int y)
{
  t_pos		tmp;

  tmp.x = x;
  tmp.y = y;
  this->listMur.push_back(tmp);
}

void		Bomberman::stockPosInlistFakeWall(int x, int y)
{
  t_pos		tmp;

  tmp.x = x;
  tmp.y = y;
  this->listFakeWall.push_back(tmp);
}

void		Bomberman::stockPosInlistBonus(int x, int y, int item)
{
  t_posBonus	tmp;
  int		i;

  i = std::rand() % 4;
  if (i == 2)
    {
      tmp.x = x;
      tmp.y = y;
      tmp.nbItem = item;
      tmp.item = this->Item[item];
      this->listBonus.push_back(tmp);
    }
}

void		Bomberman::addMapByFile(char const * const fileName)
{
  std::ifstream argfile(fileName);
  std::string	tmp;
  int		x = 0, y = 0, i = 0;

  this->listMur.clear();
  this->listFakeWall.clear();
  this->listBonus.clear();
  if (argfile)
    {
      while (std::getline(argfile, tmp))
	{
	  if (tmp.find("##"))
	    x = 0;
	  for (i = 0; tmp[i] ; ++i)
	    {
	      if (tmp[i] == 'X')
		this->stockPosInList(x, y);
	      if (tmp[i] == 'x')
		this->stockPosInlistFakeWall(x, y);
	      if (tmp[i] != '\n' && tmp[i] != '#')
		++x;
	    }
	  if (tmp.find("##"))
	    ++y;
	}
      this->xMap = x;
      this->yMap = y;
    }
  else
    throw End("File doesnt exist.");
}

void		*moveBombX(void *i)
{
  pushBomb	*tmp = (pushBomb *)i;
  Bomberman	*t = tmp->ptr;
  int		nb = t->getlistPlayer()[tmp->p]->getShoe();
  t->getlistPlayer()[tmp->p]->setShoe(0);
  int		n = 0;

  for (int j = 0; j < nb; ++j)
    {
      if (t->checkwall(t->getlistPlayer()[tmp->p]->getListBomb().front()->getX() + tmp->xB, t->getlistPlayer()[tmp->p]->getListBomb().front()->getY()) == true)
	{
	  t->getlistPlayer()[tmp->p]->getListBomb().front()->setX(t->getlistPlayer()[tmp->p]->getListBomb().front()->getX() + tmp->xB);
	  ++n;
	}
      usleep(5000);
    }
  t->getlistPlayer()[tmp->p]->setShoe(nb - n);
  delete (pushBomb *)i;
  pthread_exit(0);
}

void		*moveBombY(void *i)
{
  pushBomb	*tmp = (pushBomb *)i;
  Bomberman	*t = tmp->ptr;
  int		nb = t->getlistPlayer()[tmp->p]->getShoe();
  t->getlistPlayer()[tmp->p]->setShoe(0);
  int		n = 0;

  for (int j = 0; j < nb; ++j)
    {
      if (t->checkwall(t->getlistPlayer()[tmp->p]->getListBomb().front()->getX(), t->getlistPlayer()[tmp->p]->getListBomb().front()->getY() + tmp->yB) == true)
	{
	  t->getlistPlayer()[tmp->p]->getListBomb().front()->setY(t->getlistPlayer()[tmp->p]->getListBomb().front()->getY() + tmp->yB);
	  ++n;
	}
      usleep(5000);
    }
  t->getlistPlayer()[tmp->p]->setShoe(nb - n);
  delete (pushBomb *)i;
  pthread_exit(0);
}

bool		Bomberman::checkBomb(int x, int y)
{
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      for (std::queue<Bomb *> tmp = this->listPlayer[i]->getListBomb(); tmp.empty() != true; tmp.pop())
	{
	  if (x == tmp.front()->getX() &&
	      y == tmp.front()->getY())
	    {
	      if (this->listPlayer[i]->getShoe() > 0)
		{
		  int xB;
		  int yB;

		  xB = x - this->listPlayer[i]->getPosX();
		  yB = y - this->listPlayer[i]->getPosY();
		  if (xB != 0)
		    {
		      pthread_t		moveX;
		      pushBomb		*tbombX = new pushBomb;

		      tbombX->x = x;
		      tbombX->y = y;
		      tbombX->p = i;
		      tbombX->xB = xB;
		      tbombX->yB = yB;
		      tbombX->ptr = this;
		      pthread_create(&moveX, NULL, moveBombX, tbombX);
		     
		      return (false);
		    }
		  else
		    {
		      pthread_t		moveY;
		      pushBomb		*tbombY = new pushBomb;

		      tbombY->x = x;
		      tbombY->y = y;
		      tbombY->p = i;
		      tbombY->xB = xB;
		      tbombY->yB = yB;
		      tbombY->ptr = this;
		      pthread_create(&moveY, NULL, moveBombY, tbombY);

		      return (false);
		    }
		  return (true);
		}
	      else
		return (false);
	    }	    
	}
    }
  return (true);
}


bool		Bomberman::checkTrueWall(int x, int y)
{
  for (std::list<t_pos>::iterator it = this->listMur.begin(); it != this->listMur.end(); ++it)
    {
      if (x == (*it).x && y == (*it).y)
	return (false);
      if (x < 0 || y < 0)
	return (false);
      if (x > this->xMap - 1 || y > this->yMap - 1) 
	return (false);
    }
  return (true);
}

bool		Bomberman::checkFakeWall(int x, int y)
{
  for (std::list<t_pos>::iterator it = this->listFakeWall.begin(); it != this->listFakeWall.end(); ++it)
    {
      if (x == (*it).x && y == (*it).y)
	return (false);
      if (x < 0 || y < 0)
	return (false);
      if (x > this->xMap - 1 || y > this->yMap - 1) 
	return (false);
    }
  return (true);
}

bool		Bomberman::checkwall(int x, int y)
{
  for (std::list<t_pos>::iterator it = this->listFakeWall.begin(); it != this->listFakeWall.end(); ++it)
    {
      if (x == (*it).x && y == (*it).y)
	return (false);
      if (x < 0 || y < 0)
	return (false);
      if (x > this->xMap - 1 || y > this->yMap - 1) 
	return (false);
    }
  if (this->checkBomb(x, y) == false)
    return (false);
  return (checkTrueWall(x, y));
}
