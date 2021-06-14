#ifndef TETRIS_TSDL
#define TETRIS_TSDL

#include "pch.h"
#include "sdl/sdl.h"

namespace tetris {
//class TSDL : public SDL<TSDL> {
class TSDL : public SDL {

public:

  TSDL() {
    _iSquareWidth = 15;
  }

  ~TSDL() {}
  void initialize() {

    int iRes = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
    std::cout << iRes << "\n";

    _pWindow = SDL_CreateWindow(
      "TETRIS",
      SDL_WINDOWPOS_UNDEFINED,
      SDL_WINDOWPOS_UNDEFINED,
      800,
      500,
      SDL_WINDOW_SHOWN);
  
    //_pRender = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED);
    _pRenderer = SDL_CreateRenderer(_pWindow, -1, 0);


    //SDL_Surface* pSurface = SDL_LoadBMP("/home/steve/turtle.bmp");
    SDL_Surface* pSurface = IMG_Load("/Users/steve/background.jpg");
    _pTxBackground = SDL_CreateTextureFromSurface(renderer(), pSurface);
    SDL_FreeSurface(pSurface);

  }

  void dispose() {
    //SDL_DestroyRenderr(_pRender);
    //SDL_DestoryWindow(_pWindow);
    SDL_Quit(); 
  }


  SDL_Texture* txBackground() { return _pTxBackground; }

  int _iSquareWidth;
  SDL_Texture* _pTxBackground;
  

};
} // namespace tetris
#endif
