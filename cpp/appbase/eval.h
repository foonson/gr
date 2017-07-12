#ifndef _APPBASE_EVAL
#define _APPBASE_EVAL

#include "appbase/tickable.h"

class Eval : public Tickable {
public:  
  Eval() {
    _enabled = true;
  }

  void eval() {
    if (!enabled()) {
      return;
    }
    if (needEval()) {
      evalImpl();
    }
  }

  bool enabled() { return _enabled; }
  void enabled(bool enabled_) { _enabled = enabled_; }

  virtual void evalImpl() = 0;
  bool needEval() { 
    return tick().pass();
  };

private:
  bool _enabled;



};

#endif
