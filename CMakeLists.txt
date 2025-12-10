cmake_minimum_required(VERSION 4.0)
project(timer_system)

set(CMAKE_CXX_STANDARD 23)

add_executable(timer_system main.cpp
        StopWatch.h
        Session.h
        Lap.h)
