#include "Touch.hpp"

# include "Anim.hpp"

Touch::Touch()
{
  this->functionTouch[gdl::Keys::Escape] = &Touch::doEscape;
  this->functionTouch[gdl::Keys::Back] = &Touch::doBack;
  this->functionTouch[gdl::Keys::A] = &Touch::doS;
  this->functionTouch[gdl::Keys::P] = &Touch::doPause;
  // Joueur 1
  this->functionTouch[gdl::Keys::Up] = &Touch::doUp;
  this->functionTouch[gdl::Keys::Down] = &Touch::doDown;
  this->functionTouch[gdl::Keys::Left] = &Touch::doLeft;
  this->functionTouch[gdl::Keys::Right] = &Touch::doRight;
  this->functionTouch[gdl::Keys::RShift] = &Touch::doRShift;
  // Joueur 2
  this->functionTouch[gdl::Keys::Z] = &Touch::doZup;
  this->functionTouch[gdl::Keys::S] = &Touch::doSdown;
  this->functionTouch[gdl::Keys::Q] = &Touch::doQleft;
  this->functionTouch[gdl::Keys::D] = &Touch::doDright;
  this->functionTouch[gdl::Keys::Space] = &Touch::doSpace;

  this->i = 1;
  this->j = 2;
}

Touch::~Touch()
{

}

void	*retardBomb(void *i)
{
  MyGame	*tmp = ((stockPerso *)i)->t;
  Bomb		*bomb = ((stockPerso *)i)->bomb;
  int		nP =  ((stockPerso *)i)->perso;

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
  delete (stockPerso *)i;
  pthread_exit(0);
  return (NULL);
}

void		Touch::catchTouch(gdl::Keys::Key k, MyGame *t)
{
  if (t->mode == SOLO)
    this->j = 1;
  if (this->functionTouch[k] != NULL && t->pauseGame != true)
    (this->*(functionTouch[k]))(t);
}

void		Touch::doEscape(MyGame *)
{
  throw End("Game is Over");
}

void            Touch::doPause(MyGame *tmp)
{
  tmp->pauseGame = true;
  tmp->pausegame.setGo(false);
  usleep(500);
}

void		Touch::doS(MyGame *t)
{
  t->saveGame();
}

void		Touch::doBack(MyGame *t)
{
  t->menu.setGo(false);
  t->goForPerso.setGo(false);
  t->option.setGo(false);
  t->option.setOption(false);
  t->launchgame.setGo(false);
  t->launchgame.setOption(false);
  t->launchgame.setGo(false);
  t->cleanListPerso();
}

void		Touch::doUp(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[i]->getPosX(), t->getlistPlayer()[i]->getPosY() - 1) == true)
    {
      t->getlistPlayer()[i]->setPosY((t->getlistPlayer()[i]->getPosY() - 1));
      t->getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
      t->getlistPlayer()[i]->marvin.rotation_.z = 10;
      t->getlistPlayer()[i]->marvin.position_.y -= 1;
    }
}

void		Touch::doDown(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[i]->getPosX(), t->getlistPlayer()[i]->getPosY() + 1) == true)
    {
      t->getlistPlayer()[i]->setPosY((t->getlistPlayer()[i]->getPosY() + 1));
      t->getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);  
      t->getlistPlayer()[i]->marvin.position_.y += 1;
      t->getlistPlayer()[i]->marvin.rotation_.z = 0;
    }
}

void		Touch::doLeft(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[i]->getPosX() - 1, t->getlistPlayer()[i]->getPosY()) == true)
    {
      t->getlistPlayer()[i]->setPosX((t->getlistPlayer()[i]->getPosX() - 1));
      t->getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
      t->getlistPlayer()[i]->marvin.position_.x -= 1;
      t->getlistPlayer()[i]->marvin.rotation_.z = -1;
    }
}

