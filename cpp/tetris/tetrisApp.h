#ifndef TETRIS_TETRISAPP
#define TETRIS_TETRISAPP

#include "pch.h"
#include "appbase/application.h"
#include "util/syncQueue.h"
#include "appbase/keyEvent.h"

class TetrisApp : public Application {

public:
  virtual void initialize();
  virtual void startThreads();
  virtual void dispose();
  virtual void inputLoop();
  virtual void renderLoop();
  virtual void evaluateLoop();

private:
  SDL_Window* _pWindow;
  SDL_Renderer* _pRender;
  SyncQueue<SKeyEvent> _rawEvents;


};

#endif
