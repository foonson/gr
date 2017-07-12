#ifndef _APPBASE_EVENTLISTENER
#define _APPBASE_EVENTLISTENER

#include "pch.h"
#include "keyEvent.h"

class EventListener {
public:
  virtual void processKeyEvent(const SKeyEvent& event_)=0;
};

#endif
