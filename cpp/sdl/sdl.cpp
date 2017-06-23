
#include "pch.h"
#include "sdl.h"

SDL::SDL() {
  /*
  std::cout << "sdl ctor" << std::endl; 
  int iRes = SDL_Init(SDL_INIT_VIDEO);

  SDL_Window* pWindow = SDL_CreateWindow(
    "SDL",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    400,
    400,
    SDL_WINDOW_SHOWN);

  SDL_Delay(2000);
  */
}



SDL::~SDL() {
  std::cout << "sdl dtor" << std::endl; 
  //SDL_Quit();
}

