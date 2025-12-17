//
// Created by Ethan Heckard on 12/13/25.
//

#ifndef TIMER_SYSTEM_IMGUIUI_H
#define TIMER_SYSTEM_IMGUIUI_H

#include "../IUserInterface.h"

class ImGuiUI : public IUserInterface {
 public:
  int Run(StopWatch& sw) override;
  static void PushIfClicked(std::vector<Event>& events, const char* label,
                            EventType type);
};

#endif  // TIMER_SYSTEM_IMGUIUI_H
