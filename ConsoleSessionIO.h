//
// Created by Ethan Heckard on 12/11/25.
//

#ifndef TIMER_SYSTEM_CONSOLESESSIONIO_H
#define TIMER_SYSTEM_CONSOLESESSIONIO_H

#include <iostream>
#include <string>

struct ConsoleSessionIO {
 public:
  static std::string PromptForFileName() {
    std::string input;
    std::cout << "Enter name for your session: \n";
    std::cin >> input;
    return input;
  }

  static std::string PromptForLoadPath() {
    std::string input;
    std::cout << "Enter session name...\n";
    std::cin >> input;
    return input;
  }
};

#endif  // TIMER_SYSTEM_CONSOLESESSIONIO_H
