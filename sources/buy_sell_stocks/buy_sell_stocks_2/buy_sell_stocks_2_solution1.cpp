int buy_sell_stocks_multiple_transactions_exp_helper(const std::vector<int> &P, const int start)
{
  int ans = 0;
  for (int buy_day = start; buy_day < P.size() - 1; buy_day++)
  {
    for (int sell_day = buy_day + 1; sell_day < P.size(); sell_day++)
    {
      if (P[buy_day] < P[sell_day])  // pointless to sell otherwise
      {
        const int selling_profit = P[sell_day] - P[buy_day];
        const int profit_rest_transactions =
            buy_sell_stocks_multiple_transactions_exp_helper(P, sell_day + 1);
        ans = std::max(ans, selling_profit + profit_rest_transactions);
      }
    }
  }
  return ans;
}

int buy_sell_stocks_multiple_transactions_exp(const std::vector<int> &P)
{
  return buy_sell_stocks_multiple_transactions_exp_helper(P, 0);
}