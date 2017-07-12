#ifndef _APPBASE_GAMEACCESS
#define _APPBASE_GAMEACCESS

template<typename GAME>
class GameAccess {
public:
  GAME* aGame() { return _pGame; }
  GAME& rGame() { return *_pGame; }
  void aGame(GAME* pGame_) { _pGame = pGame_; }

private:
  GAME* _pGame;
};

#endif
