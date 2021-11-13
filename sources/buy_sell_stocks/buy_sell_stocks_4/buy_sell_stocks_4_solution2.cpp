int maxProfit(const int K, std::vector<int>& P)
{
  const int n = P.size();
  if (K == 0 || n <= 1)
    return 0;

  std::vector<std::vector<int>> DP(n + 1, std::vector<int>(2, 0));

  int curr_k = 1;
  int prec_k = 0;
  for (int k = 1; k <= K; k++)
  {
    int max_kminus1_to_left_of_i = DP[0][prec_k] - P[0];
    for (int i = 1; i < n; i++)
    {
      DP[i][curr_k] =
          std::max(DP[i - 1][curr_k], max_kminus1_to_left_of_i + P[i]);
      max_kminus1_to_left_of_i =
          std::max(max_kminus1_to_left_of_i, DP[i][prec_k] - P[i]);
    }
    swap(curr_k,prec_k);
  }
  return DP[n - 1][prec_k];
}
