int maximal_square_in_matrix_bottom_up(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const auto rows = matrix.size();
  const auto cols = matrix[0].size();
  // first row and first column have the same values as in the original
  // input matrix
  std::vector<vector<int>> cache(matrix);

  // is there a 1 in the first row?
  int ans = std::find(begin(matrix[0]), end(matrix[0]), 1) != end(matrix[0]) ? 1 : 0;

  // is there a 1 in the first column?
  for (size_t i = 1; i < rows; i++)
  {
    if (matrix[i][0])
    {
      ans = 1;
      break;
    }
  }

  for (size_t i = 1; i < rows; i++)
  {
    for (size_t j = 1; j < cols; j++)
    {
      if (matrix[i][j])
      {
        cache[i][j] = std::min({cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1]}) + 1;
      }
      ans = std::max(ans, cache[i][j]);
    }
  }
  return ans * ans;
}