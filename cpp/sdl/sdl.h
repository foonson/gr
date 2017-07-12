#ifndef _SDL_SDL_H
#define _SDL_SDL_H

#include "SDL.h"

//template <typename T>
class SDL {
public:
  SDL() {} ;
  virtual ~SDL() {};

  SDL_Window* window() { return _pWindow; }
  SDL_Renderer* renderer() { return _pRenderer; }

protected:
  SDL_Window* _pWindow;
  SDL_Renderer* _pRenderer;

};
#endif
