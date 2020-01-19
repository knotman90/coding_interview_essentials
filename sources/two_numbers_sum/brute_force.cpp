bool two_numers_sum_brute_force(const vector<int> &A, const int T) {
  const size_t size = A.size();
  for (int i = 0; i < size - 1; i++)
    for (int j = i + 1; j < size; j++)
      if (A[i] + A[j] == T)
        return true;
  return false;
}