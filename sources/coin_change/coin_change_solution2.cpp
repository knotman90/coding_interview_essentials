int change_ways_bottom_up(const int amount, const vector<int>& coins)
{
  std::vector<int> DP(amount + 1, 0);

  DP[0] = 1;
  for (const auto c : coins)
    for (int i = c; i <= amount; i++)
      DP[i] += DP[i - c];
  return DP[amount];
}