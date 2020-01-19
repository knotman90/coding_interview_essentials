int max_sum_contiguous_subarray_kadane(const std::vector<int> &A) {
  assert(A.size() > 0);

  int ans = A[0];
  int max_ending_here = A[0];
  for (int i = 1; i < A.size(); i++) {
    max_ending_here = std::max(A[i], max_ending_here + A[i]);
    ans = std::max(ans, max_ending_here);
  }
  return ans;
}
