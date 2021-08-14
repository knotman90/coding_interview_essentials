
int smallest_range_II(std::vector<int>& A, const int K)
{
  std::sort(std::begin(A), std::end(A));
  int ans = A.back() - A.front();
  for (size_t i = 1; i < A.size(); i++)
  {
    const auto m_new = std::min(A.front() + K, A[i] - K);
    const auto M_new = std::max(A[i - 1] + K, A.back() - K);
    ans              = std::min(ans, M_new - m_new);
  }
  return ans;
}
