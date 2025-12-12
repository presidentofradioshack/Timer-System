//
// Created by Ethan Heckard on 12/11/25.
//

#ifndef TIMER_SYSTEM_SESSIONSTORAGE_H
#define TIMER_SYSTEM_SESSIONSTORAGE_H

#include <filesystem>
#include <fstream>
#include <iostream>

#include "Session.h"

class SessionStorage {
 public:
  SessionStorage() = default;

  static void Save(const Session& session, const std::string& name) {
    // TODO: name validation
    namespace fs = std::filesystem;

    fs::path dir_path{"../sessions"};

    if (!fs::is_directory(dir_path)) {
      std::cout << "Creating sessions directory\n";
      fs::create_directory(dir_path);
    }

    std::string file_name = name + ".txt";
    fs::path file_path = dir_path / file_name;
    std::ofstream output_file(file_path);

    if (output_file.is_open()) {
      output_file << std::format("Session: {}\n", name);

      for (const Lap& lap : session.GetLaps()) {
        output_file << std::format("Lap {}: {}\n", lap.GetIndex(),
                                   lap.GetTotalTimeElapsed());
      }

      output_file.close();
      std::cout << std::format("File saved to {}.txt\n", name);
    } else {
      std::cerr << "Unable to open file\n";
    }
  }

  static Session& Load(const std::string& file_path) {
    // check for sessions folder
    // if it doesn't exist make it
    // look for file
  }
};

#endif  // TIMER_SYSTEM_SESSIONSTORAGE_H
