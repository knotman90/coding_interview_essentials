int buy_sell_stock4_DP_time_optimized(const int K, const std::vector<int>& P)
{
  const int n = P.size();
  if (K == 0 || n <= 1)
    return 0;
  std::vector<std::vector<int>> DP(n + 1, std::vector<int>(K + 1, 0));

  for (int k = 1; k <= K; k++)
  {
    int max_left = DP[0][k - 1] - P[0];
    for (int i = 1; i < n; i++)
    {
      DP[i][k] = std::max(DP[i - 1][k], max_left + P[i]);
      max_left = std::max(max_left, DP[i][k - 1] - P[i]);
    }
  }
  return DP[n - 1][K];
}