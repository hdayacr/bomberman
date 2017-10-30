
#ifndef AUDIO
# define AUDIO

#include	<SFML/Audio.hpp>

class Audio
{
public:
  Audio();
  ~Audio();
  void			startBombSound();
  void			startMusicSound();
  void                  startMenuSound();
  void                  stopMenuSound();
  void                  stopMusicSound();
  void                  pauseSound();
  void			stopCreditsSound();
  void			startCreditsSound();
protected:
  sf::SoundBuffer	buffer;
  sf::Sound		sound;
  sf::Music		music;
  sf::Music		menu;
  sf::Music		credits_;
};

#endif
