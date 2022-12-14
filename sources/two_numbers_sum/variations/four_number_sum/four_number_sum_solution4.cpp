int four_sum_hashing_space_optimized(const std::vector<int>& A,
                                     const std::vector<int>& B,
                                     const std::vector<int>& C,
                                     const std::vector<int>& D,
                                     const int T)
{
  const size_t size = A.size();
  std::unordered_map<int, int> ab;
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      ab[A[i] + B[j]]++;

  int ans = 0;
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      if (auto it = ab.find(T - (C[i] + D[j])); it != ab.end())
        ans += it->second;

  return ans;
}
