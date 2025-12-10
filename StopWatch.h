//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_STOPWATCH_H
#define TIMER_SYSTEM_STOPWATCH_H
#include <iostream>
#include "Session.h"

class StopWatch {
public:
    StopWatch() {
        std::cout << "Booting up stopwatch\n";
    }

    void Start() {
        if ( current_session_ ) {
            std::cout << "Current session already exists!\n";
            return;
        }

        Session session;
        current_session_ = session;
    }

    void Pause() {
        if ( !current_session_ ) {
            std::cout << "No current session to pause\n";
            return;
        }

        current_session_
    }

    void Resume() {}

    void Stop() {}

    void Lap() {}

private:
    std::vector<Session*> sessions_;
    Session& current_session_;
};


#endif // TIMER_SYSTEM_STOPWATCH_H
