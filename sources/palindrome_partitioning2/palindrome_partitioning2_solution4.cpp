

int palindrome_partitioning2_DP_bottomup(const std::string s)
{
  std::vector<int> DP(s.size() + 1, s.size() - 1);
  DP[s.size() - 1] = DP[s.size()] = 0;
  for (int i = std::ssize(s) - 2; i >= 0; i--)
  {
    if (is_palindrome(s, i, s.size() - 1))
    {
      DP[i] = 0;
      continue;
    }
    for (int j = i; j < std::ssize(s); j++)
    {
      if (is_palindrome(s, i, j))
      {
        const auto cost_partition_rest = j < std::ssize(s) - 1 ? DP[j + 1] : 0;
        DP[i] = std::min(DP[i], 1 + cost_partition_rest);
      }
    }
  }
  return DP[0];
}