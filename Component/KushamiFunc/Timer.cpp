#include "Timer.hpp"
#include <iostream>

/**
 * Timer constructor
 */
Timer::Timer() : fix(0){}

/**
 * Start timer with specific fix time and random time
 * @param fix
 * @param rand
 */
void Timer::startTimer(int fix, int rand) {
    this->fix = fix;
    randNumb.setMaxRange(0, rand);
    // Start timer in new thread
    kushamiThread = std::thread(&Timer::startLoop, this);
}

/**
 * Retrieve the start status of timer
 * @return bool
 */
bool Timer::isStarted() {
    std::lock_guard<std::mutex> lock(m_Mutex);
    return started;
}

/**
 * Stop timer
 */
void Timer::stopTimer() {
    {
        std::lock_guard<std::mutex> lock(m_Mutex);
        started = false;
    }
    cv.notify_all();
    kushamiThread.join();
    std::cout << "Thread Joined\n";
}

/**
 * Loop function for timer to plat kushami every loop with new generated time
 */
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