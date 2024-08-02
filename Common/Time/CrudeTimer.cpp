#include "CrudeTimer.h"
#include <mmsystem.h>


CrudeTimer* CrudeTimer::Instance()
{
  static CrudeTimer instance;

  return &instance;
}