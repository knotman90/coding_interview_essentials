//! This function returns the max value among the cells of I that are part of
//! the
// manhattan neighborhood of size K for cell at (i,j)
/*!
  \param I the input matrix
  \param cell the coordinate of the cell for which the max value is to be
  calculated \param K the size of the manhattan neighborhood \return the max
  value for (i,j) among all cells (p,q) satisfying: |i-p|+|j-q| <= K
*/
using Matrix = std::vector<std::vector<int>>;
using Cell   = std::pair<int, int>;

auto find_max_in_manhattan_neigh_k(const Matrix& I,
                                   const Cell& cell,
                                   const int K)
{
  const int rows    = I.size();
  const int cols    = I.back().size();
  const auto [i, j] = cell;
  assert(i >= 0 && i < rows && j >= 0 && j < cols);

  int ans = I[i][j];
  for (int p = std::max(0, i - K); p <= std::min(rows - 1, i + K); p++)
  {
    for (int q = std::max(0, j - K); q <= std::min(cols - 1, j + K); q++)
    {
      if (std::abs(i - p) + std::abs(j - q) <= K)
      {
        ans = std::max(ans, I[p][q]);
      }
    }
  }
  return ans;
}

Matrix max_manhattan_matrix_k_bruteforce(const Matrix& I, const unsigned K)
{
  const int rows = I.size();
  const int cols = I.back().size();

  Matrix M(I);
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      M[i][j] = find_max_in_manhattan_neigh_k(I, Cell(i, j), K);
    }
  }
  return M;
}