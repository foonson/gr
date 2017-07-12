#ifndef _APPBASE_TICKABLE
#define _APPBASE_TICKABLE

#include "util/tick.h"

class Tickable {
public:
  void interval(long interval_) { _tick.interval(interval_); }
  long interval() { return _tick.interval(); }
  Tick& tick() { return _tick; }

protected:
  Tick _tick;

};

#endif
