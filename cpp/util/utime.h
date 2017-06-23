#ifndef _UTIL_UTIME
#define _UTIL_UTIME

#include "pch.h"

#include <chrono>

typedef std::chrono::time_point<std::chrono::system_clock> stdTime;

namespace UTime {
  bool pass(std::chrono::time_point<std::chrono::system_clock>& last_, int millisecond_);
  std::chrono::time_point<std::chrono::system_clock> now();
  std::string toString(const stdTime& time_, const std::string& format_);
  std::string toString(const stdTime& time_);
  std::string snow();
}

#endif
