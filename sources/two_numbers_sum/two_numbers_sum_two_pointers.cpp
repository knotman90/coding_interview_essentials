bool two_numers_sum_two_pointers(const std::vector<int> &A, const int T)
{
  int s = 0, e = A.size() - 1;
  while (s < e)
  {
    const int sum = A[s] + A[e];
    if (sum < T)
      s++;
    else if (sum > T)
      e--;
    else
      return true;
  }
  return false;
}