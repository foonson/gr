#ifndef _UTIL_IDISPOSE
#define _UTIL_IDISPOSE

class IDispose {
public:
  virtual void dispose()=0;

protected:
  bool _disposed;
};

#endif
