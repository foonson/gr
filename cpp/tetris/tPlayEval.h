#ifndef _TETRIS_PLAYEVAL
#define _TETRIS_PLAYEVAL

#include "appbase/eval.h"
#include "appbase/eventListener.h"
#include "appbase/keyEvent.h"
#include "appbase/playAccess.h"


namespace tetris {
class TPlay;
class TPlayEval : public Eval, public EventListener, public PlayAccess<TPlay>
{
public:
  TPlayEval() : Eval() {
    _speedDownCount = 0;
  }

  void initialize(TPlay& rPlay_);
  void evalImpl();
  void processKeyEvent(const SKeyEvent& event_);
  void resumeNormalSpeed();

private:
  int _speedDownCount; 
  int _normalSpeed;
  
};
}
#endif
