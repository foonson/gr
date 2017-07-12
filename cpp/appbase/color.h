#ifndef _APPBASE_COLOR
#define _APPBASE_COLOR

#include "pch.h"

class Color {

public:
  Color() {
    _r = 0;
    _b = 0;
    _g = 0;
    _a = 0;
  }

  Color(int r_, int g_, int b_, int a_) {
    _r = r_;
    _g = g_;
    _b = b_;
    _a = a_;
  }

  void operator()(int r_, int b_, int g_, int a_) {
    _r = r_;
    _g = g_;
    _b = b_;
    _a = a_;
  }

  int r() const { return _r; }
  int g() const { return _g; }
  int b() const { return _b; }
  int a() const { return _a; }

  void r(int r_) { _r = r_; }
  void g(int g_) { _g = g_; }
  void b(int b_) { _b = b_; }
  void a(int a_) { _a = a_; }

private:
  int _r;
  int _g;
  int _b;
  int _a;

};

#endif
