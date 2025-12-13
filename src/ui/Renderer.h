//
// Created by Ethan Heckard on 12/10/25.
//

#ifndef TIMER_SYSTEM_RENDERER_H
#define TIMER_SYSTEM_RENDERER_H

#include "../../src/core/StopWatch.h"

class Renderer {
 public:
  virtual ~Renderer() = default;
  virtual void Render(const StopWatch& sw) = 0;
};

#endif  // TIMER_SYSTEM_RENDERER_H
