#ifndef _TETRIS_TPLAYSDLRENDER
#define _TETRIS_TPLAYSDLRENDER

#include "pch.h"
#include "sdl/sdl.h"
#include "sdl/sdlRender.h"
#include "sdl/sdlAccess.h"
#include "appbase/playAccess.h"
#include "appbase/gameAccess.h"
#include "tSDL.h"
//#include "tGame.h"
#include "appbase/xy.h"
#include "appbase/color.h"


class SDLSpan {
public:
  XY<int> _offset;
  XY<int> _side;
};

namespace tetris {

class TGame;
class TPlay;

class TPlaySDLRender : public SDLRender<TSDL>, 
                       public PlayAccess<TPlay>,
                       public GameAccess<TGame>
{

public:
  TPlaySDLRender() : SDLRender<TSDL>() { 
  }

  void initialize(TSDL& rSDL_, TGame& rGame_, TPlay& rPlay_);
  void drawRect(int x_, int y_, const XY<int>& side_, const Color& color_);
  void drawRect(const XY<int>& xyLogic_, const XY<int>& side_, const Color& color_);
  bool renderImpl();

  SDLSpan _span;
private:
  


};
}

#endif
