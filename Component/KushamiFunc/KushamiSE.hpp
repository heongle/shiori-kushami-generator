#include <sfml/Audio.hpp>
#include <iostream>
#include "../../res/se_pointer.h"
#include "RandGen.hpp"

class KushamiSE {
  private:
    sf::SoundBuffer buffer[4];
    sf::Sound kushamiPlayer;
    RandGen randKushami;

  public:
    KushamiSE();
    void playSE();
};