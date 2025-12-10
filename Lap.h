//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_LAP_H
#define TIMER_SYSTEM_LAP_H

#include <iostream>
#include <chrono>

using namespace std::chrono_literals;

struct Lap {
    using Clock = std::chrono::steady_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using Milliseconds = std::chrono::milliseconds;

public:
    Lap() {
        std::cout << "Starting new lap\n";
    }

    Start() {
        if ( is_running_ ) return;

        start_time_ = Clock::now();
        is_running_ = true;
    }

    Stop() {
        if ( !is_running_ ) return;

        end_time_ = Clock::now();
        is_running_ = false;
    }

    bool IsRunning() {
        return is_running_;
    }

    bool IsCompleted() {
        return is_completed_;
    }

     Milliseconds GetTimeElapsed() {
        if ( is_running_ ) {
            return std::chrono::duration_cast<Milliseconds>(Clock::now() - start_time_);
        } else if ( !is_running_ ) {
            return std::chrono::duration_cast<Milliseconds>(end_time_ - start_time_);
        } else {
            return 0ms;
        }
     }

private:
    TimePoint start_time_;
    TimePoint end_time_;
    bool is_running_{false};
    bool is_completed_{false};
};


#endif // TIMER_SYSTEM_LAP_H
