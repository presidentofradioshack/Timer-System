//
// Created by Ethan Heckard on 12/11/25.
//

#ifndef TIMER_SYSTEM_SESSIONSTORAGE_H
#define TIMER_SYSTEM_SESSIONSTORAGE_H

#include <chrono>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <system_error>

#include "../core/Session.h"
#include "../utils/StringUtils.h"
namespace fs = std::filesystem;

class SessionStorage {
 public:
  SessionStorage() = default;

  static void Save(const Session& session, const std::string& name) {
    // TODO: name validation

    fs::path dir_path{"../sessions"};

    if (!fs::is_directory(dir_path)) {
      std::cout << "Creating sessions directory\n";
      fs::create_directory(dir_path);
    }

    // TODO: check if file with matching name already exists

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

  static Session Load(const std::string& file_name) {
    const fs::path dir_path = "../sessions";

    try {
      if (!fs::is_directory(dir_path)) {
        std::error_code ec =
            std::make_error_code(std::errc::no_such_file_or_directory);
        throw fs::filesystem_error("Sessions folder does not exist", dir_path,
                                   ec);
      }

      auto directory_iterator = fs::directory_iterator(dir_path);
      auto end_iterator = fs::end(directory_iterator);

      auto found = std::find_if(directory_iterator, end_iterator,
                                [&file_name](const auto& entry) {
                                  return entry.path().stem() == file_name;
                                });

      if (found != end_iterator) {
        std::cout << "File found!\n";

        fs::path file_path = dir_path / (file_name + ".txt");

        std::string line;
        std::ifstream file(file_path);

        if (file.is_open()) {
          std::vector<Lap> laps;
          std::vector<std::string> parts;

          while (std::getline(file, line)) {
            const std::string lap_str = "Lap ";
            std::size_t pos = line.find(lap_str);

            if (pos != std::string::npos) {
              using Milliseconds = std::chrono::milliseconds;

              auto string_parts = StringUtils::Explode(line, ": ");
              const std::string& time_string = string_parts[1];
              const size_t colon_pos = time_string.find(':');

              int index = std::stoi(line.substr(lap_str.length(), colon_pos));

              Milliseconds total_time_elapsed =
                  StringUtils::GetMillisecondsFromString(time_string);

              laps.emplace_back(index, total_time_elapsed);
            }
          }

          file.close();

          std::cout << "Session loaded successfully!\n";
          Session loaded_session(laps);
          return loaded_session;
        } else {
          std::cerr << "Unable to open file\n";
        }
      } else {
        std::cout << "No file found\n";
      }
    } catch (const fs::filesystem_error& e) {
      std::cerr << "Caught filesystem_error: " << e.what() << std::endl;
    }
  }
};

#endif  // TIMER_SYSTEM_SESSIONSTORAGE_H
