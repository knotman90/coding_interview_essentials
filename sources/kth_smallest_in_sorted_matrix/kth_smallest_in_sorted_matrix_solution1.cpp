using Matrix = std::vector<std::vector<int>>;
int kth_smallest_in_sorted_matrix_naive(const Matrix& M, const size_t k)
{
  assert(k > 0);
  assert(M.size() && (k <= (M.size() * M[0].size())));

  std::vector<int> M_linear;
  for (const auto& row : M)
  {
    M_linear.insert(M_linear.end(), row.begin(), row.end());
  }
  std::partial_sort(M_linear.begin(), M_linear.begin() + k, M_linear.end());
  return M_linear[k - 1];
}