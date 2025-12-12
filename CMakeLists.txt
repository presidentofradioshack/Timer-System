cmake_minimum_required(VERSION 4.0)
project(timer_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(timer_system main.cpp
        StopWatch.h
        Session.h
        Lap.h
        Lap.cpp
        Session.cpp
        StopWatch.cpp
        Event.h
        InputSource.cpp
        InputSource.h
        TerminalInput.h
        Renderer.cpp
        Renderer.h
        TerminalRenderer.cpp
        TerminalRenderer.h
        SessionStorage.cpp
        SessionStorage.h
        ConsoleSessionIO.h
        Utils/StringUtils.h)
