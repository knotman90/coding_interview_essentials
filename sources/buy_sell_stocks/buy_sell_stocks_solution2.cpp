int buy_sell_stocks_DP(std::vector<int> &P)
{

  const int days     = P.size();
  int highest_so_far = std::numeric_limits<int>::min();
  int ans            = 0;
  for (int i = days - 1; i >= 0; i--)
  {
    highest_so_far = std::max(highest_so_far, P[i]);
    ans            = std::max(ans, highest_so_far - P[i]);
  }
  return ans;
}
