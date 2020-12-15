Matrix max_manhattan_matrix_k_DP_bottomup(const Matrix& I, const unsigned K)
{
  const auto rows = I.size();
  assert(rows > 0);
  const auto cols = I.back().size();
  assert(cols > 0);

  std::array<Matrix, 2> cache = {I, I};
  Matrix& previous            = cache[0];
  Matrix& current             = cache[1];

  for (int k = 1; k <= K; k++)
  {
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        auto ans = previous[i][j];
        if (i - 1 >= 0)
          ans = std::max(ans, previous[i - 1][j]);
        if (i + 1 < rows)
          ans = std::max(ans, previous[i + 1][j]);
        if (j - 1 >= 0)
          ans = std::max(ans, previous[i][j - 1]);
        if (j + 1 < cols)
          ans = std::max(ans, previous[i][j + 1]);

        current[i][j] = ans;
      }
    }
    std::swap(current, previous);
  }
  return previous;
}