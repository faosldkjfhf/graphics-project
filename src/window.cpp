#include "window.hpp"

Window::Window() {
  if (!glfwInit()) {
    // initialization failed
  }

  _window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);

  if (!_window) {
    // window init failed
  }
}

Window::~Window() {
  glfwDestroyWindow(_window);
  glfwTerminate();
}
