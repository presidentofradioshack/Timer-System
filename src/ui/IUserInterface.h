#pragma once

#include "../../src/core/StopWatch.h"

class IUserInterface {
 public:
  virtual ~IUserInterface() = default;
  virtual int Run(StopWatch& sw) = 0;
};