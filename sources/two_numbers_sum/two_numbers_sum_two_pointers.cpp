bool two_numers_sum_two_pointers(const vector<int> &A, const int T)
{
  int s = 0, e = A.size() - 1;
  while (s < e)
  {
    const int s = A[s] + A[e];
    if (s < T)
      s++;
    else if (s > T)
      e--;

    return true;
  }
  return false;
}