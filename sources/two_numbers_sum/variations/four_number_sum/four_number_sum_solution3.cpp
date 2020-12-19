int four_sum_hashing(const std::vector<int>& A,
                    const  std::vector<int>& B,
                     const std::vector<int>& C,
                     const std::vector<int>& D,
                     const int T)
{
  const size_t size = A.size();
  std::unordered_map<int, int> ab;
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      ab[A[i] + B[j]]++;

  std::unordered_map<int, int> cd;
  for (size_t i = 0; i < size; i++)
    for (size_t j = 0; j < size; j++)
      cd[C[i] + D[j]]++;

  int ans = 0;
  for (const auto [k, v] : ab)

    if (auto it = cd.find(T-k); it != cd.end())
      ans += v * it->second;

  return ans;
}
