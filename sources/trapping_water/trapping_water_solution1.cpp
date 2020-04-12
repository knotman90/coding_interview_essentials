int trapping_water_brute_force(const std::vector<int> &height)
{
  const int size = height.size();
  int ans        = 0;
  for (int i = 1; i < size - 1; i++)
  {
    const int b_l = *std::max_element(std::begin(height), std::begin(height) + i);
    const int b_r = *std::max_element(std::begin(height) + i + 1, std::end(height));

    const int min_max_on_side = std::min(b_l, b_r);
    // equivalent to
    // if(min_max_on_side - height[i] > 0) ans+=min_max_on_side - height[i]
    ans += std::max(0, min_max_on_side - height[i]);
  }
  return ans;
}
