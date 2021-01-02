bool two_numers_sum_sorting(std::vector<int> &A, const int T)
{
  std::ranges::sort(A);
  const size_t size = A.size();
  for (int i = 0; i < size - 1; i++)
    if (std::binary_search(begin(A) + i + 1, end(A), T-A[i]))
      return true;
  return false;
}