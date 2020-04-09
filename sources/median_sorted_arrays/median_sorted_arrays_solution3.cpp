double mediam_sorted_arrays_log(const std::vector<int> &A,
                                const std::vector<int> &B)
{
  int l = 0, r = A.size() - 1;
  const int size      = A.size() + B.size();
  const int half_size = size / 2;

  while (l <= r)
  {
    const int i = l + (r - l) / 2 + 1;
    const int j = half_size - mid;

    const int idx_i = i - 1;
    const int idx_j = j - 1;
    if (A[i - 1] <= B[j] && B[j - 1] <= A[i])
      if (size % 2 == 0)
        return (std::max(A[i - 1], B[j - 1]) + std::min(A[i], B[j])) / 2.0;
      else
        return std::max(A[i - 1], B[j - 1]);

    if (A[i - 1] > B[j])
      r = i - 1;
    else
      l = i - 1;
  }
}