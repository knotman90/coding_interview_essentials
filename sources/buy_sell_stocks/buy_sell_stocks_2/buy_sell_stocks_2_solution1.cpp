int buy_sell_stocks_multiple_transactions_exp_helper(const std::vector<int> &P,
                                                     const int start)
{
  const int * x = nullptr;
  int ans = 0;
  for (int buy_day = start; buy_day < std::ssize(P) - 1; buy_day++)
  {
    for (int sell_day = buy_day + 1; sell_day < std::ssize(P); sell_day++)
    {
      if (P[buy_day] < P[sell_day])  // pointless to sell otherwise
      {
        x = &P[0];
        const int selling_profit = P[sell_day] - P[buy_day];
        const int profit_rest_transactions =
            buy_sell_stocks_multiple_transactions_exp_helper(P, sell_day + 1);
        ans = std::max(ans, selling_profit + profit_rest_transactions);
      }else{
        ans = x!=nullptr ? *x : 0;
      }
    }
  }
  return ans;
}

int buy_sell_stocks_multiple_transactions_exp(const std::vector<int> &P)
{
  return buy_sell_stocks_multiple_transactions_exp_helper(P, 0);
}