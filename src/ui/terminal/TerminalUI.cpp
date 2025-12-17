//
// Created by Ethan Heckard on 12/13/25.
//

#include "TerminalUI.h"

#include "../../storage/SessionStorage.h"
#include "ConsoleSessionIO.h"

int TerminalUI::Run(StopWatch& sw) {
  bool running{true};

  while (running) {
    renderer_.Render(sw);

    Event e = input_.NextEvent();

    if (e.type == EventType::QUIT) {
      SessionStorage::Save(sw.GetCurrentSession(),
                           ConsoleSessionIO::PromptForFileName());

      running = false;
      continue;
    }

    if (e.type == EventType::LOAD) {
      const std::string file_name = ConsoleSessionIO::PromptForLoadPath();
      const Session session = SessionStorage::Load(file_name);

      session.DisplayLapInfo();
      sw.LoadSession(session);
      continue;
    }

    if (e.type != EventType::NONE) {
      sw.HandleEvent(e);
    }
  }

  return 0;
}