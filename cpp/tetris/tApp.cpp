#include "tApp.h"
#include "sdl/usdl.h"

namespace tetris {

TApp::TApp() {
  aSDL(&_tSDL);
}

void TApp::initialize() {
  _tSDL.initialize();
  _tGame.initialize(*this);
  _tickRender.interval(40);
}

void TApp::dispose() {
  _tSDL.dispose();
}

void TApp::startThreads() {
  //std::thread t1(&Application::inputLoop, this);
  std::thread t2(&Application::renderLoop, this);
  std::thread t3(&Application::evaluateLoop, this);

  //t1.join();
  inputLoop();
  t2.join();
  t3.join();
}

void TApp::evaluateLoop() {
  std::cout << "Tetris::evaluateLoop\n";
  while (true) {
    if (_exit) {
      break;
    }
    //_evalTick.sleep();
    //if (!_evalTick.pass()) {
    //  continue;
    //}

    auto optEvent = _rawEvents.get();
    if (optEvent) {
      SKeyEvent& e = *optEvent;
      if (e.sym==113) {
        triggerExit();
      }
      _tGame.processKeyEvent(e);
    }
    _tGame.eval();

    //_tPlayEval.eval();
  }
  std::cout << "Tetris::evaluateLoop exit\n";
}


void TApp::inputLoop() {
  std::cout << "Tetris::inputLoop\n";
  SDL_Event event;
  while (true) {
    if (_exit) {
      break;
    }
    //if (!_renderTick.pass()) {
    //  continue;
    //}
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

void TApp::renderLoop() {

  std::cout << "Tetris::renderLoop\n";

  bool needRender = false;
  //bool renderClean = false;

  SDL_Renderer* pRenderer = _tSDL.renderer();

  do {
    if (_exit) {
      break;
    }

    if (!_tickRender()) {
      continue;
    }

    SDL_RenderCopy(pRenderer, rSDL().txBackground(), NULL, NULL);

    //if (!renderClean) {
      //SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255);
      //SDL_RenderClear(pRenderer);
      //renderClean = true;
      //needRender = true;
    //}


    if(_tGame.render()) {
      needRender = true;
    }

    if (needRender) {
      SDL_RenderPresent(pRenderer);
    }

  } while (true);
  std::cout << "Tetris::renderLoop exit\n";
}
}
