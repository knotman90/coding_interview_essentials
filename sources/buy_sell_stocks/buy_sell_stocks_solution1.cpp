int buy_sell_stocks_bruteforce(std::vector<int> &P)
{
  const int n = P.size();
  int ans     = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      ans = std::max(ans, P[j] - P[i]);
  return ans;
}