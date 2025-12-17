#include <iostream>

#include "src/core/StopWatch.h"
#include "src/ui/gui/ImGuiUI.h"
#include "src/ui/terminal/TerminalInput.h"
#include "src/ui/terminal/TerminalRenderer.h"

int main() {
  StopWatch stopwatch;
  TerminalInput terminal_input;
  TerminalRenderer terminal;
  ImGuiUI gui;
  gui.Run(stopwatch);
}
