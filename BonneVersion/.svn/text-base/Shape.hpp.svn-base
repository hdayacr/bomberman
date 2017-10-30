#ifndef SHAPE_HPP
# define SHAPE_HPP

# include "Aobject.hpp"
# include "Image.hpp"

# define LARGEUR 800
# define HAUTEUR 800

class Triangle : public AObject
{
public:
  void wallpaper(void);
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void	raff(float, float, float, float, float);
private:
  gdl::Image picIntro;
};

class Rectangle : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw();
  void cube(float, float, float, float, float, float, gdl::Image);
  void floor(float, float, float, gdl::Image);
  void wallpaper(gdl::Image);
  void background(gdl::Image);
private:
  gdl::Image image_;
  gdl::Image texture_;
};

class Hexagone : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void hexagone(float, float, float, int);
};

class Choice : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void wallpaper(void);
private:
  gdl::Image bomby;
};

class OptionGame : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void wallpaper(void);
private:
  gdl::Image bomby;
};

class DoCredit : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void wallpaper(void);
private:
  gdl::Image thecredit;
};

class PGame : public AObject
{
public:
  void initialize(void);
  void update(gdl::GameClock const&, gdl::Input &);
  void draw(void);
  void wallpaper(void);
private:
  gdl::Image bomby;
};

#endif
