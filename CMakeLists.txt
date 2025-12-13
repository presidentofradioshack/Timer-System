cmake_minimum_required(VERSION 4.0)
project(timer_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(timer_system main.cpp
        src/core/StopWatch.h
        src/core/Session.h
        src/core/Lap.h
        src/core/Lap.cpp
        src/core/Session.cpp
        src/core/StopWatch.cpp
        src/events/Event.h
        src/ui/InputSource.cpp
        src/ui/InputSource.h
        src/ui/terminal/TerminalInput.h
        src/ui/Renderer.cpp
        src/ui/Renderer.h
        src/ui/terminal/TerminalRenderer.h
        src/storage/SessionStorage.h
        src/ui/terminal/ConsoleSessionIO.h
        src/utils/StringUtils.h)
