#ifndef _TETRIS_SHAPE
#define _TETRIS_SHAPE

#include <initializer_list>
#include "appbase/xy.h"
#include "appbase/color.h"

namespace tetris {

class Shape {
  
public:
  Shape(XY<int> org_, XY<int> dim_, std::initializer_list<int> v_) :
    _org(org_),
    _dim(dim_)
  {
    _v.insert(_v.end(), v_.begin(), v_.end());
  }

  const XY<int>& dim() const { return _dim; }
  const XY<int>& org() const { return _org; }
  int x(size_t u) const { return u % _dim.x(); }
  int y(size_t u) const { return u / _dim.x(); }
  int operator[](size_t u) const { return _v[u]; }
  size_t size() const { return _v.size(); }

private:
  std::vector<int> _v;

  XY<int> _org;
  XY<int> _dim;
};


class ShapeSet {
public:

  ShapeSet(std::initializer_list<Shape> v_) {
    _index = 0;
    _vShape.insert(_vShape.end(), v_.begin(), v_.end());
  }

  const Shape& rotate() {
    const Shape& s = _vShape[_index];
    _index = (_index+1) % _vShape.size();
    return s;
  }

  const Shape& tryRotate() {
    //int i = (_index+1) % _vShape.size();
    //printf("try rotate %d %d\n",i, _index);
    return _vShape[_index];
  }

  const Color& color() { return _color; }
  void color(const Color& color_) { _color = color_; }


private:
  std::vector<Shape> _vShape;
  int _index;
  Color _color;

};
} // namespace tetris
#endif
