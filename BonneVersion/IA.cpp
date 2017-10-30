#include "MyGame.hpp"
#include <cstdlib>
#include "Character.hpp"

void	*IAretardBomb(void *i)
{
  MyGame	*tmp = ((stockIA *)i)->t;
  Bomb		*bomb = ((stockIA *)i)->bomb;
  int		nP =  ((stockIA *)i)->perso;

  while (tmp->pauseGame != false);
  sleep(1);
  while (tmp->pauseGame != false);
  sleep(1);
  while (tmp->pauseGame != false);
  if (tmp->getlistPlayer()[nP] != NULL)
    {
      pthread_mutex_lock(&(tmp->m_prod));
      if (tmp->getlistPlayer()[nP]->getNbVies() > 0)
	{
	  if (tmp->son == true)
	    tmp->getAudio().startBombSound();
	}
      bomb->setTest(true);
      pthread_mutex_unlock(&(tmp->m_prod));
      sleep(1);
      bomb->setToken(true);
      bomb->setTest(false);
    }
  delete (stockIA *)i;
  pthread_exit(0);
  return (NULL);
}

void	MyGame::randMoves()
{
  int		a = 0;

  for (int i = (this->mode == DUEL) ? 3 : 2; this->listPlayer[i] != NULL; ++i)
    {
      if (checkBomby(i) == false)
	{
	  a = std::rand() % 98;
	  if (this->IAfunc[a] != NULL && pauseGame != true)
	    (this->*IAfunc[a])(i);
	}
    }
}

bool	MyGame::checkBomby(int i)
{
  for (int j = 1; this->listPlayer[j] != NULL; ++j)
    {
      for (std::queue<Bomb *> tmp = this->listPlayer[j]->getListBomb(); tmp.empty() != true; tmp.pop())
	{
	  if (getlistPlayer()[i]->getPosX() == tmp.front()->getX())
	    {	  
	      if (checkwall(getlistPlayer()[i]->getPosX() - 1, getlistPlayer()[i]->getPosY()) == true)
		IALeft(i);
	      else
		IARight(i);
	      return (true);
	    }	 
	  else if (getlistPlayer()[i]->getPosY() == tmp.front()->getY())
	    {	  
	      if (checkwall(getlistPlayer()[i]->getPosX(), getlistPlayer()[i]->getPosY() - 1) == true)
		IAUp(i);
	      else
		IADown(i);
	      return (true);
	    }
	}
    }
  return (false);
}

void	MyGame::IAUp(int i)
{
  if (checkwall(getlistPlayer()[i]->getPosX(), getlistPlayer()[i]->getPosY() - 1) == true && checkBomb(getlistPlayer()[i]->getPosX(), getlistPlayer()[i]->getPosY() - 1) == true)
    {
      getlistPlayer()[i]->setPosY((getlistPlayer()[i]->getPosY() - 1));
      getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
      getlistPlayer()[i]->marvin.rotation_.z = 10;
      getlistPlayer()[i]->marvin.position_.y -= 1;
    }
}

void	MyGame::IADown(int i)
{
  if (checkwall(getlistPlayer()[i]->getPosX(), getlistPlayer()[i]->getPosY() + 1) == true && checkBomb(getlistPlayer()[i]->getPosX(), getlistPlayer()[i]->getPosY() + 1) == true)
    {
      getlistPlayer()[i]->setPosY((getlistPlayer()[i]->getPosY() + 1));
      getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);  
      getlistPlayer()[i]->marvin.position_.y += 1;
      getlistPlayer()[i]->marvin.rotation_.z = 0;
    }
}

void	MyGame::IALeft(int i)
{
  if (checkwall(getlistPlayer()[i]->getPosX() - 1, getlistPlayer()[i]->getPosY()) == true && checkBomb(getlistPlayer()[i]->getPosX() - 1, getlistPlayer()[i]->getPosY()) == true)
    {
      getlistPlayer()[i]->setPosX((getlistPlayer()[i]->getPosX() - 1));
      getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
      getlistPlayer()[i]->marvin.position_.x -= 1;
      getlistPlayer()[i]->marvin.rotation_.z = -1;
    }
}

void	MyGame::IARight(int i)
{
  if (checkwall(getlistPlayer()[i]->getPosX() + 1, getlistPlayer()[i]->getPosY()) == true && checkBomb(getlistPlayer()[i]->getPosX() + 1, getlistPlayer()[i]->getPosY()) == true)
    {
      getlistPlayer()[i]->setPosX((getlistPlayer()[i]->getPosX() + 1));
      getlistPlayer()[i]->marvin.position_.x += 1;
      getlistPlayer()[i]->marvin.rotation_.z = 1;
      getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
    }
}

void	MyGame::IABomb(int i)
{
  pthread_t	tmp = getPthread();

  if (getlistPlayer()[i]->getNbVies() > 0)
    if (getlistPlayer()[i]->getNbBomb() > 0)
      {
	stockIA		*temp = new stockIA;
	setPlayer(i);
	getlistPlayer()[i]->setNbBomb(getlistPlayer()[i]->getNbBomb() - 1);


	temp->perso = i;
	temp->t = this;
	temp->bomb = this->getlistPlayer()[i]->addBomb(this->getlistPlayer()[i]->getPosX(), this->getlistPlayer()[i]->getPosY());
	pthread_create(&tmp, NULL, IAretardBomb, temp);
      }
}
