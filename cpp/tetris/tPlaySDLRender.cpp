#include "tGame.h"
#include "tPlay.h"
#include "tPlaySDLRender.h"

namespace tetris {
void TPlaySDLRender::initialize(TSDL& rSDL_, TGame& rGame_, TPlay& rPlay_) {

  aSDL(&rSDL_);
  aGame(&rGame_);
  aPlay(&rPlay_);

  //if (pSurface==NULL) {
  //  std::cout << "NULL pSurface\n";
  //}

}

void TPlaySDLRender::drawRect(int x_, int y_, const XY<int>& side_, const Color& color_) {
  drawRect(XY<int>(x_, y_), side_, color_);
}

void TPlaySDLRender::drawRect(const XY<int>& xyLogic_, const XY<int>& side_, const Color& color_) {
  SDL_Renderer* pRenderer = renderer();
  SDL_SetRenderDrawColor(pRenderer, color_.r(), color_.g(), color_.b(), color_.a());
  SDL_Rect rect;
  rect.x = xyLogic_.x() * side_.x() + _span._offset.x();
  rect.y = xyLogic_.y() * side_.y() + _span._offset.y();
  rect.w = side_.x() - 1;
  rect.h = side_.y() - 1;
  //printf("%d %d %d %d\n", rect.x, rect.y, rect.w, rect.h);
  SDL_RenderFillRect(pRenderer, &rect);
}

bool TPlaySDLRender::renderImpl() {

  TPlay& rp = rPlay();
  int w = rSDL()._iSquareWidth;

  drawRect(0, 0, XY<int>(rp.dim().x()*w, rp.dim().y()*w), Color(0,0,0,0));

  XY<int> square = XY<int>(w, w);

  const Shape& rShape = rp.rShape();
  ShapeSet& rShapes = rp.rShapeSet();
  const XY<int>& rOrg = rShape.org();
  int cx = rp.xy().x() - rOrg.x();
  int cy = rp.xy().y() - rOrg.y();
  for (size_t i=0;i<rShape.size();i++) {
    if (rShape[i]==0) {
      continue;
    }
    int dx = rShape.x(i);
    int dy = rShape.y(i);
    drawRect(cx+dx, cy+dy, square, rShapes.color());
  }

  Board<char, Color>& board = rp.board();
  for (int y=0;y<rp.dim().y();y++) {
    for (int x=0;x<rp.dim().x();x++) {
      if (board.board(x, y)=='x') {
        drawRect(x, y, square, board.color(x, y));
      }
    }
  }

  return true;

}
}
