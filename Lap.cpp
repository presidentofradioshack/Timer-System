
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
  std::cout << "Lap stopping\n";
  if (!is_running_) return;
  std::cout << "Lap stopping after return\n";

  end_time_ = Clock::now();

  std::chrono::duration<double, std::milli> duration = end_time_ - start_time_;

  std::cout << "Lap duration: " << duration << "ms\n";

  is_running_ = false;
}

void Lap::Resume() {
  if (is_running_) return;

  std::cout << "Resuming lap\n";

  is_running_ = true;
}

Milliseconds Lap::GetTimeElapsed() const {
  if (is_running_) {
    return std::chrono::duration_cast<Milliseconds>(Clock::now() - start_time_);
  } else if (!is_running_) {
    return std::chrono::duration_cast<Milliseconds>(end_time_ - start_time_);
  } else {
    return 0ms;
  }
}