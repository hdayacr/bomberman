#include <iostream>
#include "Character.hpp"

Character::Character(int x, int y, std::string name, int nbVies, int nbBomb)
{
  this->_x = x;
  this->_y = y;
  this->_name = name;
  this->_nbVies = nbVies;
  this->_nbBomb = nbBomb;
  this->nBomb = nbBomb;
  this->_explo = 3;
  this->_shoe = 0;
  this->marvin.initialize();
}

Character::Character(Character const &other)
{
  this->_x = other._x;
  this->_y = other._y;
  this->_name = other._name;
  this->_nbVies = other._nbVies;
  this->_nbBomb = other._nbBomb;
  this->nBomb = other._nbBomb;
}

Character&	Character::operator=(Character const &other)
{
  if (this != &other)
    {
      this->_x = other._x;
      this->_y = other._y;
      this->_name = other._name;
      this->_nbVies = other._nbVies;
      this->_nbBomb = other._nbBomb;
      this->nBomb = other._nbBomb;
    }
  return *this;
}

int		Character::getPosX() const
{
  return this->_x;
}

int		Character::getPosY() const
{
  return this->_y;
}

int		Character::getNbPlayer() const
{
  return this->_nbPlayer;
}

std::string	Character::getName() const
{
  return this->_name;
}

int		Character::getNbVies() const
{
  return this->_nbVies;
}

int		Character::getNbBomb(void) const
{
  return this->_nbBomb;
}

std::queue<Bomb *>	Character::getListBomb(void) const
{
  return this->listBomb;
}

bool		Character::getShield(void) const
{
  return this->shield;
}

int		Character::getNBomb(void) const
{
  return this->nBomb;
}

int		Character::getExplo(void) const
{
  return this->_explo;
}


int		Character::getShoe(void) const
{
  return this->_shoe;
}

void		Character::setPosX(int x)
{
  this->_x = x;
}

void		Character::setPosY(int y)
{
  this->_y = y;
}

void		Character::setName(std::string &name)
{
  this->_name = name;
}

void		Character::setNbPlayer(int nb)
{
  this->_nbPlayer = nb;
}

void		Character::setNbVies(int vies)
{
  this->_nbVies = vies;
}

void		Character::setNbBomb(int nb)
{
  this->_nbBomb = nb;
}

void		Character::setShield(bool shield)
{
  this->shield = shield;
}

void		Character::setNBomb(int nb)
{
  this->nBomb = nb;
}

void		Character::setShoe(int shoe)
{
  this->_shoe = shoe;
}

void		Character::fillBomb(void)
{
  this->_nbBomb = this->nBomb;
}

void		Character::setExplo(int explo)
{
  this->_explo = explo;
}

Bomb		*Character::addBomb(int x_, int y_)
{
  Bomb		*nwBomb = new Bomb;

  nwBomb->setX(x_);
  nwBomb->setY(y_);
  nwBomb->setExpl(false);
  this->listBomb.push(nwBomb);
  return (nwBomb);
}

void		Character::addExplo(void)
{
}

void		Character::eraseBomb(void)
{
  this->listBomb.pop();
}

static void	*activeShield(void *i)
{
  Character	*tmp = (Character *)i;

  sleep(2);
  tmp->setShield(false);
  pthread_exit(0);
}

void		Character::stateOfGrace(void)
{
  this->setShield(true);
  pthread_create(&this->_shield, NULL, activeShield, this);
}

void		Character::resetPlayer(void)
{
  for (; this->listBomb.empty() != true; this->listBomb.pop());
}

void		Character::affichePosition(int x, int y)
{
  std::cout << "Position du Joueur : " << std::endl << " x [" << x << "] y [" << y << "]" << std::endl;
}

Character::~Character()
{
}