#include "pch.h"
#include "tetrisApp.h"
#include "sdl/usdl.h"

void TetrisApp::initialize() {

  _evalTick.interval(10);
  _renderTick.interval(10);


  int iRes = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS);
  std::cout << iRes << "\n";

  _pWindow = SDL_CreateWindow(
    "SDL",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    400,
    400,
    SDL_WINDOW_SHOWN);
  
  //_pRender = SDL_CreateRenderer(_pWindow, -1, SDL_RENDERER_ACCELERATED);
  _pRender = SDL_CreateRenderer(_pWindow, -1, 0);

}

void TetrisApp::startThreads() {
  //std::thread t1(&Application::inputLoop, this);
  std::thread t2(&Application::renderLoop, this);
  std::thread t3(&Application::evaluateLoop, this);

  //t1.join();
  inputLoop();
  t2.join();
  t3.join();
}

void TetrisApp::evaluateLoop() {
  std::cout << "Tetris::evaluateLoop\n";
  while (true) {
    if (_exit) {
      break;
    }
    if (!_evalTick.pass()) {
      continue;
    }
    auto optEvent = _rawEvents.get();
    if (optEvent) {
      SKeyEvent& e = *optEvent;
      if (e.sym==113) {
        triggerExit();
      }
    }
  }
  std::cout << "Tetris::evaluateLoop exit\n";
}


void TetrisApp::inputLoop() {
  std::cout << "Tetris::inputLoop\n";
  SDL_Event event;
  while (true) {
    if (_exit) {
      break;
    }
    if (!_renderTick.pass()) {
      continue;
    }
    if (SDL_WaitEvent(&event)==0) {
      continue;
    }
    if (event.type==SDL_QUIT) {
      break;
    }

    if (event.type==SDL_KEYDOWN) {
      //std::cout << "keydown\n";
      std::cout << event.key.keysym.sym << "\n";
      _rawEvents.put(usdl::fromSDLKeyEvent(event));

    //} else if (event.type==SDL_KEYUP) {
      //std::cout << "keyup\n";
    }
  }
  std::cout << "Tetris::inputLoop exit\n";
}

void TetrisApp::renderLoop() {

  std::cout << "Tetris::renderLoop\n";
  int y = 0;

  SDL_Surface* pSurface = SDL_LoadBMP("/home/steve/turtle.bmp");
  SDL_Texture* pTx = SDL_CreateTextureFromSurface(_pRender, pSurface);
  SDL_FreeSurface(pSurface);
  if (pSurface==NULL) {
    std::cout << "NULL pSurface\n";
  }

  do {
    if (_exit) {
      break;
    }
    y = y+1;
    if (y>400) {
      y = 0;
    }

    SDL_SetRenderDrawColor(_pRender, 0, 0, 0, 255);
    SDL_RenderClear(_pRender);
  
    SDL_RenderCopy(_pRender, pTx, NULL, NULL);

    SDL_SetRenderDrawColor(_pRender, 255, 0, 0, 255);
    SDL_Rect rect;
    rect.x=10;
    rect.y=y;
    rect.w=100;
    rect.h=50;
    SDL_RenderFillRect(_pRender, &rect);

    SDL_RenderPresent(_pRender);
  } while (true);
  std::cout << "Tetris::renderLoop exit\n";
}

void TetrisApp::dispose() {
  //SDL_DestroyRenderr(_pRender);
  //SDL_DestoryWindow(_pWindow);
  SDL_Quit(); 
}
