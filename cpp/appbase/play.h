#ifndef _APPBASE_PLAY
#define _APPBASE_PLAY
#include "pch.h"
#include "util/ucollection.h"

template<typename TACTION>
class Play {

public:
  void mapKeyAction(unsigned long key_, TACTION action_) { 
    UCollection::set(_mapKeyAction, key_, action_);
    //printf("mapKeyAction %d %d\n", key_, _mapKeyAction.size());
  }
  
  TACTION action(unsigned long key_) {
    //printf("action %d %d\n", key_, _mapKeyAction.size());
    return UCollection::getValue(_mapKeyAction, key_, TACTION::NONE);
  }

protected:
  std::map<unsigned long, TACTION> _mapKeyAction;

};

#endif

