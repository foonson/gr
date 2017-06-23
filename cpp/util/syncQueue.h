#ifndef _UTIL_SYNCQUEUE
#define _UTIL_SYNCQUEUE

#include "pch.h"
#include <deque>
#include <thread>
#include <mutex>

template<typename T> 
class SyncQueue {

public:
  void put(const T& cmd_);
  optional<T> get();
  bool empty();
  size_t size();
private:
  std::deque<T> _queue;
  std::mutex _mutex;
};

template<typename T>
bool SyncQueue<T>::empty() { return _queue.empty(); }

template<typename T>
size_t SyncQueue<T>::size() { return _queue.size(); }

template<typename T>
void SyncQueue<T>::put(const T& cmd_) {
  std::lock_guard<std::mutex> lock(_mutex);
  _queue.push_back(cmd_);
}

template<typename T>
optional<T> SyncQueue<T>::get() {
  std::lock_guard<std::mutex> lock(_mutex);
  if (_queue.empty()) {
    //return T();
    return nullopt;
  }
  T node = _queue.front();
  _queue.pop_front();
  return optional<T>(node);
}

#endif
