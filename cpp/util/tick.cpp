#include "tick.h"
#include <thread>  // this_thread::sleep

Tick::Tick() {
  _interval = 0;
}

Tick::Tick(long interval_) {
  _interval = interval_;
}

void Tick::interval(long interval_) {
  _interval = interval_;
}

long Tick::interval() {
  return _interval;
}

bool Tick::pass() {
  if (_interval==0) return true;
  if (UTime::pass(_last, _interval)) {
    _last = UTime::now();
    return true;
  }
  return false;
}

void Tick::sleep() {
  // TODO sleep residual time
  std::this_thread::sleep_for(std::chrono::milliseconds(_interval));
}

void Tick::force() {
  _last = UTime::now();
}
