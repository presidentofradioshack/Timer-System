#ifndef TIMER_SYSTEM_SRC_EVENT_H
#define TIMER_SYSTEM_SRC_EVENT_H

enum class EventType { START, STOP, RESET, LAP, QUIT, NONE };

struct Event {
 public:
  EventType type{EventType::NONE};
};

#endif