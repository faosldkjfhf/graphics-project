#pragma once

#include <GLFW/glfw3.h>

// TODO: Use GLFW

/*
 * Creates a window for the program
 */
class Window {
public:
  Window();
  ~Window();

private:
  GLFWwindow *_window;
};
