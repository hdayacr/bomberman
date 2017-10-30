
#include	"Audio.hpp"

Audio::Audio()
{
  this->buffer.LoadFromFile("./sound/bomb.wav");
  this->music.OpenFromFile("./sound/story.ogg");
  this->credits_.OpenFromFile("./sound/godfather.ogg");
}

Audio::~Audio()
{

}

void    Audio::startMenuSound()
{
}

void	Audio::startMusicSound()
{
  this->music.Play();
}

void	Audio::startBombSound()
{
  this->sound.SetBuffer(this->buffer);
  this->sound.Play();
}

void    Audio::pauseSound()
{
  this->music.Pause();
}

void    Audio::stopMenuSound()
{
  this->menu.Stop();
}

void    Audio::stopMusicSound()
{
  this->music.Stop();
}

void	Audio::startCreditsSound()
{
  this->credits_.Play();
}

void	Audio::stopCreditsSound()
{
  this->credits_.Stop();
}

