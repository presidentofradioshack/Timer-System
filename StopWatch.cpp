#include "StopWatch.h"

#include "Event.h"
#include "Lap.h"

void StopWatch::HandleEvent(const Event& e) {
  switch (e.type) {
    case EventType::START:
      if (current_state_ == State::RUNNING) {
        std::cout << "Stopwatch is already running.\n";
        return;
      }

      Start();
      break;

    case EventType::STOP:
      if (current_state_ == State::STOPPED) {
        std::cout << "Stopwatch is already stopped\n";
        return;
      }

      Stop();
      break;

    case EventType::LAP:
      if (current_state_ != State::RUNNING) {
        std::cout << "Stopwatch must be running to lap\n";
        return;
      }

      NewLap();
      break;

    case EventType::RESET:
      if (current_state_ != State::STOPPED) {
        std::cout << "Stopwatch must be stopped to reset\n";
        return;
      }

      Reset();
      break;

    default:
      break;
  }
}

void StopWatch::Start() {
  if (!current_session_.GetLapCount()) {
    Lap* new_lap = current_session_.AddLap();
    new_lap->Start();
  } else {
    Lap* current_lap = current_session_.GetCurrentLap();
    current_lap->Start();
  }

  std::cout << "Starting\n";
  current_state_ = State::RUNNING;
}

void StopWatch::Stop() {
  std::cout << "Stopping\n";
  Lap* current_lap = current_session_.GetCurrentLap();
  current_lap->Stop();

  current_session_.DisplayLapInfo();
  current_state_ = State::STOPPED;
}

void StopWatch::NewLap() {
  Lap* current_lap = current_session_.GetCurrentLap();
  current_lap->Stop();

  Lap* new_lap = current_session_.AddLap();
  new_lap->Start();
}

void StopWatch::Reset() {
  if (current_session_.GetLapCount() == 0) {
    std::cout << "No laps to reset. Doing nothing\n";
    return;
  }

  Lap* current_lap = current_session_.GetCurrentLap();
  current_lap->Reset();

  current_session_.ClearLaps();

  current_state_ = State::STOPPED;
}