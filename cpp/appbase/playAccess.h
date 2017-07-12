#ifndef _APPBASE_PLAYACCESS
#define _APPBASE_PLAYACCESS

template<typename PLAY>
class PlayAccess {
public:
  PLAY* aPlay() { return _pPlay; }
  PLAY& rPlay() { return *_pPlay; }
  void aPlay(PLAY* pPlay_) { _pPlay = pPlay_; }

private:
  PLAY* _pPlay;
};

#endif
