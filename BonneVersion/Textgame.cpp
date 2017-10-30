#include "Textgame.hpp"
#include <list>
#include <iterator>

void Textbomby::initialize(void)
{
  this->alphabet = gdl::Image::load("./image/charset.png");
  this->symbol = gdl::Image::load("./image/symbol.png");
  this->heart = gdl::Image::load("./image/heart.png");
  this->shoe = gdl::Image::load("./image/pegasusboots.png");
  this->bomb = gdl::Image::load("./image/bomb.png");
  this->flame = gdl::Image::load("./image/flame.png");
  this->text_ = gdl::Text("./image/font.TTF");

  this->mouto = gdl::Image::load("./image/HopeMoutau.jpg");
  this->jeromin = gdl::Image::load("./image/HopeJeromin.jpg");
  this->raff = gdl::Image::load("./image/HopeRaff.jpg");
  this->osika = gdl::Image::load("./image/HopeOsika.jpg");
  this->loic = gdl::Image::load("./image/HopeLoic.jpg");
  this->nathan = gdl::Image::load("./image/HopeNathan.jpg");
}

gdl::Image Textbomby::getAlphabet() const
{
  return this->alphabet;
}

gdl::Image Textbomby::getSymbol() const
{
  return this->symbol;
}

gdl::Image Textbomby::getHeart() const
{
  return this->heart;
}

gdl::Image Textbomby::getShoe() const
{
  return this->shoe;
}

gdl::Image Textbomby::getBomb() const
{
  return this->bomb;
}

gdl::Image Textbomby::getFlame() const
{
  return this->flame;
}

gdl::Image Textbomby::getMouto() const
{
  return this->mouto;
}

gdl::Image Textbomby::getJeromin() const
{
  return this->jeromin;
}

gdl::Image Textbomby::getRaff() const
{
  return this->raff;
}

gdl::Image Textbomby::getOsika() const
{
  return this->osika;
}

gdl::Image Textbomby::getLoic() const
{
  return this->loic;
}

gdl::Image Textbomby::getNathan() const
{
  return this->nathan;
}


void Textbomby::update(void)
{
}

void Textbomby::draw(void)
{
}

void Textbomby::write(const std::string text, int size, int x, int y, gdl::Color color)
{
  glMatrixMode(GL_MODELVIEW);
  glPushMatrix();
  glMatrixMode(GL_PROJECTION);
  glPushMatrix();
  glPushAttrib(GL_COLOR_BUFFER_BIT | GL_CURRENT_BIT | GL_ENABLE_BIT
	       | GL_TEXTURE_BIT | GL_TRANSFORM_BIT | GL_VIEWPORT_BIT);
  glDisable(GL_ALPHA_TEST);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_LIGHTING);
  text_.setColor(color);
  text_.setText(text);
  text_.setSize(size);
  text_.setPosition(x, y);
  text_.draw();
  glMatrixMode(GL_PROJECTION);
  glPopMatrix();
  glMatrixMode(GL_MODELVIEW);
  glPopMatrix();
  glPopAttrib();
}


void Textbomby::writeItem(int x, int y, int width, int height, gdl::Image image)
{
  glDisable(GL_DEPTH_TEST);
  glLoadIdentity();
  glPushMatrix();
  image.bind();
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glBegin(GL_QUADS);
  glTexCoord2f(0.0f, 0.0f);
  glVertex3d(x, y, 0);
  glTexCoord2f(0.0f, 1.0f);
  glVertex3d(x, y-height, 0);
  glTexCoord2f(1.0f, 1.0);
  glVertex3d(x + width, y-height, 0);
  glTexCoord2f(1.0f, 0.0f);
  glVertex3d(x+width, y, 0);
  glEnd();
  glDisable(GL_BLEND);
  glPopMatrix();
  glEnable(GL_DEPTH_TEST);
}
