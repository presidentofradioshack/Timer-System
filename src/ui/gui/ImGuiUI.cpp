//
// Created by Ethan Heckard on 12/13/25.
//

#include "ImGuiUI.h"

#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

#include "../../src/events/Event.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

void ImGuiUI::PushIfClicked(std::vector<Event>& e, const char* label,
                            EventType type) {
  if (ImGui::Button(label)) {
    e.emplace_back(type);
  }
}

int ImGuiUI::Run(StopWatch& sw) {
  GLFWwindow* window;

  if (!glfwInit()) {
    return -1;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  window = glfwCreateWindow(640, 480, "Hello world", NULL, NULL);

  if (!window) {
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  // Setup Dear ImGui context
  IMGUI_CHECKVERSION();
  ImGui::CreateContext();
  ImGuiIO& io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard;  // Enable Keyboard Controls
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls

  // Setup Platform/Renderer backends
  ImGui_ImplGlfw_InitForOpenGL(
      window, true);  // Second param install_callback=true will install GLFW
  // callbacks and chain to existing ones.
  ImGui_ImplOpenGL3_Init();

  while (!glfwWindowShouldClose(window)) {
    glfwPollEvents();
    std::vector<Event> events;

    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("Stopwatch", nullptr, ImGuiWindowFlags_MenuBar);

    if (ImGui::BeginMenuBar()) {
      if (ImGui::BeginMenu("File")) {
        if (ImGui::MenuItem("Open", "Ctrl+O")) {
        }
        if (ImGui::MenuItem("Save", "Ctrl+S")) {
        }
        ImGui::EndMenu();
      }
      ImGui::EndMenuBar();
    }

    PushIfClicked(events, "Start", EventType::START);
    PushIfClicked(events, "Stop", EventType::STOP);
    PushIfClicked(events, "Lap", EventType::LAP);
    PushIfClicked(events, "Reset", EventType::RESET);

    ImGui::End();

    ImGui::Render();

    for (const Event& event : events) {
      sw.HandleEvent(event);
    }

    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    glfwSwapBuffers(window);
  }

  ImGui_ImplOpenGL3_Shutdown();
  ImGui_ImplGlfw_Shutdown();
  ImGui::DestroyContext();
  glfwTerminate();
}