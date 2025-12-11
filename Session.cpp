#include "Session.h"

Lap* Session::AddLap() {
  Lap& new_lap = laps.emplace_back();
  UpdateLastUpdatedTime();

  std::cout << "Current lap count: " << GetLapCount() << std::endl;

  return &new_lap;
}

Lap* Session::GetCurrentLap() {
  if (laps.empty()) {
    std::cerr << "No laps exist.\n";
    return nullptr;
  }

  return &laps.back();
}

void Session::ClearLaps() {
  laps.clear();

  std::cout << "Resetting! Current laps: " << GetLapCount() << std::endl;
}