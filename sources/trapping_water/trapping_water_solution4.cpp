
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


std::vector<int> max_right(const std::vector<int> &h)
{
  std::vector<int> maxR(h.size(), 0);

  int i    = h.size() - 1;
  int cmax = h[i];
  for (--i; i >= 0; i--)
  {
    maxR[i] = cmax;
    cmax    = std::max(cmax, h[i]);
  }
  return maxR;
}

auto unwind(std::stack<int> &w, const int target)
{
  int ans   = 0;
  int steps = 0;
  while (!w.empty() && w.top() <= target)
  {
    ans += w.top();
    w.pop();
    ++steps;
  }
  return std::make_tuple(ans, steps);
}

int trapping_water_stack(const std::vector<int> &height)
{
  const size_t len = height.size();
  if (len < 2)
    return 0;

  std::stack<int> w;
  std::vector<int> maxR(max_right(height));

  w.push(std::min(height[0], maxR[0]));
  int m   = w.top();
  int ans = 0;
  for (int i = 1; i < len; i++)
  {
    if (height[i] >= m)
    {
      auto [v, l] = unwind(w, m);
      ans += (m * l) - v;
      m = std::min(height[i], maxR[i]);
    }
    w.push(height[i]);
  }
  return ans;
}
