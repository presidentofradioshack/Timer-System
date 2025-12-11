//
// Created by Ethan Heckard on 12/10/25.
//

#ifndef TIMER_SYSTEM_INPUTSOURCE_H
#define TIMER_SYSTEM_INPUTSOURCE_H

#include "Event.h"

class InputSource {
 public:
  virtual ~InputSource() = default;
  virtual Event NextEvent() = 0;
};

#endif  // TIMER_SYSTEM_INPUTSOURCE_H
