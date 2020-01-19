int max_sum_contiguous_subarray_bruteforce(const std::vector<int> &A) {
  int ans = std::numeric_limits<int>::min();
  for (auto i = begin(A); i != end(A); i++) {
    for (auto j = i; j != end(A); j++) {
      const int subarray_sum = std::accumulate(i, j + 1, 0);
      ans = std::max(ans, subarray_sum);
    }
  }
  return ans;
}