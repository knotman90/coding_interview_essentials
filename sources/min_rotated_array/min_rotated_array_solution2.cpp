template <typename T>
auto min_rotated_array_brute_force_1(const std::vector<T>& V)
{
  auto ans = std::numeric_limits<T>::max();
  for (const auto v : V)
    ans = std::min(ans, v);
  return ans;
}