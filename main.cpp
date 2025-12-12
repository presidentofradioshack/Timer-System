#include <iostream>

#include "ConsoleSessionIO.h"
#include "Event.h"
#include "Session.h"
#include "SessionStorage.h"
#include "StopWatch.h"
#include "TerminalInput.h"
#include "TerminalRenderer.h"

int main() {
  StopWatch stopwatch;
  TerminalInput terminal_input;
  TerminalRenderer terminal;

  bool running{true};

  while (running) {
    terminal.Render(stopwatch);

    Event e = terminal_input.NextEvent();

    if (e.type == EventType::QUIT) {
      SessionStorage::Save(stopwatch.GetCurrentSession(),
                           ConsoleSessionIO::PromptForFileName());

      running = false;
      continue;
    }

    if (e.type != EventType::NONE) {
      stopwatch.HandleEvent(e);
    }
  }

  return 0;
}
