#ifndef _SDL_USDL_H
#define _SDL_USDL_H

#include "pch.h"
#include "appbase/keyEvent.h"

namespace usdl {

  SKeyEvent fromSDLKeyEvent(const SDL_Event& e_) {
    SKeyEvent e;
    e.sym = e_.key.keysym.sym;
    return e;
  }

}

#endif
