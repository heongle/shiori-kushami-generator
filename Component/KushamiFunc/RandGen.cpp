#include "RandGen.hpp"

/**
 * RandGen constructor
 */
RandGen::RandGen() : mt(rd()) {}

/**
 * Set the range of the value which generator will generate
 * @param int min
 * @param int max
 */
void RandGen::setMaxRange(int min, int max) {
    if (max > 0){
        gotRand = true;
        dist = std::uniform_int_distribution<int>(min, max);
    } else {
        gotRand = false;
    }
}

/**
 * Retrive the random number
 */
int RandGen::getRand() {
    if (gotRand) {
        return dist(mt);
    }
    return 0;
}