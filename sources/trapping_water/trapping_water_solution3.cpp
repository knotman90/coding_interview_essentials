/*std::vector<int> scan_inclusive(const std::vector<int> &h)
{

  std::vector<int> s(h.size());
  s.back() = h.back();
  for (int i = h.size() - 2; i >= 0; i--)
  {
    s[i] += s[i + 1];
  }
  return s;
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

int trapping_water_scan(const std::vector<int> &height)
{
  const size_t len = height.size();
  if (len < 2)
    return 0;


  std::vector<int> maxR(max_right(height));
  std::vector<int> s(scan_inclusive(height));

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
  }
  return ans;
}
*/