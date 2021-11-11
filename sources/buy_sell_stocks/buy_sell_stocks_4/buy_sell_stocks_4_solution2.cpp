int maxProfit(int K, vector<int>& P)
{
  const int n = P.size();
  if (K == 0 || n <= 1)
    return 0;
  std::vector<std::vector<int>> DP(n + 1, std::vector<int>(K + 1, 0));

  for (int k = 1; k <= K; k++)
  {
    int max_kminus1_to_left_of_i = DP[0][k - 1] - P[0];
    for (int i = 1; i < n; i++)
    {
      DP[i][k] = std::max(DP[i - 1][k], max_kminus1_to_left_of_i + P[i]);
      max_kminus1_to_left_of_i =
          std::max(max_kminus1_to_left_of_i, DP[i][k - 1] - P[i]);
    }
  }
  return DP[n - 1][K];
