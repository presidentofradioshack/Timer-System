//
// Created by Ethan Heckard on 12/12/25.
//

#ifndef TIMER_SYSTEM_STRINGUTILS_H
#define TIMER_SYSTEM_STRINGUTILS_H

#include <iostream>
#include <string>
using Milliseconds = std::chrono::milliseconds;

struct StringUtils {
 public:
  static std::vector<const std::string> Explode(const std::string& string,
                                                const std::string& delimiter) {
    std::vector<const std::string> tokens;
    size_t start = 0;
    size_t end = 0;

    while ((end = string.find(delimiter, start)) != std::string::npos) {
      tokens.push_back(string.substr(start, end - start));

      start = end + delimiter.length();
    }

    tokens.push_back(string.substr(start));

    return tokens;
  }

  static Milliseconds GetMillisecondsFromString(const std::string& string) {
    const size_t colon_pos = string.find(':');
    const size_t dot_pos = string.find('.');

    if (colon_pos == std::string::npos || dot_pos == std::string::npos) {
      throw std::runtime_error("Bad time format\n");
    }

    int min = std::stoi(string.substr(0, colon_pos));
    int sec =
        std::stoi(string.substr(colon_pos + 1, dot_pos - (colon_pos + 1)));
    int ms = std::stoi(string.substr(dot_pos + 1));

    Milliseconds minutes(min * 60'000);
    Milliseconds seconds(sec * 1'000);
    Milliseconds milliseconds(ms);

    Milliseconds total_time_elapsed = minutes + seconds + milliseconds;

    return total_time_elapsed;
  }
};

#endif  // TIMER_SYSTEM_STRINGUTILS_H
