#include "Interval.h"

bool operator==(const Interval& i1, const Interval& i2)
{
  return i1.start == i2.start && i1.end == i2.end;
}
