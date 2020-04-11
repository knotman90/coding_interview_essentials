int buy_sell_stocks_multiple_transactions_lin(std::vector<int> &P)
{
  int ans = 0;
  for (int i = 0; i < (int)P.size() - 1; i++)
  {
    if (P[i] < P[i + 1])
      ans += (P[i + 1] - P[i]);
  }
  return ans;
}
