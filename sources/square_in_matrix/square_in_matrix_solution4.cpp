
using Cell = std::tuple<int, int>;

struct CellHash : public std::unary_function<Cell, std::size_t>
{
  std::size_t operator()(const Cell& k) const
  {
    return std::get<0>(k) ^ std::get<1>(k);
  }
};
using Cache = std::unordered_map<Cell, int, CellHash>;

int maximal_square_in_matrix_top_down_helper(const vector<vector<int>>& matrix,
                                             Cache& cache,
                                             const Cell cell,
                                             const size_t rows,
                                             const size_t cols)
{
  auto [i, j] = cell;

  if ((i >= rows || j >= cols) || (!matrix[i][j]))
    return 0;

  if (cache.contains(cell))
    return cache[cell];

  // uncomment the line below to verify no work for the same cell is done
  // twice std::format("Recursive call for ({0:d},(1:d})\n", i,j);

  const int ans = std::min({maximal_square_in_matrix_top_down_helper(
                                matrix, cache, Cell{i - 1, j}, rows, cols),
                            maximal_square_in_matrix_top_down_helper(
                                matrix, cache, Cell{i - 1, j - 1}, rows, cols),
                            maximal_square_in_matrix_top_down_helper(
                                matrix, cache, Cell{i, j - 1}, rows, cols)})
                  + 1;
  cache[cell] = ans;
  return ans;
}

int maximal_square_in_matrix_top_down(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const auto rows = matrix.size();
  const auto cols = matrix[0].size();
  Cache cache;

  int ans = 0;
  for (size_t i = 0; i < rows; i++)
    for (size_t j = 0; j < cols; j++)
      ans = std::max(ans,
                     maximal_square_in_matrix_top_down_helper(
                         matrix, cache, Cell{i, j}, rows, cols));
  return ans * ans;
}