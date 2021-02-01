
using Cache = vector<vector<int>>;
int change_helper(int amount,
                  const vector<int>& coins,
                  const int current_coin,
                  Cache& cache)
{
  if (amount < 0 || current_coin < 0)
    return 0;

  if (amount == 0)
    return 1;

  if (cache[current_coin][amount] > 0)
    return cache[current_coin][amount] - 1;

  const int ans =
      change_helper(amount, coins, current_coin - 1, cache)
      + change_helper(amount - coins[current_coin], coins, current_coin, cache);
  cache[current_coin][amount] = ans + 1;

  return ans;
}
int count_change_ways_top_down(int amount, const vector<int>& coins)
{
  if (amount == 0)
    return 1;
  Cache cache(coins.size(), std::vector<int>(amount + 1, 0));
  return change_helper(amount, coins, coins.size() - 1, cache);
}
