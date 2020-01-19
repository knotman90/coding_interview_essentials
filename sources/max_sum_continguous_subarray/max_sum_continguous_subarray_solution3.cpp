std::vector<int> prefix_sum(const std::vector<int> &A) {
  assert(A.size() > 0);

  std::vector<int> Y(A.size());
  Y[0] = A[0];
  for (size_t i = 1; i < A.size(); i++)
    Y[i] = Y[i - 1] + A[i];

  return Y;
}

int max_sum_contiguous_subarray_bruteforce_prefix_sum(
    const std::vector<int> &A) {
  const std::vector<int> Y = prefix_sum(A);

  int ans = std::numeric_limits<int>::min();
  for (size_t i = 0; i < A.size(); i++) {
    for (size_t j = i; j < A.size(); j++) {
      int subarray_sum = Y[j]; // 0 to j
      if (i > 0)
        subarray_sum -= Y[i - 1]; // 0 to i

      ans = std::max(ans, subarray_sum);
    }
  }
  return ans;
}