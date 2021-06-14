#include "tPlay.h"
#include "tGame.h"
#include "tApp.h"

namespace tetris {
void TPlay::initialize(TApp& rApp_, TGame& rGame_, const XY<int>& dim_) {
  aApp(&rApp_);
  aGame(&rGame_);

  dim(dim_);
  _board.initialize(dim_);
  newShape();

  _tPlayEval.initialize(*this);
  _tPlayEval.interval(1000);

  _tPlaySDLRender.initialize(rApp().rSDL(), rGame(), *this);

}

void TPlay::newShape() {
  auto& vShapes = rGame()._vShapes;
  //srand()
  _pShapeSet = &(vShapes[(iShapeIndex++) % vShapes.size()]);
  //_pShapeSet = &(vShapes[rand()% vShapes.size()]);
  _pShape = &(_pShapeSet->rotate());
  _xy(dim().x()/2, _pShape->org().y());


  if (!tryMove(_xy, *_pShape)) {
    _tPlayEval.enabled(false);
  }
}

void TPlay::rotate() {
  //printf("rotate\n");
  _pShape = &(_pShapeSet->rotate());
}

void TPlay::land() {
  
  const Shape& rs = rShape();
  const XY<int>& rOrg = rs.org();
  int cx = xy().x() - rOrg.x();
  int cy = xy().y() - rOrg.y();
  for (size_t i=0;i<rs.size();i++) {
    if (rs[i]==0) {
      continue;
    }
    int dx = rs.x(i);
    int dy = rs.y(i);
    int x = cx+dx;
    int y = cy+dy;
    //printf("%d %d\n", x, y);
    _board(x, y) = 'x';
    _board.color(x, y) = rShapeSet().color();
  }


  int mark = 0;
  for (int y=0;y<dim().y();y++) {
    int fillCount = 0;
    for (int x=0;x<dim().x();x++) {
      if (_board(x, y)!='x') {
        continue;
      }
      fillCount++;
    }
    if (fillCount==dim().x()) {
      mark++;
      for (int y1=y;y1>0;y1--) {
        for (int x1=0;x1<dim().x();x1++) {
          _board(x1, y1) = _board(x1, y1-1); 
          _board.color(x1, y1) = _board.color(x1, y1-1); 
        }
      }
    }
  }

  int delta = 0;
  if (mark==1) { delta = 10; }
  else if (mark==2) { delta = 40; }
  else if (mark==3) { delta = 90; }
  else if (mark==4) { delta = 200; }
  else { delta = 1;}
  _score += delta;
  _line += mark;

  int speed = 1000 - _line * 50;
  if (speed<200) { speed = 200; }
  _tPlayEval.interval(speed); 

  //if (mark>0) {
    printf("%s: +%d [%d]\n", _name.c_str(), delta, _score);
  //}
  
}


bool TPlay::tryMove(const XY<int>& xy_, const Shape& shape_) {
  const XY<int>& rOrg = shape_.org();
  int cx = xy_.x() - rOrg.x();
  int cy = xy_.y() - rOrg.y();

  auto& b = board();
  //printf("%d %d\n", shape_.dim().x(), shape_.dim().y());
  for (size_t i=0;i<shape_.size();i++) {
    if (shape_[i]==0) {
      continue;
    }
    int dx = shape_.x(i);
    int dy = shape_.y(i);
    int x = cx+dx;
    int y = cy+dy;

    if (b(x, y)=='x') {
      return false;
    }

    //printf("%d %d\n", x, y);
    if (x<0) return false;
    if (x>=dim().x()) return false;
    if (y>=dim().y()) return false;
    //drawRect(cx+dx, cy+dy, square, rShapes.color());
  }
  return true;
}

} // namespace
