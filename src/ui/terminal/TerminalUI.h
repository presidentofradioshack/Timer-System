//
// Created by Ethan Heckard on 12/13/25.
//

#ifndef TIMER_SYSTEM_TERMINALUI_H
#define TIMER_SYSTEM_TERMINALUI_H
#include "../IUserInterface.h"
#include "TerminalInput.h"
#include "TerminalRenderer.h"

class TerminalUI final : public IUserInterface {
 public:
  int Run(StopWatch& sw) override;

 private:
  TerminalInput input_;
  TerminalRenderer renderer_;
};

#endif  // TIMER_SYSTEM_TERMINALUI_H
