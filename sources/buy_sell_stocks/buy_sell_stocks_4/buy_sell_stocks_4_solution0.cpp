int buy_sell_stock4_DP_unoptimized(const int K, const std::vector<int>& P)
{
  const int n = P.size();
  if (K == 0 || n <= 1)
    return 0;
  std::vector<std::vector<int>> DP(n + 1, std::vector<int>(K + 1, 0));

  for (int k = 1; k <= K; k++)
  {
    for (int i = 1; i < n; i++)
    {
      int best_l = 0;
      for(int l=0 ; l < i; l++)
      {
          best_l = std::max(best_l, DP[l][k-1]+P[i]-P[l]);
      }
      DP[i][k] = std::max(DP[i-1][k], best_l);
    }
  }
  return DP[n - 1][K];
}