
int maximal_square_in_matrix_bottom_up(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const int rows = matrix.size();
  const int cols = matrix[0].size();

  vector<vector<int>> R(rows, vector<int>(cols)),
      D(rows, vector<int>(cols)), S(rows, vector<int>(cols));
  
  int ans = 0;

  for (int i = 0; i < rows; i++)
    for (int j = cols - 1; j >= 0; j--)
      if (matrix[i][j] != 0)
        R[i][j] = 1 + (j + 1 < cols ? R[i][j + 1] : 0);

  for (int i = 0; i < cols; i++)
    for (int j = rows - 1; j >= 0; j--)
      if (matrix[j][i] != 0)
        D[j][i] = 1 + (j + 1 < rows ? D[j + 1][i] : 0);

  for (int j = cols - 1; j >= 0; ans = std::max(ans, S[rows - 1][j]), j--)
    S[rows - 1][j] = (matrix[rows - 1][j] != 0);

  for (int i = rows - 1; i >= 0; ans = std::max(ans, S[i][cols - 1]), i--)
    S[i][cols - 1] = (matrix[i][cols - 1] != 0);

  for (int i = rows - 2; i >= 0; i--)
  {
    for (int j = cols - 2; j >= 0; j--)
    {
      if (D[i][j] == 0)
        continue;

      const int inner = S[i + 1][j + 1];
      if (inner == 0)
        S[i][j] = 1;
      else
      {
        S[i][j] == D[i][j] > 0;
        if (D[i][j] >= inner + 1 && R[i][j] >= inner + 1)
          S[i][j] = inner + 1;
        else
          S[i][j] = std::max(1, std::min({D[i][j], R[i][j], inner}));
      }
      ans = std::max(ans, S[i][j]);
    }
  }

  return ans * ans;
}
