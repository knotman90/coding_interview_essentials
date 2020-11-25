
[[nodiscard]] int largerSquareFrom(
    const vector<vector<int>>& matrix,
    const std::pair<size_t, size_t>& top_left_corner,
    const size_t rows,
    const size_t cols)
{
  const auto [x, y] = top_left_corner;

  int k     = 0;
  bool good = true;
  while (good && ((x + k) < rows) && ((y + k) < cols))
  {
    for (size_t i = x; good && i <= x + k; i++)
    {
      for (size_t j = y; good && j <= y + k; j++)
      {
        if (!matrix[i][j])
        {
          return k;
        }
      }
    }
    ++k;
  }
  return k;
}

[[nodiscard]] int maximal_square_brute_force_1(
    const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const auto rows = matrix.size();
  const auto cols = matrix[0].size();
  int ans         = 0;
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      if (matrix[i][j])
        ans = std::max(ans, largerSquareFrom(matrix, {i, j}, rows, cols));

  return ans * ans;
}
