#ifndef _SDL_SDLRENDER
#define _SDL_SDLRENDER


#include "sdl.h"
#include "sdlAccess.h"
#include "appbase/render.h"

template <typename T_SDL>
class SDLRender : public Render, public SDLAccess<T_SDL> {

public:

  SDL_Renderer* renderer() { return SDLAccess<T_SDL>::rSDL().renderer(); }

};

#endif
