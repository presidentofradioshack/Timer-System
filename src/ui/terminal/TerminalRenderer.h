//
// Created by Ethan Heckard on 12/10/25.
//

#ifndef TIMER_SYSTEM_TERMINALRENDERER_H
#define TIMER_SYSTEM_TERMINALRENDERER_H
#include <iostream>

#include "../../../src/core/StopWatch.h"
#include "../Renderer.h"

class TerminalRenderer final : public Renderer {
 public:
  void Render(StopWatch& stopwatch) override {
    std::cout << "Terminal rendering\n";
  }
};

#endif  // TIMER_SYSTEM_TERMINALRENDERER_H
