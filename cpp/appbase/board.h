#ifndef _APPBASE_BOARD
#define _APPBASE_BOARD

#include "pch.h"

template<typename T, typename COLOR>
class Board {
public:
  Board() {
  }

  void initialize(XY<int> side_) {
    _side = side_;
    _board.resize(_side.x() * _side.y());
    _color.resize(_side.x() * _side.y());
  } 

  T& operator()(int x_, int y_) { return board(x_, y_); }

  COLOR& color(int x_, int y_) { return _color[x_ + y_*_side.x()]; }
  T& board(int x_, int y_) { return _board[x_ + y_ * _side.x()]; }

private:
  XY<int> _side;
  std::vector<T> _board;
  std::vector<COLOR> _color;

};

#endif
