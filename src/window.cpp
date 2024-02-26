#include "window.hpp"
#include <GL/glew.h>
#include <iostream>

Window::Window() { Start(); }

Window::~Window() {
  glfwDestroyWindow(_window);
  glfwTerminate();
}

void Window::Start() {
  if (!glfwInit()) {
    // initialization failed
    std::cout << "ERROR: glfw initialization failed" << std::endl;
  }

  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

  _window = glfwCreateWindow(640, 480, "My Window", NULL, NULL);

  if (!_window) {
    // window init failed
    std::cout << "ERROR: Window initialization failed" << std::endl;
  }

  glfwMakeContextCurrent(_window);

  GLenum err = glewInit();
  // TODO: Fix glewInit not working
  if (err != GLEW_OK) {
    // std::cout << "ERROR: " << glewGetErrorString(err) << std::endl;
  }

  std::cout << glGetString(GL_VERSION) << std::endl;
}

void Window::Loop() {
  GenBuffers();
  while (!glfwWindowShouldClose(_window)) {
    Update();
    Render();
    Input();
  }
}

void Window::Input() { glfwPollEvents(); }

void Window::Update() {}

void Window::Render() {
  glClear(GL_COLOR_BUFFER_BIT);

  glDrawArrays(GL_TRIANGLES, 0, 3);

  glfwSwapBuffers(_window);
}

void Window::GenBuffers() {
  float positions[6] = {-0.5f, -0.5f, 0.0f, 0.5f, 0.5f, -0.5f};

  // Generate buffer and bind it
  glGenBuffers(1, &_buffer);
  glBindBuffer(GL_ARRAY_BUFFER, _buffer);
  glBufferData(GL_ARRAY_BUFFER, 6 * sizeof(float), positions, GL_STATIC_DRAW);

  // Specify the vertex attributes
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,
                        (const void *)0);
}
