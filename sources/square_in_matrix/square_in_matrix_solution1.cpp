
[[nodiscard]] int largerSquareFrom(const vector<vector<int>>& matrix, const std::pair<int,int>& top_left_corner, const size_t rows, const size_t cols ){
  const auto [x,y] = top_left_corner;
  
  int k = 0;
  bool good = true;
  while(good && ((x+k) < rows) && ((y+k) < cols))
  {
    for(size_t i = x ;  good && i < x+k ; i++)
    {
      for (size_t j = y; good && j < y+k ; j++)
      {
        if(!matrix[i][j]){
          good = false;
          break;
        }
      }
    }
    ++k;
  }
  return k+1;
  
}


[[nodiscard]] int maximal_square_brute_force_1(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
    return 0;

  const int rows = matrix.size();
  const int cols = matrix[0].size();

  for(int i = 0 ; i < rows ; i++)
    for(int j = 0 ; j < cols ; j++)
      ans = std::max(ans, largerSquareFrom(matrix,{x,y}, rows, cols));
    
  return ans * ans;
}
