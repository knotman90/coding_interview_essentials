[[nodiscard]] auto largerSquareFromDiagonal(const vector<vector<int>>& matrix, const std::pair<size_t,size_t>& top_left_corner, const size_t rows, const size_t cols ){
  const auto [x,y] = top_left_corner;
  int steps = 0;
  while( ((x+steps)< rows) && ((y+steps)< cols) )
  {
      //search in row
      const auto& row = matrix[x+steps];
      const auto& start = std::begin(row)+y;
      const auto& end = std::begin(row)+y+steps;
      if(const auto itrow = std::find(start, end, 0); itrow != end  )
        break; //found a 0 in row
      
      //search in column
      for(size_t r = x; r < x+steps; r++)
      {
        if(!matrix[r][y+steps])
          break; //found a zero in col
      }

      //square of side (step+1) exists. Try a larger on next;
      ++steps;
  }

  return steps+1;
  
}


auto maximal_square_brute_force_2(const vector<vector<int>>& matrix)
{
  if (matrix.size() <= 0 || matrix[0].size() <= 0)
      return 0;

    const auto rows = matrix.size();
    const auto cols = matrix[0].size();
    int ans=0;
    for(size_t i = 0 ; i < rows ; i++)
      for(size_t j = 0 ; j < cols ; j++)
        if(matrix[i][j])
         // ans = std::max(ans, largerSquareFromDiagonal(matrix,{i,j}, rows, cols));
      
    return ans * ans;
}
