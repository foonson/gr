#include "tPlayEval.h"
#include "tPlay.h"


namespace tetris {
void TPlayEval::initialize(TPlay& rPlay_) {
  aPlay(&rPlay_);
}

void TPlayEval::evalImpl() {

  TPlay& rp = rPlay();
  XY<int>& rxy = rp.xy();
  XY<int> xyTry = rxy;
  const Shape& rShape = rp.rShape();
  xyTry._y++;

  if (rp.tryMove(xyTry, rShape)) {
    rxy = xyTry;
  } else {
    rp.land();
    rp.newShape();
    resumeNormalSpeed();
  }
  if (_speedDownCount>0) {
    _speedDownCount--;
    if (_speedDownCount==0) {
      resumeNormalSpeed();
    }
  }
}

void TPlayEval::resumeNormalSpeed() {
  interval(_normalSpeed);
  _speedDownCount = 0;
}

void TPlayEval::processKeyEvent(const SKeyEvent& event_) {
  TPlay& rp = rPlay();
  XY<int>& rxy = rp.xy();
  XY<int> xyTry = rxy;
  const Shape* pShape = NULL;

  ACTION action = rp.action(event_.sym);

  bool move = false;
  bool rotate = false;
  if (action==ACTION::RIGHT) {
    xyTry._x++;
    pShape = &(rp.rShape());
    move = true;
  } else if (action==ACTION::LEFT) {
    xyTry._x--;
    pShape = &(rp.rShape());
    move = true;
  } else if (action==ACTION::UP) {
    pShape = &(rp.rShapeSet().tryRotate());
    rotate = true;
  } else if (action==ACTION::DOWN) {
    if (_speedDownCount==0) {
      _normalSpeed = interval();
      _speedDownCount = 15;
      interval(50);
    }
  }

  if (move||rotate) {
    if (rp.tryMove(xyTry, *pShape)) {
      if (move) {
        rxy = xyTry;
      }
      if (rotate) {
        rp.rotate();
      }
    }
  }
}
}
