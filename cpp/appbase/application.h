#ifndef _APPBASE_APPLICATION
#define _APPBASE_APPLICATION

//#include "util/pch.h"

#include <thread>
//#include "screen.h"
//#include "keyboard.h"
//#include "key.h"
//#include "ikeyListener.h"
#include "util/idispose.h"
//#include "evalGroup.h"
//#include "util/syncQueue"
#include "util/tick.h"

//template class T
class Application : private IDispose {
//class Application : private IKeyListener, private IDispose {

public:

  Application();
  virtual ~Application();

  static void signalHandler(int signum);
  static Application* _pApp;

  void registerSignalHandler();
  virtual void initialize();
  virtual void dispose();

  virtual void evaluateLoop();
  virtual void renderLoop();
  virtual void inputLoop();
  void startThreads();

  //vector<SPEvalGroup>& evalGroups() { return _vpEvalGroups; }
  //Screen& screen() { return _screen; }
  //Keyboard& keyboard() { return _keyboard; }

  //void addEvalGroup(SPEvalGroup pEvalGroup_) {
  //  _vpEvalGroups.push_back(pEvalGroup_);
  //}

  //void sound(const string& pathName_);
  void triggerExit() {
    _exit = true;
  }

protected:
  bool _exit;
  //Tick _evalTick;
  //Tick _renderTick;

private:
  //Screen _screen;
  //Keyboard _keyboard;

  //vector<SPEvalGroup> _vpEvalGroups;
  //SyncQueue<Key> _queueKey;
};

#endif
