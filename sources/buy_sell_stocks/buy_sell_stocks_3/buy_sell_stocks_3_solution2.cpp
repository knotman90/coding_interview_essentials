int buy_sell_stock3_linear_space(const std::vector<int>& P)
{
  if (P.empty())
    return 0;

  int buy1    = std::numeric_limits<int>::max();
  int profit1 = std::numeric_limits<int>::min();
  int buy2    = std::numeric_limits<int>::max();
  int profit2 = std::numeric_limits<int>::min();
  for (int i = 0; i < P.size(); i++)
  {
    buy1    = std::min(buy1, P[i]);
    profit1 = std::max(profit1, P[i] - buy1);
    buy2    = std::min(buy2, P[i] - profit1);
    profit2 = std::max(profit2, P[i] - buy2);
  }
  return profit2;
}