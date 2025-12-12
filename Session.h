//
// Created by Ethan Heckard on 12/9/25.
//

#ifndef TIMER_SYSTEM_SESSION_H
#define TIMER_SYSTEM_SESSION_H
#include <chrono>
#include <iostream>

#include "Lap.h"

class Session {
 public:
  Session()
      : created_on_{std::chrono::steady_clock::now()},
        last_updated_on_{created_on_} {
    std::cout << "Creating session!\n";
  }

  Session(std::vector<Lap> laps) : laps{laps} {}

  void UpdateLastUpdatedTime() {
    last_updated_on_ = std::chrono::steady_clock::now();
  }

  [[nodiscard]]
  std::vector<Lap> GetLaps() const {
    return laps;
  }

  Lap* GetCurrentLap();

  void DisplayLapInfo() const;

  Lap* AddLap();

  [[nodiscard]]
  std::size_t GetLapCount() const {
    return laps.size();
  }

  void ClearLaps();

  void LoadLaps(std::vector<Lap>& loaded);

 private:
  std::string name;
  std::vector<Lap> laps;
  std::chrono::time_point<std::chrono::steady_clock> created_on_;
  std::chrono::time_point<std::chrono::steady_clock> last_updated_on_;
};

#endif  // TIMER_SYSTEM_SESSION_H
