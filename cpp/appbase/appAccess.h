#ifndef _APPBASE_APPACCESS
#define _APPBASE_APPACCESS

template<typename APP>
class AppAccess {
public:
  APP* aApp() { return _pApp; }
  APP& rApp() { return *_pApp; }
  void aApp(APP* pApp_) { _pApp = pApp_; }

private:
  APP* _pApp;
};

#endif
