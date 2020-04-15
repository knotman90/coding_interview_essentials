std::vector<int> max_left_it(auto begin, auto end)
{
  std::vector<int> L(std::distance(begin, end), 0);

  int i    = 0;
  int cmax = *begin;
  while (++begin != end)
  {
    L[++i] = cmax;
    cmax   = std::max(cmax, *begin);
  }
  return L;
}

int trapping_water_DP(const std::vector<int> &height)
{
  const size_t len = height.size();
  if (len < 2)
    return 0;

  int ans = 0;
  std::vector<int> L(max_left_it(height.begin(), height.end()));
  // reversed input to calculate
  std::vector<int> R(max_left_it(height.rbegin(), height.rend()));
  std::reverse(R.begin(), R.end());

  for (size_t i = 0; i < height.size(); i++)
  {
    ans += std::max(0, std::min(R[i], L[i]) - height[i]);
  }

  return ans;
}
