
auto best_transaction_right(const std::vector<int>& prices)
{
  const auto size = prices.size();
  std::vector<int> ans(size, 0);
  int max_right = prices[size - 1];
  ans[size - 1] = (max_right - prices[size - 1]);
  for (int i = size - 2; i >= 0; i--)
  {
    max_right = std::max(max_right, prices[i]);
    ans[i]    = std::max(ans[i + 1], max_right - prices[i]);
  }
  return ans;
}

int buy_sell_stocks3_DP(vector<int>& prices)
{
  const auto best_right = best_transaction_right(prices);
  const auto size       = prices.size();

  int ans      = 0;
  int min_left = prices[0];
  for (int i = 0; i < size; i++)
  {
    min_left = std::min(min_left, prices[i]);
    ans      = std::max(ans, prices[i] - min_left + best_right[i]);
  }
  return ans;
}