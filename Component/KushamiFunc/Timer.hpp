#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>
#include "RandGen.hpp"
#include "KushamiSE.hpp"

class Timer {
  private:
    int fix;
    bool started = false;
    RandGen randNumb;
    KushamiSE kushamiSE;
    std::thread kushamiThread;
    std::mutex m_Mutex;
    std::condition_variable cv;

  public:
    Timer();
    void startTimer(int fix, int rand);
    bool isStarted();
    void stopTimer();

  private:
    void startLoop();
};

#endif /* TIMER_H */
