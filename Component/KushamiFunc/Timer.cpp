#include "Timer.hpp"
#include <iostream>
Timer::Timer() : fix(0){}

void Timer::startTimer(int fix, int rand) {
    this->fix = fix;
    randNumb.setMaxRange(0, rand);
    kushamiThread = std::thread(&Timer::startLoop, this);
}

bool Timer::isStarted() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return started;
}

void Timer::stopTimer() {
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        started = false;
    }
    cv.notify_all();
    kushamiThread.join();
    std::cout << "Thread Joined\n";
}

void Timer::startLoop() {
    std::cout << "Thread Started\n";
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        started = true;
    }

    while (true) {
        int totalTime = fix + randNumb.getRand();
        std::cout << "Total Time: " << totalTime << "\n";
        // play se
        kushamiSE.playSE();
        // wait for the time or signaled
        {
            std::unique_lock<std::mutex> lk(m_Mutex);
            if (cv.wait_for(lk, std::chrono::minutes(totalTime), [this] { return !started; })) {
                std::cout << "Thread Interupted\n";
                return;
            }
        }
        std::cout << "Thread Continue\n";
    }
}