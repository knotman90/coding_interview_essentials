#ifndef SOURCES_KTH_LARGEST_IN_STREAM_IKTHLARGESTINSTREAM
#define SOURCES_KTH_LARGEST_IN_STREAM_IKTHLARGESTINSTREAM

#include <vector>

class IKThLargestInStream
{
 public:
  IKThLargestInStream()                   = default;
  virtual void initialize(const std::vector<int>& initArray,
                          const size_t K) = 0;
  virtual int add(const int n)            = 0;
};

#endif /* SOURCES_KTH_LARGEST_IN_STREAM_IKTHLARGESTINSTREAM */
