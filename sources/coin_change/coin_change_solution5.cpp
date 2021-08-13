int change_min_ways_bottom_up(const int amount, const vector<int>& coins)
{
  constexpr int INF = std::numeric_limits<int>::max();
  std::vector<int> T(amount + 1, INF);
  T[0] = 0;
  
  for (const auto c : coins)
    for (int x = 0; x <= amount; x++)
      if ((x + c) <= amount)
        T[x + c] = std::min(T[x + c], T[x] + 1);
  return T[amount];
}