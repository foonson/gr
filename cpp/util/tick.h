#ifndef _UTIL_TICK
#define _UTIL_TICK

#include "pch.h"
#include "utime.h"

class Tick {
public:
  Tick();
  Tick(long interval_);
  bool operator()() { return pass(); }
  void interval(long interval_);
  long interval();
  bool pass();
  void sleep();
  void force();

private:
  long _interval;  
  stdTime _last;

};

#endif
