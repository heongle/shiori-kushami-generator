#include <sfml/Audio.hpp>
#include <iostream>
#include "../../res/se_pointer.h"
#include "RandGen.hpp"

class KushamiSE {
  private:
    sf::SoundBuffer *buffer;
    sf::Sound kushamiPlayer;
    RandGen randKushami;

  public:
    KushamiSE();
    ~KushamiSE();
    void playSE();
};