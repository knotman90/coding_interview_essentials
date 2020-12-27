struct KeyHash
{
  std::size_t operator()(const std::tuple<int, int>& key) const
  {
    return std::get<0>(key) ^ std::get<1>(key);
  }
};

using Cache = std::unordered_map<std::tuple<int, int>, int, KeyHash>;

long min_difficulty_scheduler_DP_topdown_helper(const std::vector<int>& I,
                                                const size_t start,
                                                const int d,
                                                Cache& cache)
{
  if (start >= I.size() && d == 0)
    return 0;

  const size_t remaining = I.size() - start;
  if (remaining < d)
    return std::numeric_limits<int>::max();

  auto t = std::make_tuple(start, d);
  if (auto it = cache.find(t); it != cache.end())
    return it->second;

  int M    = I[start];
  long ans = std::numeric_limits<int>::max();
  for (size_t i = start; i < I.size(); i++)
  {
    M   = std::max(M, I[i]);
    ans = std::min(
        ans,
        M + min_difficulty_scheduler_DP_topdown_helper(I, i + 1, d - 1, cache));
  }
  cache[t] = ans;
  return ans;
}

int min_difficulty_scheduler_DP_topdown(const vector<int>& I, int d)
{
  Cache cache;
  auto ans = min_difficulty_scheduler_DP_topdown_helper(I, 0, d, cache);
  if (ans >= std::numeric_limits<int>::max())
    return -1;
  return ans;
}
