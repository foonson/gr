#ifndef _TETRIS_TPLAY
#define _TETRIS_TPLAY

#include "pch.h"
#include "appbase/xy.h"
#include "appbase/gameAccess.h"
#include "appbase/appAccess.h"
#include "appbase/color.h"
#include "appbase/board.h"
#include "appbase/action.h"
#include "appbase/play.h"
#include "shape.h"
//#include "tGame.h"
#include "tPlayEval.h"
#include "tPlaySDLRender.h"
#include "util/ucollection.h"

namespace tetris {

class TGame;
class TApp;

class TPlay : public Play<ACTION>, private GameAccess<TGame>, AppAccess<TApp> {

public:
  TPlay() {
  }


  void initialize(TApp& rApp_, TGame& rGame_, const XY<int>& dim_);
  void newShape();
  void rotate();
  void land();

  bool tryMove(const XY<int>& xy_, const Shape& shape_);
  XY<int>& xy() { return _xy; }

  void dim(const XY<int>& dim_) { _dim = dim_; }
  const XY<int>& dim() { return _dim; }
  
  ShapeSet& rShapeSet() { return *_pShapeSet; }
  const Shape& rShape() { return *_pShape; }

  void name(const std::string& name_) { _name = name_; }

  Board<char, Color>& board() { return _board; }

  TPlayEval _tPlayEval;
  TPlaySDLRender _tPlaySDLRender;

private:

  Board<char, Color> _board; 
  XY<int> _xy;
  XY<int> _dim;
  
  ShapeSet* _pShapeSet;
  const Shape* _pShape;
  int iShapeIndex;
  int _score {0};
  int _line {0};
  std::string _name;

};
}

#endif
