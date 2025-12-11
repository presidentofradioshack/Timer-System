//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_LAP_H
#define TIMER_SYSTEM_LAP_H

#include <chrono>
#include <iostream>

using namespace std::chrono_literals;

class Lap {
  using Clock = std::chrono::steady_clock;
  using TimePoint = std::chrono::time_point<Clock>;
  using Milliseconds = std::chrono::milliseconds;

 public:
  Lap() { std::cout << "Starting new lap\n"; }

  void Start();

  void Stop();

  void Resume();

  [[nodiscard]]
  bool IsRunning() const {
    return is_running_;
  }

  [[nodiscard]]
  bool IsCompleted() const {
    return is_completed_;
  }

  [[nodiscard]]
  Milliseconds GetTimeElapsed() const;

  std::string FormatTime(TimePoint& time_point);

 private:
  TimePoint start_time_;
  TimePoint end_time_;
  bool is_running_{false};
  bool is_completed_{false};
};

#endif  // TIMER_SYSTEM_LAP_H
