#ifndef _APPBASE_RENDER
#define _APPBASE_RENDER

#include "appbase/tickable.h"

class Render : public Tickable {

public:

  //Render() {}

  virtual bool renderImpl() = 0;

  bool render() {
    if (needRender()) {
      return renderImpl();
    }
    return false;
  }

  bool needRender() {
    return tick().pass();
  }

};

#endif
