bool two_numers_sum_hashset(const vector<int> &A, const int T) {
  unordered_set<int> H;
  const size_t size = A.size();
  for (int i = 0; i < size - 1; i++) {
    if (H.find(A[i]) != end(H))
      return true;
    H.insert(A[i]);
  }
  return false;
}