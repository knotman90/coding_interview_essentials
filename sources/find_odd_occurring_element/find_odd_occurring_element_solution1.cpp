inline constexpr bool is_odd(const int x)
{
  return x & 1;  // only odd number have the leftmost bit set
}

int odd_appearing_element_bruteforce_rawloop(const std::vector<int>& A)
{
  for (const auto& x : A)
  {
    // count how many times x appears in A
    const size_t number_occurrences = std::count(begin(A), end(A), x);
    if (is_odd(number_occurrences))
      return x;
  }
  throw std::invalid_argument(
      "Invalid input array. No elements appear an odd number of times");
}