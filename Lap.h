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
  Lap(int index) : index_{index} { std::cout << "Starting new lap\n"; }

  void Start();

  void Stop();

  void Reset();

  int GetIndex() const { return index_; }

  [[nodiscard]]
  bool IsRunning() const {
    return is_running_;
  }

  [[nodiscard]]
  bool IsCompleted() const {
    return is_completed_;
  }

  [[nodiscard]]
  std::string GetTotalTimeElapsed() const;

  std::string FormatTime(TimePoint& time_point);

 private:
  int index_;
  TimePoint start_time_;
  TimePoint end_time_;
  Milliseconds total_time_elapsed_;
  bool is_running_{false};
  bool is_completed_{false};
  Milliseconds GetTimeElapsed(TimePoint& end, TimePoint& start) const;
};

#endif  // TIMER_SYSTEM_LAP_H
