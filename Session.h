//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_SESSION_H
#define TIMER_SYSTEM_SESSION_H
#include <iostream>
#include <chrono>
#include "Lap.h"

struct Session {
public:
    Session() : created_on_{std::chrono::steady_clock::now()}, last_updated_on_{created_on_} {
        std::cout << "Creating session!\n";
    }

    void UpdateLastUpdatedTime() {
        last_updated_on_ = std::chrono::steady_clock::now();
    }

    void StartLap() {
        Lap new_lap;
    }

    void StopLap() {

    }



    void AddLap(const Lap& new_lap) {
        laps.push_back(new_lap);
        UpdateLastUpdatedTime();
    }

private:
    std::string name;
    std::vector<Lap> laps;
    std::chrono::time_point<std::chrono::steady_clock> created_on_;
    std::chrono::time_point<std::chrono::steady_clock> last_updated_on_;
};

#endif // TIMER_SYSTEM_SESSION_H
