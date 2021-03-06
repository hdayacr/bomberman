#ifndef CHARACTER_HPP_
# define CHARACTER_HPP_

# include "Pos.hpp"
# include "Bomb.hpp"
# include "Anim.hpp"

# include <queue>

class	Character
{
public:
  Character(int = 0, int = 0,const std::string  = "unknown", int = 3, int = 1);
  Character(Character const &other);
  Character&		operator=(Character const &other);
  virtual		~Character();
  int			getPosX() const;
  int			getPosY() const;
  int			getNbPlayer(void) const;
  std::string		getName(void) const;
  int			getNbVies(void) const;
  std::queue<Bomb *>	getListBomb(void) const;
  int			getNbBomb(void) const;
  bool			getShield(void) const;
  int			getNBomb(void) const;
  int			getExplo(void) const;
  int			getShoe(void) const;
  void			setPosX(int);
  void			setPosY(int);
  void			setName(std::string &);
  void			setNbPlayer(int);
  void			setNbVies(int);
  void			setNbBomb(int);
  void			setNBomb(int);
  void			setShield(bool);
  void			setExplo(int);
  void			setShoe(int);
  void			affichePosition(int, int);
  Bomb			*addBomb(int, int);
  void			eraseBomb(void);
  void			fillBomb(void);
  void			addExplo(void);
  void			stateOfGrace(void);
  void			resetPlayer(void);
  void			*link;
  Anim		        marvin;
protected:
  int			_x;
  int			_y;
  std::string		_name;
  int			_nbVies;
  int			_nbBomb;
  int			_nbPlayer;
  int			_explo;
  int			_shoe;
  int			nBomb;
  pthread_t		_shield;
  std::queue<Bomb *>	listBomb;
  bool			shield;
};

#endif // !CHARACTER_HPP_
