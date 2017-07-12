#ifndef _TETRIS_TGAME
#define _TETRIS_TGAME

#include "pch.h"
#include <initializer_list>
#include "appbase/xy.h"
#include "appbase/action.h"
#include "appbase/appAccess.h"
#include "appbase/eval.h"
#include "appbase/render.h"
#include "appbase/eventListener.h"
#include "shape.h"
//#include "tApp.h"
#include "tPlay.h"

namespace tetris {

class TApp;

class TGame : private AppAccess<TApp>, public Eval, public Render, public EventListener  {
public:

  void initialize(TApp& rApp_) {
    aApp(&rApp_);

    for (auto& play: _tPlays) {
      play.initialize(rApp_, *this, XY<int>{10, 25});
    }

    TPlay& rp0 = _tPlays[0];
    TPlay& rp1 = _tPlays[1];
    TPlaySDLRender& rSDLr0 = rp0._tPlaySDLRender;
    TPlaySDLRender& rSDLr1 = rp1._tPlaySDLRender;

    rSDLr0._span._offset(20,  20);
    rSDLr1._span._offset(400, 20);
 
    rp0.mapKeyAction(119, ACTION::UP); // w
    rp0.mapKeyAction(97,  ACTION::LEFT); // a
    rp0.mapKeyAction(100, ACTION::RIGHT); // d
    rp0.mapKeyAction(115, ACTION::DOWN); // s

    rp1.mapKeyAction(1073741906, ACTION::UP); 
    rp1.mapKeyAction(1073741904, ACTION::LEFT); 
    rp1.mapKeyAction(1073741903, ACTION::RIGHT); 
    rp1.mapKeyAction(1073741905, ACTION::DOWN); 

    
  }

  TGame() {
    ShapeSet shapes1 = { 
      Shape( {1,1}, {3,2}, { 0,1,0,
                             1,1,1 } ),
      Shape( {0,1}, {2,3}, { 1,0,
                             1,1,
                             1,0 }   ),
      Shape( {1,0}, {3,2}, { 1,1,1,
                             0,1,0}  ),
      Shape( {1,1}, {2,3}, { 0,1,
                             1,1,
                             0,1 }   )
    };
    shapes1.color(Color(255, 0, 0, 0));
    _vShapes.push_back(shapes1);

    ShapeSet shapes2 = { 
      Shape( {1,1}, {3,2}, { 1,1,0,
                             0,1,1 } ),
      Shape( {1,1}, {2,3}, { 0,1,
                             1,1,
                             1,0 }   )
    };
    shapes2.color(Color(0, 255, 0, 0));
    _vShapes.push_back(shapes2);


    ShapeSet shapes3 = { 
      Shape( {1,1}, {3,2}, { 0,1,1,
                             1,1,0 } ),
      Shape( {1,1}, {2,3}, { 1,0,
                             1,1,
                             0,1 }   )
    };
    shapes3.color(Color(0, 0, 255, 0));
    _vShapes.push_back(shapes3);

    ShapeSet shapes4 = { 
      Shape( {1,1}, {3,2}, { 1,0,0,
                             1,1,1 } ),
      Shape( {1,1}, {2,3}, { 1,1,
                             1,0,
                             1,0 }   ),
      Shape( {1,1}, {3,2}, { 1,1,1,
                             0,0,1}  ),
      Shape( {1,1}, {2,3}, { 0,1,
                             0,1,
                             1,1 }   )
    };
    shapes4.color(Color(0, 255, 255, 0));
    _vShapes.push_back(shapes4);


    ShapeSet shapes5 = { 
      Shape( {1,1}, {3,2}, { 0,0,1,
                             1,1,1 } ),
      Shape( {1,1}, {2,3}, { 1,0,
                             1,0,
                             1,1 }   ),
      Shape( {1,1}, {3,2}, { 1,1,1,
                             1,0,0}  ),
      Shape( {1,1}, {2,3}, { 1,1,
                             0,1,
                             0,1 }   )
    };
    shapes5.color(Color(255, 0, 255, 0));
    _vShapes.push_back(shapes5);


    ShapeSet shapes6 = { 
      Shape( {1,0}, {4,1}, { 1,1,1,1 } ),
      Shape( {0,1}, {1,4}, { 1,
                             1,
                             1,
                             1 }   )
    };
    shapes6.color(Color(255, 255, 0, 0));
    _vShapes.push_back(shapes6);


    ShapeSet shapes7 = { 
      Shape( {0,0}, {2,2}, { 1,1,
                             1,1 }   )
    };
    shapes7.color(Color(127, 127, 0, 0));
    _vShapes.push_back(shapes7);


  }


  void processKeyEvent(const SKeyEvent& event_) {
    for (auto& play: _tPlays) {
      play._tPlayEval.processKeyEvent(event_);
    }
  }

  void evalImpl() {
    for (auto& play: _tPlays) {
      play._tPlayEval.eval();
    }
  }


  bool renderImpl() {
    bool needRender = false;
    for (auto& play: _tPlays) {
      if (play._tPlaySDLRender.render()) {
        needRender = true;
      }
    }
    return needRender;
  }

  std::vector<ShapeSet> _vShapes;

  TPlay _tPlays[2];



};
} // namespace tetris

#endif
