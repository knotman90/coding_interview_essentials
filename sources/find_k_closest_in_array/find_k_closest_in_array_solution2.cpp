std::vector<int> kth_closest_in_array_partial_sorting(vector<int>& I,
                                                      const int k,
                                                      const int x)
{
  assert(I.size() >= k);
  std::partial_sort(
      begin(I), begin(I) + k, end(I), [x](const auto y, const auto z) {
        return std::abs(x - y) < std::abs(x - z);
      });

  return std::vector<int>(begin(I), begin(I) + k);
}