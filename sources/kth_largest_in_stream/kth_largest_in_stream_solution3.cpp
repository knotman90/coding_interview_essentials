#include "IKThLargestInStream.h"

class KthLargestInStreamHeap : IKThLargestInStream
{
 public:
  KthLargestInStreamHeap() = default;
  void initialize(const std::vector<int>& initArray, const size_t K) override
  {
    assert(K <= initArray.size());
    m_k = K;

    auto s = begin(initArray);
    auto e = begin(initArray) + K;
    m_values_heap.insert(begin(m_values_heap), s, e);
    std::make_heap(begin(m_values_heap), end(m_values_heap), std::greater<>());

    assert(K == m_values_heap.size());

    while (e != end(initArray))
    {
      add(*e);
      ++e;
    }
    assert(K == m_values_heap.size());
  }

  int add(const int n) override
  {
    assert(m_k == m_values_heap.size());
    if (n <= m_values_heap.front())
      return m_values_heap.front();
    std::pop_heap(begin(m_values_heap), end(m_values_heap), std::greater<>());
    m_values_heap.back() = n;
    std::push_heap(begin(m_values_heap), end(m_values_heap), std::greater<>());

    assert(m_k == m_values_heap.size());
    return m_values_heap.front();
  }

 private:
  std::vector<int> m_values_heap;
  size_t m_k;
};
