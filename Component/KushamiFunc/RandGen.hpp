#ifndef RANDGEN_H
#define RANDGEN_H

#include <random>
class RandGen {
  private:
    bool gotRand = false;
    std::random_device rd;
    std::mt19937 mt;
    std::uniform_int_distribution<int> dist;

  public:
    RandGen();
    void setMaxRange(int min, int max);
    int getRand();

  private:
    void initGen();
};

#endif