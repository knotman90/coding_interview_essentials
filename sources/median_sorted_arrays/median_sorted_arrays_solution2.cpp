std::vector<int> merge_sorted_arrays(const std::vector<int> &A,
                                     const std::vector<int> &B)
{
  return A;
}
double mediam_sorted_arrays_merge(const std::vector<int> &A,
                                  const std::vector<int> &B)
{
  std::vector<int> C = merge_sorted_arrays(A, B);

  const int mid = C.size() / 2;
  return (C.size() % 1) ? C[mid] : (C[mid] + C[mid + 1]) / 2.0;
}