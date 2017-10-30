
NAME=	bomberman

SRC=	./BonneVersion/Bomberman.cpp\
	./BonneVersion/Character.cpp\
	./BonneVersion/Camera.cpp\
	./BonneVersion/Vector3f.cpp\
	./BonneVersion/MyGame.cpp\
	./BonneVersion/Shape.cpp\
	./BonneVersion/main.cpp\
	./BonneVersion/Touch.cpp\
	./BonneVersion/Error.cpp\
	./BonneVersion/Textgame.cpp\
	./BonneVersion/Menu.cpp\
	./BonneVersion/Anim.cpp\
	./BonneVersion/Audio.cpp\
	./BonneVersion/LaunchGame.cpp\
	./BonneVersion/Intro.cpp\
	./BonneVersion/Bomb.cpp\
	./BonneVersion/Option.cpp\
	./BonneVersion/GoPerso.cpp\
	./BonneVersion/Save.cpp\
	./BonneVersion/Credits.cpp\
	./BonneVersion/Classique.cpp\
	./BonneVersion/inGame.cpp\
	./BonneVersion/IA.cpp\
	./BonneVersion/Load.cpp

OBJ=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-W -Wall -Werror -Wextra
CPPFLAGS	+=	-lgdl_gl -lGL -lGLU
CPPFLAGS	+=	-I./libgdl_gl-2012.4/include/
CPPFLAGS	+=	-L./libgdl_gl-2012.4/lib -Wl,--rpath=./libgdl_gl-2012.4/lib
CPPFLAGS	+=	-lsfml-system -lsfml-audio

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) -lpthread 

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all