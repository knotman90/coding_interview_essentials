int odd_appearing_element_linear_space(const std::vector<int>& A)
{
  // true = even
  // false = odd
  std::unordered_map<int, bool> M;
  for (const auto& x : A)
    M[x] = !M[x];

  for (const auto& kv : M)
    if (kv.second)  // kv is a pair<key, value>
      return kv.first;

  throw std::invalid_argument(
      "Invalid input array. No elements appear an odd number of times");
}