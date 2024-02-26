#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
 * Creates a window for the program
 */
class Window {
public:
  Window();
  ~Window();
  void Loop();

private:
  void Start();
  void Update();
  void Input();
  void Render();
  void GenBuffers();

  GLFWwindow *_window;
  unsigned int _buffer;
};
