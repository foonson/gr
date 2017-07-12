#ifndef _APPBASE_XY
#define _APPBASE_XY

#include "pch.h"

template<typename T=int>
class XY {
public:
  XY() {};
  XY(T x_, T y_) { _x = x_ ; _y = y_; }
  XY(const XY<T>& xy_) { xy(xy_); }

  void operator()(T x_, T y_) { xy(x_, y_); }
  void operator()(const XY<T>& xy_) { xy(xy_); }


  friend bool operator<(const XY<T>& l_, const XY<T>& r_) {
    if (l_._y < r_._y) return true;
    if (l_._y > r_._y) return false;
    return (l_._x < r_._x);
  }

  bool operator==(const XY<T>& other_) {
    if (_x!=other_._x) return false;
    return _y!=other_._y;
  }

  //XY& operator+=(const XY& xy_) {
  //  _x += xy_.x();
  //  _y += xy_.y();
  //  return *this;
  //}

  void x(T x_) { _x = x_; }
  void y(T y_) { _y = y_; }
  void xy(T x_, T y_) { _x = x_; _y = y_; }
  void xy(const XY<T>& xy_) { _x = xy_._x; _y = xy_._y; }
  //bool touching(const XY& xy_);
  //bool touching(T x_, T y_);

  //virtual string toString() const;
  T x() const { return _x; }
  T y() const { return _y; }

  //static XY random(const XY& max);
  //static XY random(const XY& min, const XY& max);

//protected:
  T _x;
  T _y;

};

/*
typedef vector<XY> XYs;
typedef set<XY> XYSet;

class XYZ {
public:
  XYZ(int x_, int y_, int z_);
  XYZ(const XYZ& xyz_);
  void xyz(int x_, int y_, int z_);
  bool touching(const XYZ& xyz_);
  bool touching(int x_, int y_, int z_);
  bool touchingXY(int x_, int y_);
  bool touchingXY(const XY& xy_);

protected:
  int _x;
  int _y;
  int _z;
};
*/
#endif
