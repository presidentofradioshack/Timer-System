#include <iostream>

#include "src/core/Session.h"
#include "src/core/StopWatch.h"
#include "src/events/Event.h"
#include "src/storage/SessionStorage.h"
#include "src/ui/terminal/ConsoleSessionIO.h"
#include "src/ui/terminal/TerminalInput.h"
#include "src/ui/terminal/TerminalRenderer.h"

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

    if (e.type == EventType::LOAD) {
      const std::string file_name = ConsoleSessionIO::PromptForLoadPath();
      const Session session = SessionStorage::Load(file_name);

      session.DisplayLapInfo();

      stopwatch.LoadSession(session);
    }

    if (e.type != EventType::NONE) {
      stopwatch.HandleEvent(e);
    }
  }

  return 0;
}
