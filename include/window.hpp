#ifndef WINDOW
#define WINDOW

#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>

/*
 * Creates a window for the program
 */
class Window {
public:
  Window();
  ~Window();
  SDL_Window *GetSDLWindow();

private:
  SDL_Window *window;
};

#endif
