#include "MyGame.hpp"
#include "Touch.hpp"

#include <sstream>

void	MyGame::initialize(void)
{
  window_.setTitle("Bomberman");
  window_.setWidth(800);
  window_.setHeight(800);
  window_.create();
  camera_.initialize();
  window_.display();
  std::list<AObject*>::iterator itb = this->objects_.begin();
  for (; itb != this->objects_.end(); ++itb)
    (*itb)->initialize();

  this->listTouch.push_back(gdl::Keys::Escape);
  this->listTouch.push_back(gdl::Keys::Up);
  this->listTouch.push_back(gdl::Keys::Down);
  this->listTouch.push_back(gdl::Keys::Left);
  this->listTouch.push_back(gdl::Keys::Right);
  this->listTouch.push_back(gdl::Keys::RShift);
  this->listTouch.push_back(gdl::Keys::Z);
  this->listTouch.push_back(gdl::Keys::S);
  this->listTouch.push_back(gdl::Keys::Q);
  this->listTouch.push_back(gdl::Keys::D);
  this->listTouch.push_back(gdl::Keys::Space);
  this->listTouch.push_back(gdl::Keys::Back);
  this->listTouch.push_back(gdl::Keys::A);
  this->listTouch.push_back(gdl::Keys::P);

  this->menu.ptr = this;
  this->menu.ptr = this;
  this->intro.ptr = this;
  this->launchgame.ptr = this;
  this->option.ptr = this;
  this->goForPerso.ptr = this;
  this->credit.ptr = this;
  this->pausegame.ptr = this;
  this->classique.ptr = this;
  this->load.ptr = this;
  Touch *tmp = new Touch;

  this->touch = tmp;

  this->wall_ = gdl::Image::load("./image/wall2.jpg");
  this->fake_ = gdl::Image::load("./image/fis.jpg");
  this->fire_ = gdl::Image::load("./image/feu003.jpg");
  this->bomb_ = gdl::Image::load("./image/bomb.jpg");
  this->wallpaper_ = gdl::Image::load("./image/bomberman2.jpg");
  this->contour_ = gdl::Image::load("./image/grass.jpg");
  this->floor_ = gdl::Image::load("./image/floor.jpg");
  this->galaxie_ = gdl::Image::load("./image/galaxie.jpg");
  pthread_mutex_init(&m_prod, NULL);

  this->rectangle_.initialize();
  this->triangle_.initialize();
  this->choice.initialize();
  this->optionGame.initialize();
  this->pgame.initialize();
  this->docredit.initialize();

  this->pl1 = "Raff";
  this->pl2 = "Loic";
  this->son = true;
  this->pauseGame = false;
  this->mode = DUEL;
  this->player = 2;

  this->option.prev = (void *)&launchgame;
  this->goForPerso.prev = (void *)&launchgame;
  this->menu.prev = (void *)&launchgame;
  this->credit.prev = (void *)&launchgame;

  this->funcBonus[0] = &MyGame::bonusVies;
  this->funcBonus[1] = &MyGame::bonusBomb;
  this->funcBonus[2] = &MyGame::bonusShoe;
  this->funcBonus[3] = &MyGame::bonusFlame;

  this->IAfunc[0] = &MyGame::IAUp;
  this->IAfunc[1] = &MyGame::IADown;
  this->IAfunc[2] = &MyGame::IALeft;
  this->IAfunc[3] = &MyGame::IARight;
  this->IAfunc[4] = &MyGame::IABomb;
  this->IAfunc[5] = &MyGame::IAUp;
  this->IAfunc[6] = &MyGame::IADown;
  this->IAfunc[7] = &MyGame::IALeft;
  this->IAfunc[8] = &MyGame::IARight;
  this->IAfunc[9] = &MyGame::IAUp;
  this->IAfunc[10] = &MyGame::IADown;
  this->IAfunc[11] = &MyGame::IALeft;
  this->IAfunc[12] = &MyGame::IARight;
  this->IAfunc[13] = &MyGame::IAUp;
  this->IAfunc[14] = &MyGame::IADown;
  this->IAfunc[15] = &MyGame::IALeft;
  this->IAfunc[16] = &MyGame::IARight;
  end = false;
}

void		MyGame::bonusVies(int perso)
{
  this->listPlayer[perso]->setNbVies(this->listPlayer[perso]->getNbVies() + 1);
}

void		MyGame::bonusBomb(int perso)
{
  this->listPlayer[perso]->setNBomb(this->listPlayer[perso]->getNBomb() + 1);
  this->listPlayer[perso]->fillBomb();
}

void		MyGame::bonusShoe(int perso)
{
  this->listPlayer[perso]->setShoe(this->listPlayer[perso]->getShoe() + 1);
}

void		MyGame::bonusFlame(int perso)
{
  this->listPlayer[perso]->setExplo(this->listPlayer[perso]->getExplo() + 1);
}

