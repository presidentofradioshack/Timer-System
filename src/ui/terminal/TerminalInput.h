//
// Created by Ethan Heckard on 12/10/25.
//

#ifndef TIMER_SYSTEM_TERMINALINPUT_H
#define TIMER_SYSTEM_TERMINALINPUT_H
#include <iostream>

#include "../InputSource.h"

struct TerminalInput : public InputSource {
 public:
  Event NextEvent() override {
    std::cout << "[s]tart, s[t]op, [r]eset, [l]ap, [o]pen, [q]uit > ";

    std::string line;

    if (!std::getline(std::cin, line)) {
      return Event{EventType::QUIT};
    }

    if (line.empty()) {
      return Event{EventType::NONE};
    }

    switch (line[0]) {
      case 's':
        return Event{EventType::START};
        break;
      case 't':
        return Event{EventType::STOP};
        break;
      case 'r':
        return Event{EventType::RESET};
        break;
      case 'l':
        return Event{EventType::LAP};
        break;
      case 'q':
        return Event{EventType::QUIT};
        break;
      case 'o':
        return Event{EventType::LOAD};
        break;
      default:
        return Event{EventType::NONE};
        break;
    }
  }
};

#endif  // TIMER_SYSTEM_TERMINALINPUT_H
