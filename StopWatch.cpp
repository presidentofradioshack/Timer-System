#include "StopWatch.h"

#include "Event.h"
#include "Lap.h"

void StopWatch::HandleEvent(const Event& e) {
  switch (e.type) {
    case EventType::START:
      Start();
      break;

    case EventType::STOP:
      Stop();
      break;

    case EventType::LAP:
      NewLap();
      break;

    case EventType::RESET:
      Reset();
      break;

    default:
      break;
  }
}

void StopWatch::Start() {
  if (current_state_ == State::RUNNING) {
    std::cout << "Stopwatch is already running.\n";
    return;
  }

  if (!current_session_.GetLapCount()) {
    Lap* new_lap = current_session_.AddLap();
    new_lap->Start();
  } else {
    Resume();
  }

  std::cout << "Starting\n";
  current_state_ = State::RUNNING;
}

void StopWatch::Stop() {
  if (current_state_ == State::STOPPED) {
    std::cout << "Stopwatch is already stopped\n";
    return;
  }

  std::cout << "Stopping\n";
  Lap* lap = current_session_.GetCurrentLap();
  lap->Stop();
  current_state_ = State::STOPPED;
}

void StopWatch::Resume() {
  if (current_state_ != State::STOPPED) {
    std::cout << "Stopwatch is currently running\n";
    return;
  }

  Lap* lap = current_session_.GetCurrentLap();
  lap->Resume();
  current_state_ = State::RUNNING;
}

void StopWatch::NewLap() {
  if (current_state_ != State::RUNNING) {
    std::cout << "Stopwatch must be running to lap\n";
    return;
  }

  Lap* new_lap = current_session_.AddLap();
  new_lap->Start();
}

void StopWatch::Reset() {
  if (current_session_.GetLapCount() == 0) {
    std::cout << "No laps to reset. Doing nothing\n";
    return;
  }

  if (current_state_ != State::STOPPED) {
    std::cout << "Stopwatch must be stopped to reset\n";
    return;
  }

  current_session_.ClearLaps();
  current_state_ = State::STOPPED;
}