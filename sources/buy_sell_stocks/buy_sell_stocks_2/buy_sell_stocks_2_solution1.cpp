int buy_sell_stocks_multiple_transactions(std::vector<int> &P)
{
  if (P.size() <= 0)
    return 0;
  int ans = 0;
  for (int i = 0; i < P.size() - 1; i++)
  {
    if (P[i] < P[i + 1])
      ans += (P[i + 1] - P[i]);
  }
  return ans;
}