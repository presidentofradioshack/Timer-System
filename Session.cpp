#include "Session.h"

Lap* Session::AddLap() {
  int index{0};

  if (laps.empty()) {
    index = 1;
  } else {
    index = GetLapCount() + 1;
  }
  Lap& new_lap = laps.emplace_back(index);
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

void Session::DisplayLapInfo() const {
  if (laps.empty()) {
    std::cout << "No current laps\n";
    return;
  }

  std::cout << "Current Laps:\n"
            << "------------\n";

  for (const Lap& lap : laps) {
    std::cout << std::format("Lap {}: {}\n", lap.GetIndex(),
                             lap.GetTotalTimeElapsed());
  }
}