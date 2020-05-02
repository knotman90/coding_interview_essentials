
int maximal_square_brute_force_1(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const int rows = matrix.size();
  const int cols = matrix[0].size();

  int ans = 0;
  return ans * ans;
}