void		Touch::doRight(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[i]->getPosX() + 1, t->getlistPlayer()[i]->getPosY()) == true)
    {
      t->getlistPlayer()[i]->setPosX((t->getlistPlayer()[i]->getPosX() + 1));
       t->getlistPlayer()[i]->marvin.position_.x += 1;
       t->getlistPlayer()[i]->marvin.rotation_.z = 1;
       t->getlistPlayer()[i]->marvin.model_.play("RUN", gdl::Anim::RUN);
    }
}

void		Touch::doRShift(MyGame *t)
{
  pthread_t	tmp = t->getPthread();

  if (t->getlistPlayer()[i]->getNbVies() > 0)
    if (t->getlistPlayer()[i]->getNbBomb() > 0)
      {
	stockPerso		*temp = new stockPerso;

	t->setPlayer(i);
	t->getlistPlayer()[i]->setNbBomb(t->getlistPlayer()[i]->getNbBomb() - 1);
	temp->perso = i;
	temp->t = t;
	temp->bomb = t->getlistPlayer()[i]->addBomb(t->getlistPlayer()[i]->getPosX(), t->getlistPlayer()[i]->getPosY());
	pthread_create(&tmp, NULL, retardBomb, temp);
      }
}

void		Touch::doZup(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[j]->getPosX(), t->getlistPlayer()[j]->getPosY() - 1) == true)
    {
      t->getlistPlayer()[j]->setPosY((t->getlistPlayer()[j]->getPosY() - 1));
      t->getlistPlayer()[j]->marvin.model_.play("RUN", gdl::Anim::RUN);
      t->getlistPlayer()[j]->marvin.rotation_.z = 10;
      t->getlistPlayer()[j]->marvin.position_.y -= 1;
    }
}

void		Touch::doSdown(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[j]->getPosX(), t->getlistPlayer()[j]->getPosY() + 1) == true)
    {
      t->getlistPlayer()[j]->setPosY((t->getlistPlayer()[j]->getPosY() + 1));
      t->getlistPlayer()[j]->marvin.model_.play("RUN", gdl::Anim::RUN);  
      t->getlistPlayer()[j]->marvin.position_.y += 1;
      t->getlistPlayer()[j]->marvin.rotation_.z = 0;
    }
}

void		Touch::doQleft(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[j]->getPosX() - 1, t->getlistPlayer()[j]->getPosY()) == true)
    {
      t->getlistPlayer()[j]->setPosX((t->getlistPlayer()[j]->getPosX() - 1));
      t->getlistPlayer()[j]->marvin.model_.play("RUN", gdl::Anim::RUN);
      t->getlistPlayer()[j]->marvin.position_.x -= 1;
      t->getlistPlayer()[j]->marvin.rotation_.z = -1;
    }
}

void		Touch::doDright(MyGame *t)
{
  if (t->checkwall(t->getlistPlayer()[j]->getPosX() + 1, t->getlistPlayer()[j]->getPosY()) == true)
    {
      t->getlistPlayer()[j]->setPosX((t->getlistPlayer()[j]->getPosX() + 1));
      t->getlistPlayer()[j]->marvin.model_.play("RUN", gdl::Anim::RUN);
      t->getlistPlayer()[j]->marvin.position_.x += 1;
      t->getlistPlayer()[j]->marvin.rotation_.z = 1;
    }
}

void		Touch::doSpace(MyGame *t)
{
  pthread_t	tmp = t->getPthread();

  if (t->getlistPlayer()[j]->getNbVies() > 0)
    if (t->getlistPlayer()[j]->getNbBomb() > 0)
      {
	stockPerso		*temp = new stockPerso;

	t->setPlayer(j);
	t->getlistPlayer()[j]->setNbBomb(t->getlistPlayer()[j]->getNbBomb() - 1);
	temp->perso = j;
	temp->t = t;
	temp->bomb = t->getlistPlayer()[j]->addBomb(t->getlistPlayer()[j]->getPosX(), t->getlistPlayer()[j]->getPosY());
	pthread_create(&tmp, NULL, retardBomb, temp);
      }
}