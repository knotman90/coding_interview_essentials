constexpr inline bool is_bit_set(const int n, const unsigned p) {
  return (n >> p) & 1;
}

std::vector<std::vector<int>>
power_set_bit_manipulation(const std::vector<int> &A) {
  const size_t limit = (1ll << A.size()) - 1;
  std::vector<std::vector<int>> PS;
  PS.reserve(limit + 1);

  for (int i = 0; i < limit; i++) {
    std::vector<int> subset = {};
    for (int p = 0; p < 32; p++)
      if (is_bit_set(i, p)) {
        subset.push_back(A[p]);
      }
    PS.push_back(subset);
  }

  PS.push_back(A);
  return PS;
}
