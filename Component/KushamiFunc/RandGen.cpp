#include "RandGen.hpp"

RandGen::RandGen() : mt(rd()) {}

void RandGen::setMaxRange(int min, int max) {
    if (max > 0){
        gotRand = true;
        dist = std::uniform_int_distribution<int>(min, max);
    } else {
        gotRand = false;
    }
}

int RandGen::getRand() {
    if (gotRand) {
        return dist(mt);
    }
    return 0;
}