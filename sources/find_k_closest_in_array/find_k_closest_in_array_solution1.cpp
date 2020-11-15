std::vector<int> kth_closest_in_array_sorting(vector<int>& I,
                                              const int k,
                                              const int x)
{
  assert(I.size() >= k);
  std::sort(begin(I), end(I), [x](const auto y, const auto z) {
    return std::abs(x - y) < std::abs(x - z);
  });

  std::vector<int> ans{begin(I), begin(I) + k};
  std::sort(begin(ans), end(ans));
  return ans;
}