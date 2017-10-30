#ifndef TEXTGAME_HPP
# define TEXTGAME_HPP

#include <Text.hpp>
#include <GL/gl.h>
#include <GL/glu.h>
#include <Image.hpp>


class Textbomby
{

public:
  void initialize(void);
  void update(void);
  void draw(void);
  void writeItem(int, int, int, int, gdl::Image);
  void write(const std::string, int, int, int, gdl::Color);

  gdl::Image getMouto() const;
  gdl::Image getJeromin() const;
  gdl::Image getRaff() const;
  gdl::Image getOsika() const;
  gdl::Image getLoic() const;
  gdl::Image getNathan() const;

  gdl::Image getAlphabet() const;
  gdl::Image getSymbol() const;
  gdl::Image getHeart() const;
  gdl::Image getShoe() const;
  gdl::Image getBomb() const;
  gdl::Image getFlame() const;
private:
  gdl::Text text_;
  gdl::Image alphabet;
  gdl::Image symbol;
  gdl::Image heart;
  gdl::Image shoe;
  gdl::Image bomb;
  gdl::Image flame;

  gdl::Image mouto;
  gdl::Image jeromin;
  gdl::Image raff;
  gdl::Image osika;
  gdl::Image loic;
  gdl::Image nathan;
};


#endif
