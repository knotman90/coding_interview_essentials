
#include "IKThLargestInStream.h"

class KthLargestInStreamMap : IKThLargestInStream
{
 public:
  KthLargestInStreamMap() = default;
  void initialize(const std::vector<int>& initArray, const size_t K) override
  {
    assert(K <= initArray.size());
    m_k = K;
    m_values.insert(begin(initArray), end(initArray));

    auto it = begin(m_values);
    while (m_values.size() > K)
    {
      it = m_values.erase(it);
    }
    assert(m_k == K);
    assert(K == m_values.size());
  }
  int add(const int n) override
  {
    assert(m_k == m_values.size());

    if (n > *(m_values.begin()))
    {
      m_values.insert(n);
      m_values.erase(m_values.begin());
    }
    assert(m_k == m_values.size());
    return *(m_values.begin());
  }

 private:
  std::multiset<int> m_values;
  size_t m_k;
};
