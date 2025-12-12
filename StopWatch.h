//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_STOPWATCH_H
#define TIMER_SYSTEM_STOPWATCH_H
#include <iostream>

#include "Event.h"
#include "Session.h"

enum State { STOPPED, RUNNING };

class StopWatch {
 public:
  StopWatch() { std::cout << "Booting up stopwatch\n"; }

  void HandleEvent(const Event& e);

  void Start();

  void Reset();

  void Stop();

  void NewLap();

  [[nodiscard]]
  const Session& GetCurrentSession() const {
    return current_session_;
  }

  void LoadSession();

 private:
  std::vector<Session*> sessions_;
  Session current_session_;
  State current_state_{State::STOPPED};
};

#endif  // TIMER_SYSTEM_STOPWATCH_H
