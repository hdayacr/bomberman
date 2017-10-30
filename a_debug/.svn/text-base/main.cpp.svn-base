#include "Bomberman.hpp"
#include "MyGame.hpp"

int	main(int argc, char **argv)
{
  try
    {
      if (argc > 0)
	{
	  MyGame		game;
	  (void) argv;
	  game.run();
	  return (0);
	}
      else
	std::cout << "Pas assez d'arguments" << std::endl;
    }
  catch (End const &end)
    {
      std::cout << end.what() << std::endl;
    }
  return (0);
}
