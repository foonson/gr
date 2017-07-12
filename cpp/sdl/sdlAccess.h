#ifndef _SDL_SDLACCESS
#define _SDL_SDLACCESS

template<typename T_SDL>
class SDLAccess {
public:
  T_SDL* aSDL() { return _pSDL; }
  T_SDL& rSDL() { return *_pSDL; }
  void aSDL(T_SDL* pSDL_) { _pSDL = pSDL_; }

private:
  T_SDL* _pSDL;
};

#endif
