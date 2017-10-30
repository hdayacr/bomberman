# include "MyGame.hpp"
# include <sstream>

void	MyGame::loadGame(void)
{
  const char*	name = this->save.c_str();
  std::ifstream fichier(name, std::ios::in);
  std::string contenu;
  int	x;
  int	y;
  int	pers;

  this->cleanListPerso();

  if (fichier)
    {
      std::getline(fichier, contenu);

      this->menu.map = contenu;
      this->getAudio().stopMenuSound();
      this->getAudio().startMusicSound();
      this->camera_.view(0, -800, 1000);
      this->addMapByFile(contenu.c_str());


      std::getline(fichier, contenu);

      std::istringstream nb(contenu);
      nb >> pers;

      std::getline(fichier, contenu);
      int	mode_;
      std::istringstream modeu(contenu);
      modeu >> mode_;
      this->mode = (modeGame)mode_;

      for (int i = 1; i <= pers; ++i)
	{
      	  std::string	Name;
      	  int	color, XMap, YMap, Vie, bomb, flame, shoe;

      	  std::getline(fichier, Name);
      	  std::getline(fichier, contenu);
      	  std::istringstream col(contenu);
      	  col >> color;
      	  std::getline(fichier, contenu);
      	  std::istringstream x(contenu);
      	  x >> XMap;
      	  std::getline(fichier, contenu);
      	  std::istringstream y(contenu);
      	  y >> YMap;
      	  this->createPlayer(XMap, YMap, Name, i, color);
      	  std::getline(fichier, contenu);
      	  std::istringstream life(contenu);
      	  life >> Vie;
	  this->listPlayer[i]->setNbVies(Vie);
      	  std::getline(fichier, contenu);
      	  std::istringstream bibomb(contenu);
      	  bibomb >> bomb;
	  this->listPlayer[i]->setNBomb(bomb);
	  this->listPlayer[i]->fillBomb();
      	  std::getline(fichier, contenu);
      	  std::istringstream flamiche(contenu);
      	  flamiche >> flame;
	  this->listPlayer[i]->setExplo(flame);
      	  std::getline(fichier, contenu);
      	  std::istringstream shoesi(contenu);
      	  shoesi >> shoe;
	  this->listPlayer[i]->setShoe(shoe);

	}
      this->listFakeWall.clear();
      while (std::getline(fichier, contenu, ';'))
	{
	  std::istringstream xx(contenu);
	  xx >> x;
	  std::getline(fichier, contenu, ';');
	  std::istringstream yy(contenu);
	  yy >> y;

	  this->stockPosInlistFakeWall(x, y);
	}
      fichier.close();
    }
  else
    {
      std::cerr << "Impossible de charger le fichier !" << std::endl;
      this->menu.setGo(false);
      this->launchgame.setGo(false);
    }
}

void	MyGame::saveGame(void)
{
  std::ofstream fichier("./save/save1.txt", std::ios::out | std::ios::trunc);  
  if (fichier)
    {
      int	a = 0;

      fichier << menu.getMap() << std::endl;
      for (int i = 1; this->listPlayer[i] != NULL; ++i)
	a++;
      fichier << a << std::endl;
      fichier << this->mode << std::endl;
      for (int i = 1; this->listPlayer[i] != NULL; ++i)
	{
	  fichier << this->listPlayer[i]->getName() << std::endl;
	  fichier << this->listPlayer[i]->marvin.getColor() << std::endl;
	  fichier << this->listPlayer[i]->getPosX() << std::endl; 
	  fichier << this->listPlayer[i]->getPosY() << std::endl;
	  fichier << this->listPlayer[i]->getNbVies() << std::endl;
	  fichier << this->listPlayer[i]->getNBomb() << std::endl;
	  fichier << this->listPlayer[i]->getExplo() << std::endl;
	  fichier << this->listPlayer[i]->getShoe() << std::endl;
	}
      std::list<t_pos> Pos = this->listFakeWall;
      for (std::list<t_pos>::iterator it = Pos.begin(); it != Pos.end(); it++)
	fichier << (*it).x << ';' << (*it).y << ';';;
      fichier.close();
      std::cout << "\nGame is save" << std::endl;
    }
  else
    std::cerr << "Impossible de sauvegarder le fichier!" << std::endl;
}
