cmake_minimum_required(VERSION 4.0)
project(timer_system)

set(CMAKE_CXX_STANDARD 23)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

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
        src/utils/StringUtils.h
        src/ui/gui/ImGuiRenderer.cpp
        src/ui/gui/ImGuiRenderer.h
        external/imgui/backends/imgui_impl_glfw.cpp
        external/imgui/backends/imgui_impl_opengl3.cpp
        external/imgui/imgui.cpp
        external/imgui/imgui_draw.cpp
        external/imgui/imgui_widgets.cpp
        external/imgui/imgui_tables.cpp
        src/ui/IUserInterface.h
        src/ui/terminal/TerminalUI.h
        src/ui/terminal/TerminalUI.cpp
        src/ui/gui/ImGuiUI.cpp
        src/ui/gui/ImGuiUI.h
)

target_include_directories(timer_system PRIVATE
        external/imgui
        external/imgui/backends
        /opt/homebrew/include
)

target_link_libraries(timer_system PRIVATE glfw OpenGL::GL)