pthread_t	MyGame::getPthread(void) const
{
  return this->th;
}

int		MyGame::getPlayer(void) const
{
  return this->player;
}

Audio	&MyGame::getAudio(void)
{
  return this->audio;
}

void		MyGame::setPlayer(int player)
{
  this->player = player;
}

void MyGame::update(void)
{
  if (menu.getGo() == true)
    {
      std::list<AObject*>::iterator itb = this->objects_.begin();
      for (; itb != this->objects_.end(); ++itb)
	(*itb)->update(gameClock_, input_);
      for (int i = 1; this->listPlayer[i] != NULL; ++i)
	this->listPlayer[i]->marvin.update(gameClock_, input_);
      camera_.update(gameClock_, input_);
      for (std::list<gdl::Keys::Key>::const_iterator it = this->listTouch.begin(); it != this->listTouch.end(); it++)
	if (input_.isKeyDown((*it)) == true)
	  ((Touch *)(this->touch))->catchTouch((*it), this);
    }
}

gdl::Input	MyGame::getInput_(void)
{
  return (input_);
}

void	MyGame::drawContour(void)
{
  int	x = -1, y = -1;

  for (; y <= this->yMap;++y)
    {
      rectangle_.cube(((x) * 50.0f) - 800.0, ((y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x58767e, this->contour_);
      rectangle_.cube(((x + this->xMap + 1) * 50.0f) - 800.0, ((y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x58767e, this->contour_);
    }
  y = -1;
  for (; x <= this->xMap; ++x)
    {
      rectangle_.cube(((x) * 50.0f) - 800.0, ((y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x58767e, this->contour_);
      rectangle_.cube(((x) * 50.0f) - 800.0, ((y + this->yMap + 1) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x58767e, this->contour_);
    }
}

void	MyGame::drawMur(void)
{
  for (std::list<t_pos>::const_iterator it = this->listMur.begin(); it != this->listMur.end(); it++)
    rectangle_.cube((((*it).x) * 50.0f) - 800.0, (((*it).y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x58767e, this->wall_);
}

void	MyGame::drawBonus(void)
{
  for (std::list<t_posBonus>::iterator it = this->listBonus.begin(); it != this->listBonus.end(); it++)
    rectangle_.cube((((*it).x) * 50.0f) - 800.0, (((*it).y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x76511c, (*it).item);
}

void	MyGame::drawFloor(void)
{
  int	x = -1, y = -1;

  for (; y < this->yMap -1; y++)
    {
      for (;x < this->xMap - 1; x++)
  	rectangle_.floor(((x) * 50.0f) - 800.0, ((y) * -50.0f) - 0.0, -230.0f, this->floor_);
      x = -1;
    }
}

void	MyGame::drawFakeWall(void)
{
  for (std::list<t_pos>::const_iterator it = this->listFakeWall.begin(); it != this->listFakeWall.end(); it++)
    rectangle_.cube((((*it).x) * 50.0f) - 800.0, (((*it).y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0x76511c, this->fake_);
}

static bool		addExplosion(int xE, int yE, bool by, Bomb *t)
{
  tBomb	newBomb;

  newBomb.x = xE;
  newBomb.y = yE;
  t->listExplo.push_back(newBomb);
  return (by);
}

bool			MyGame::coordExp(int xE, int yE, bool flag, Bomb *t)
{
  if (flag == true)
    return true;
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    if (this->listPlayer[i]->getPosX() == xE && this->listPlayer[i]->getPosY() == yE)
      return (addExplosion(xE, yE, true, t));
  if (this->checkTrueWall(xE, yE) == true && this->checkFakeWall(xE, yE) == true)
    return (addExplosion(xE, yE, false, t));
  if (this->checkFakeWall(xE, yE) == false)
    return (addExplosion(xE, yE, true, t));
  return (true);
}

void			MyGame::updateExplo(Bomb *t, int i)
{
  if (t->getTest() == true)
    {
      int	a = 0;
      bool xAdd = false, xMin = false, yAdd = false, yMin = false;

      int xE = t->getX();
      int yE = t->getY();
      t->listExplo.clear();
      for (; a < this->listPlayer[i]->getExplo(); ++a)
	{
	  xAdd = this->coordExp(xE + a, yE, xAdd, t);
	  yAdd = this->coordExp(xE, yE + a, yAdd, t);
	  xMin = this->coordExp(xE - a, yE, xMin, t);
	  yMin = this->coordExp(xE, yE - a, yMin, t);
	}
    }
}

void	MyGame::drawExplo(Bomb *t)
{
  std::list<tBomb>	tmp = t->getListExplo();

  for (std::list<tBomb>::iterator it = tmp.begin(); it != tmp.end(); it++)
    {
      this->demolitionWall((*it).x, (*it).y, t);
      this->death((*it).x, (*it).y);
      rectangle_.cube((((*it).x) * 50.0f) - 800.0, (((*it).y) * -50.0f) - 0.0, -200.0f, 50.0f, 50.0f, 0xFFFC17, this->fire_);
    }
}

void	MyGame::drawBomb(void)
{
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getNbVies() > 0)
	for (std::queue<Bomb *>	tmp = this->listPlayer[i]->getListBomb(); tmp.empty() != true; tmp.pop())
	  {
	    if (tmp.front()->getToken() == true)
	      {
		tmp.front()->setToken(false);
		this->listPlayer[i]->eraseBomb();
		if (this->listPlayer[i]->getNbBomb() == 0)
		  this->listPlayer[i]->fillBomb();
	      }
	    else
	      {
		int	xLa = tmp.front()->getX();
		int	yLa = tmp.front()->getY();

	       	this->listPlayer[1]->marvin.drawmBomb(xLa, yLa);
		this->updateExplo(tmp.front(), i);
		this->drawExplo(tmp.front());
	      }
	  }
    }
}

void	MyGame::catchBonus(int x, int y, int perso)
{
  for (std::list<t_posBonus>::iterator it = this->listBonus.begin(); it != this->listBonus.end(); ++it)
    if ((*it).x == x &&	(*it).y == y)
      {
	(this->*funcBonus[(*it).nbItem])(perso);
	it = listBonus.erase(it);
      }
}

void	MyGame::drawPlayer(void)
{
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getNbVies() > 0)
	this->listPlayer[i]->marvin.draw();
      else
	this->listPlayer[i]->resetPlayer();
      this->catchBonus(this->listPlayer[i]->getPosX(), this->listPlayer[i]->getPosY(), i);
    }
}

void MyGame::drawInfoPlayer(void)
{
  int   x = 0;
  int	n = 1;

  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getNbVies() > 0)
	{
	  this->camera_.view(0, 0, 1000);
	  if (n <= 6)
	    hexagone_.hexagone(550, 785 + (x * - 2.3), 0, this->listPlayer[i]->marvin.getColor());
	  else
	    hexagone_.hexagone(250, 785 + (x * - 2.3), 0, this->listPlayer[i]->marvin.getColor());
	  this->camera_.view(0, -800, 1000);
	  x += 130;
	  if (n == 6)
	    x = 0;
	  ++n;
	}
    }
  x = 0;
  n = 1;
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getNbVies() > 0)
	{
	  std::ostringstream        nVies;
	  std::ostringstream        nBomb;
	  std::ostringstream        nShoe;
	  std::ostringstream        nFlame;


	  nVies << this->listPlayer[i]->getNbVies();
	  nBomb << this->listPlayer[i]->getNbBomb();
	  nShoe << this->listPlayer[i]->getShoe();
	  nFlame << this->listPlayer[i]->getExplo() - 3;
	  this->menu.drawInventaire(nVies.str(), this->listPlayer[i]->getName(), nBomb.str(), nShoe.str(), nFlame.str(), x, n);
	  x += 130;
	  if (n == 6)
	    x = 0;
	  ++n;
	}
    }
}

void	MyGame::goSound()
{
  if (son == true)
    this->getAudio().startMusicSound();
  else
    this->getAudio().stopMusicSound();
}

bool	MyGame::checkIntro()
{
  if (this->intro.getGo() == true)
    return true;
  this->camera_.view(0, 0, 1000);
  this->triangle_.wallpaper();
  this->intro.isTouch();
  return false;
}

void	*retardEnd(void *t)
{
  MyGame *tmp = (MyGame *)t;

  sleep(3);
  tmp->menu.setGo(false);
  tmp->goForPerso.setGo(false);
  tmp->option.setGo(false);
  tmp->option.setOption(false);
  tmp->launchgame.setGo(false);
  tmp->launchgame.setOption(false);
  tmp->launchgame.setGo(false);
  tmp->cleanListPerso();
  pthread_exit(0);
}

void	MyGame::toEnterInGame()
{
  int	nb = 0, nbPlay = 0, survivor = 0;

  this->camera_.view(0, 0, 4000);
  rectangle_.background(this->galaxie_);
  this->camera_.view(0 , -800, 1000);
  glDisable(GL_DEPTH_TEST);
  this->drawInfoPlayer();
  this->drawContour();
  this->drawMur();
  this->drawFakeWall();
  this->drawBonus();
  this->drawBomb();
  this->drawPlayer();
  this->drawFloor();
  this->randMoves();
  glEnable(GL_DEPTH_TEST);
  for (int i = 1; this->listPlayer[i] != NULL; ++i)
    {
      if (this->listPlayer[i]->getNbVies() <= 0)
	++nb;
      else
	survivor = i;
      ++nbPlay;
    }
  if (nb == nbPlay - 1)
    {
      pthread_t	over;
      if (end == false)
	{
	  this->end = true;
	  this->surv = survivor; 
	  if (this->listPlayer[this->surv])
	    this->listPlayer[survivor]->setNBomb(0);
	  pthread_create(&over, NULL, retardEnd, this);
	}
      else
	bonus_.write(this->listPlayer[survivor]->getName()+" WINS !!!!", 50, 100, 220, gdl::Color(255, 255, 255));
    }
}

void	MyGame::createBot(int i)
{
  std::string ia = "IA";
  int	xR = std::rand() % this->xMap;

  int	yR;

  if (xR % 2 == 0)
    yR = this->yMap - 1;
  else	
    yR = 0;

  this->createPlayer(xR, yR, ia, i, 0x000000);
}

void	MyGame::cleanListPerso()
{
  for (int i = 1; i <= this->getPlayer(); ++i)
    {
      delete this->listPlayer[i];
      this->listPlayer[i] = NULL;
    }
  this->setPlayer(2);
}

void	MyGame::reStart()
{
  if (this->menu.getGo() == true)
    {
      goSound();
      this->camera_.view(0, -800, 1000);
      this->addMapByFile(this->menu.getMap().c_str());
      this->end = false;
      for (int i = 1; i <= this->getPlayer(); ++i)
	{
	  if (i == 1)
	    this->createPlayer(0, 0, this->pl1, i, 0xFF00FF);
	  else if (i == 2 && this->mode == DUEL)
	    this->createPlayer(getXMap() - 1, getYMap() - 1, this->pl2, i, 0x00FF00);
	  else
	    createBot(i);
	}
    }
}

void	MyGame::checkGoLaunchGame()
{
  if (this->menu.getGo() == true)
    this->toEnterInGame();
  else
    {
      this->rectangle_.wallpaper(this->wallpaper_);
      this->camera_.view(0, 0, 1000);
      this->menu.chooseMap();
      this->reStart();
    }
}

bool	MyGame::checkGoLaunch(bool pass)
{
  if (pass == true && this->launchgame.getGo() == true)
    {
      this->checkGoLaunchGame();
      return false;
    }
  return pass;
}

void	MyGame::checkGoForPerso()
{
  if (this->goForPerso.getGo() == true)
    this->launchgame.setGo(true);
  else
    {
      this->optionGame.wallpaper();
      this->goForPerso.isTouch();
    }
}

void	MyGame::doOption()
{
  if (this->option.getGo() == true)
    this->checkGoForPerso();
  else
    {
      this->optionGame.wallpaper();
      this->option.isTouch();
    }
}

bool	MyGame::checkGoOption(bool pass)
{
  if (pass == true && this->launchgame.getOption() == true)
    {
      this->doOption();
      return false;
    }
  return pass;
}

void	MyGame::doCredits()
{
  if (this->credit.getGo() == true)
    return ;
  else
    {
      this->docredit.wallpaper();
      this->credit.isTouch();
    }
}

bool	MyGame::checkGoCredits(bool pass)
{
  if (pass == true && this->launchgame.getCredits() == true)
    {
      this->doCredits();
      return false;
    }
  return pass;
}

void	MyGame::choiceInLaunchGame()
{
  this->camera_.view(0, 0, 1000);
  this->choice.wallpaper();
  this->launchgame.isTouch();
}

bool	MyGame::checkPause()
{
 if (this->pausegame.getGo() == false)
    {
      this->camera_.view(0, 0, 1000);
      this->pgame.wallpaper();
      this->pausegame.inPause();
      return false;
    }
 return true;
}

void	MyGame::doClassique()
{
  this->rectangle_.wallpaper(this->wallpaper_);
  this->camera_.view(0, 0, 1000);
  this->classique.isTouch();
}

bool	MyGame::checkGoClassique(bool pass)
{
  if (pass == true && this->classique.getGo() == false)
    {
      this->doClassique();
      return false;
    }
  return pass;
}

void	MyGame::doLoad()
{
  this->choice.wallpaper();
  this->load.chooseLoad();
}

bool	MyGame::checkGoLoad(bool pass)
{
  if (pass == true && this->load.getGo() == false)
    {
      this->doLoad();
      return false;
    }
  return pass;
}


void MyGame::draw(void)
{
  bool pass = true;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0.23f, 0.84f, 95.0f, 1.0f);
  glClearDepth(1.0f);

  if (this->checkIntro() == false)
    return ;

  pass = this->checkPause();

  pass = this->checkGoClassique(pass);

  pass = this->checkGoLoad(pass);

  pass = this->checkGoLaunch(pass);

  pass = this->checkGoOption(pass);

  pass = this->checkGoCredits(pass);

  if (pass == true)
    this->choiceInLaunchGame();

  usleep(50000);
}

void MyGame::unload(void)
{
}
