#include "Shape.hpp"

void Triangle::initialize(void)
{
  this->picIntro = gdl::Image::load("./image/Bomberman_Logo.jpg");
}

void Triangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void Triangle::draw(void)
{
  glBegin(GL_TRIANGLES);
  glColor3f(1.0f, 0.50f, 0.75f);
  glVertex3f(0.0f, 150.0f, 0.0f);
  glVertex3f(-150.0f, 0.0f, 0.0f);
  glVertex3f(150.0f, 00.0f, 0.0f);
  glEnd();
}

void Triangle::wallpaper(void)
{
  this->picIntro.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 150, HAUTEUR + -50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 150, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}

void Rectangle::initialize(void)
{
  this->image_ = gdl::Image::load("./image/bomberman2.jpg");
  this->texture_ = gdl::Image::load("./image/wall2.jpg");
}

void Rectangle::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void Rectangle::draw(void)
{
  glPushMatrix();
  glLoadIdentity();
  glTranslatef(-800, 600, 0);

  glBegin(GL_QUADS);
  glColor3f(1.0f, 0.50f, 0.75f);

  glVertex3f(-150.0f, 100.0f, 0.0f);
  glVertex3f(-150.0f, -100.0f, 0.0f);
  glVertex3f(150.0f, -100.0f, 0.0f);
  glVertex3f(150.0f, 100.0f, 0.0f);
  glEnd();
  glPopMatrix();
}

void	Rectangle::cube(float x, float y, float z, float, float, float, gdl::Image texture_)
{
  glPushMatrix();
  glTranslatef(x,y,z);

  x = 25.0;
  y = 25.0;
  z = 25.0;

  texture_.bind();
 
  glBegin(GL_QUADS);


  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x,y,z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x,y,z*-1);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x*-1,y,z*-1);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x*-1,y,z);


  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x,y*-1,z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x,y*-1,z*-1);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x,y,z*-1);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x,y,z);

  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x*-1,y*-1,z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x*-1,y*-1,z*-1);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x,y*-1,z*-1);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x,y*-1,z);


  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x*-1,y,z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x*-1,y,z*-1);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x*-1,y*-1,z*-1);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x*-1,y*-1,z);


  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x,y,z*-1);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x,y*-1,z*-1);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x*-1,y*-1,z*-1);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x*-1,y,z*-1);

  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x,y*-1,z);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x,y,z);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x*-1,y,z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x*-1,y*-1,z);

  glEnd();
  glPopMatrix();
}

void Rectangle::wallpaper(gdl::Image image_)
{
  image_.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 150, HAUTEUR + -50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 150, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}

void Rectangle::background(gdl::Image image_)
{
  image_.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR * 5 + 150), HAUTEUR * 5 - 100);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR * 5 + 150), -(HAUTEUR * 5 - 100));
  glTexCoord2d(1, 1); glVertex2f(LARGEUR * 5 + 150, -(HAUTEUR * 5 - 100));
  glTexCoord2d(1, 0); glVertex2f(LARGEUR * 5 + 150, HAUTEUR * 5 - 100);
  glEnd();
}


void Rectangle::floor(float x, float y, float z, gdl::Image image_)
{
  glPushMatrix();
  image_.bind();

  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x, y, z);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x, y-100.0f, z);
  glTexCoord2f(1.0f, 1.0f);
  glVertex3d(x + 100.0f, y-100.0f, z);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x+100.0f, y, z);
  glEnd();
  glPopMatrix();
}

void Hexagone::initialize(void)
{
}

void Hexagone::update(gdl::GameClock const&, gdl::Input &)
{
}

void Hexagone::draw(void)
{
}

void Hexagone::hexagone(float x, float y, float z, int color)
{
  glLoadIdentity();
  glPushMatrix();
  glColor3ub(color/256/256, color/256, color);
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  glDisable(GL_TEXTURE_2D);
  glBegin(GL_TRIANGLE_FAN); 
  glVertex3f(x-100,  y-150,  z+0);
  glVertex3f(x-150,   y+0,  z+0);
  glVertex3f(x-100,   y+150,  z+0);
  glVertex3f( x+100,   y+150,  z+0);
  glVertex3f(  x+150,   y+0,  z+0);
  glVertex3f( x+100,  y-150,  z+0);
  glEnd();
  glPopMatrix();

  glLoadIdentity();
  glPushMatrix();
  glColor3ub(0, 0, 0);
  glRotatef(90, 0.0f, 0.0f, 1.0f);
  glDisable(GL_TEXTURE_2D);
  glBegin(GL_TRIANGLE_FAN);
  glVertex3f(x-90,  y-140,  z+0);
  glVertex3f(x-140,   y+0,  z+0);
  glVertex3f(x-90,   y+140,  z+0);
  glVertex3f( x+90,   y+140,  z+0);
  glVertex3f(  x+140,   y+0,  z+0);
  glVertex3f( x+90,  y-140,  z+0);
  glEnd();
  glPopMatrix();
}


void    Choice::initialize(void)
{
  this->bomby = gdl::Image::load("./image/bomberman.jpg");
}

void    Choice::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  (void)gameClock;
  (void)input;
}

void    Choice::draw(void)
{
}

void    Choice::wallpaper(void)
{
  this->bomby.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 150, HAUTEUR - 50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 150, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}

void    OptionGame::initialize(void)
{
  this->bomby = gdl::Image::load("./image/bomby.jpg");
}

void    OptionGame::update(gdl::GameClock const &, gdl::Input &)
{
}

void    OptionGame::draw(void)
{
}

void    OptionGame::wallpaper(void)
{
  this->bomby.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 150, HAUTEUR - 50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 150, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}

void    DoCredit::initialize(void)
{
  this->thecredit = gdl::Image::load("./image/sol.jpg");
}

void    DoCredit::update(gdl::GameClock const &, gdl::Input &)
{
}

void    DoCredit::draw(void)
{
}

void    DoCredit::wallpaper(void)
{
  this->thecredit.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 150, HAUTEUR - 50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 150, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}


void	PGame::initialize(void)
{
  this->bomby = gdl::Image::load("./image/pause.png");
}

void	PGame::update(gdl::GameClock const &, gdl::Input &)
{
}

void	PGame::draw(void)
{
}

void    PGame::wallpaper(void)
{
  this->bomby.bind();
  glBegin(GL_QUADS);
  glTexCoord2d(0, 0); glVertex2f(-(LARGEUR) - 140, HAUTEUR - 50);
  glTexCoord2d(0, 1); glVertex2f(-(LARGEUR) - 140, -(HAUTEUR) + 100);
  glTexCoord2d(1, 1); glVertex2f(LARGEUR + 135, -(HAUTEUR) + 100);
  glTexCoord2d(1, 0); glVertex2f(LARGEUR + 135, HAUTEUR - 50);
  glEnd();
}
