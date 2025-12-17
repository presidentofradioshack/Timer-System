//
// Created by Ethan Heckard on 12/13/25.
//

#ifndef TIMER_SYSTEM_IMGUIRENDERER_H
#define TIMER_SYSTEM_IMGUIRENDERER_H

#include "../Renderer.h"

class ImGuiRenderer : public Renderer {
 public:
  void Render(StopWatch& sw, std::vector<Event>& out_events);
};

#endif  // TIMER_SYSTEM_IMGUIRENDERER_H
