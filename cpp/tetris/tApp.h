#ifndef TETRIS_TAPP
#define TETRIS_TAPP

#include "pch.h"
#include "appbase/application.h"
#include "util/syncQueue.h"
#include "appbase/keyEvent.h"

#include "tGame.h"
#include "sdl/sdlAccess.h"
#include "tSDL.h"
#include "util/tick.h"

// if class memeber is reference, it must initialize at contructor

namespace tetris {
class TApp : public Application, public SDLAccess<TSDL> {

public:

  TApp();
  virtual void initialize();
  virtual void startThreads();
  virtual void dispose();
  virtual void inputLoop();
  virtual void renderLoop();
  virtual void evaluateLoop();
  

private:
  TSDL _tSDL;
  SyncQueue<SKeyEvent> _rawEvents;

  TGame _tGame;
  Tick _tickRender;

};
} // namespace tetris
#endif
