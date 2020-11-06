int find_majority_element_brute_force(const std::vector<int>& N)
{
  const size_t threshold = N.size() / 2;
  for (const auto x : N)
  {
    const size_t countx = std::count(begin(N), end(N), x);
    if (countx > threshold)
      return x;
  }
  return -1;
}