int four_sum_hashing(std::vector<int>& A,
                     std::vector<int>& B,
                     std::vector<int>& C,
                     std::vector<int>& D,
                     const int T)
{
  const size_t size = A.size();
  std::unordered_map<int, int> ab;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      ab[A[i] + B[j]]++;

  std::unordered_map<int, int> cd;
  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++)
      cd[C[i] + D[j]]++;

  int ans = 0;
  for (const auto [k, v] : ab)

    if (auto it = cd.find(-k); it != cd.end())
      ans += v * it->second;

  return ans;
}
