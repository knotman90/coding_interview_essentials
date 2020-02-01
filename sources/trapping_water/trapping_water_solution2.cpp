
std::vector<int> max_left(const std::vector<int> &h)
{
  std::vector<int> maxR(h.size(), 0);

  int i    = 0;
  int cmax = h[i];
  for (++i; i < h.size(); i++)
  {
    maxR[i] = cmax;
    cmax    = std::max(cmax, h[i]);
  }
  return maxR;
}


std::vector<int> max_left_it(auto begin, auto end)
{
  std::vector<int> maxR(std::distance(begin, end), 0);

  int i    = 0;
  int cmax = *begin;
  while(++begin != end)
  {
    maxR[++i] = cmax;
    cmax    = std::max(cmax, *begin);
  }
  return maxR;
}



int trapping_water_left_right(const std::vector<int> &height)
{
  const size_t len = height.size();
  if (len < 2)
    return 0;

  int ans = 0;
  std::vector<int> maxR(max_left_it(height.begin(), height.end()));
  std::vector<int> maxL(max_left_it(height.rbegin(), height.rend()));
  std::reverse(maxL.begin(), maxL.end());
  
  for (int i = 0; i < height.size(); i++)
  {
    ans += std::max(0,  std::min(maxR[i], maxL[i]) - height[i]);
  }

  return ans;
}
