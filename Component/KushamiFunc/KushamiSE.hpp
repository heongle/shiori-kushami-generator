#ifndef KUSHAMISE_H
#define KUSHAMISE_H

#include <sfml/Audio.hpp>
#include <iostream>
#include <memory>
#include "../../res/se_pointer.h"
#include "RandGen.hpp"

class KushamiSE {
  private:
    std::unique_ptr<sf::SoundBuffer[]> buffer;
    sf::Sound kushamiPlayer;
    RandGen randKushami;

  public:
    KushamiSE();
    ~KushamiSE();
    void playSE();
};

#endif /* KUSHAMISE_H */
