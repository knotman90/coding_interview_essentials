bool two_numers_sum_hashset(const vector<int> &A, const int T)
{
  std::unordered_set<int> H;
  const size_t size = A.size();
  for (int i = 0; i < size ; i++)
  {
    if (H.contains(T-A[i]))
      return true;
    H.insert(A[i]);
  }
  return false;
}