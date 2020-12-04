int odd_appearing_element_final_std(const std::vector<int> &A)
{
  return std::accumulate(
      begin(A), end(A), 0, [](const int acc, const int x) { return acc ^ x; });
}