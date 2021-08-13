using DPCache = std::unordered_map<int, int>;

int change_ways_DP_topdown_helper(const std::vector<int>& I,
                                  const int t,
                                  DPCache& cache)
{
  if (t == 0)
    return 0;
  if (t < 0)
    return std::numeric_limits<int>::max();

  if (cache.contains(t))
    return (cache.find(t))->second;

  int ans = std::numeric_limits<int>::max();
  for (const auto d : I)
  {
    ans = std::min(ans, change_ways_DP_topdown_helper(I, t - d, cache));
  }
  ans += 1;
  cache.insert({t, ans});
  return ans;
}

int change_ways_DP_topdown(const std::vector<int>& I, const int t)
{
  DPCache cache;
  return change_ways_DP_topdown_helper(I, t, cache);
}