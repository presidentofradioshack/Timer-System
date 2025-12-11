
#include "Lap.h"

#include <chrono>
#include <iostream>

using Clock = std::chrono::steady_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Milliseconds = std::chrono::milliseconds;

void Lap::Start() {
  if (is_running_) return;

  std::cout << "Lap starting\n";

  start_time_ = Clock::now();
  is_running_ = true;
}

void Lap::Stop() {
  if (!is_running_) return;

  end_time_ = Clock::now();

  total_time_elapsed_ += GetTimeElapsed(end_time_, start_time_);

  std::cout << "Total time elapsed: " << GetTotalTimeElapsed() << std::endl;

  is_running_ = false;
}

void Lap::Reset() {
  total_time_elapsed_ = 0ms;

  is_running_ = false;
}

Milliseconds Lap::GetTimeElapsed(TimePoint& end, TimePoint& start) const {
  if (is_running_) {
    return std::chrono::duration_cast<Milliseconds>(Clock::now() - start);
  } else {
    return std::chrono::duration_cast<Milliseconds>(end - start);
  }
}

std::string Lap::GetTotalTimeElapsed() const {
  return std::format("{:%M:%S}", total_time_elapsed_);
}