class KthLargestInStreamArray : IKThLargestInStream
{
 public:
  KthLargestInStreamArray() = default;
  void initialize(const std::vector<int>& initArray, const size_t K) override
  {
    m_values = initArray;
    m_k      = K;
    std::sort(begin(m_values), end(m_values));
    const auto start = begin(m_values);
    const auto end   = m_values.size() >= K
                           ? m_values.begin() + (m_values.size() - K)
                           : m_values.begin();
    m_values.erase(start, end);
  };

  int add(const int n) override
  {
    assert(m_values.size() == m_k);
    if (n < m_values.front())
      return m_values.front();
    m_values.front() = n;
    auto it          = begin(m_values);
    auto itn         = std::next(it);
    while (itn != end(m_values) && *it > *itn)
    {
      std::iter_swap(it, itn);
      it  = itn;
      itn = std::next(it);
    }
    return m_values.front();
  };

 private:
  std::vector<int> m_values;
  size_t m_k = 0;
};