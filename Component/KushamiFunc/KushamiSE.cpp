#include "KushamiSE.hpp"

/**
 * KushamiSE constructor
 */
KushamiSE::KushamiSE() : buffer(new sf::SoundBuffer[soundArraySize]) {
    for (int i = 0; i < soundArraySize; ++i) {
        if (!buffer[i].loadFromMemory(sound_pointer[i], (std::size_t)sound_length_pointer[i])) {
            std::cerr << "Error opening Shiori Stream" << std::endl;
        }
    }
    randKushami.setMaxRange(0, soundArraySize - 1);
}

/**
 * Play kushami. Random on each call
 */
void KushamiSE::playSE() {
    kushamiPlayer.setBuffer(buffer[randKushami.getRand()]);
    kushamiPlayer.play();
}
