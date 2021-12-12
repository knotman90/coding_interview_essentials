enum Direction
{
  RIGHT,
  DOWN,
  LEFT,
  UP
};
std::vector<int> spiral_matrix_solution(const std::vector<std::vector<int>>& M)
{
  int rows = M.size();
  int cols = M.back().size();

  std::vector<int> visited = {};
  Direction curr_direction = RIGHT;
  int currx = 0, curry = 0;
  bool skip = false;

  int y_up_limit    = 0;
  int y_down_limit  = rows - 1;
  int x_left_limit  = 0;
  int x_right_limit = cols - 1;
  while (visited.size() < rows * cols)
  {
      assert((currx <= x_right_limit) && (currx >= x_left_limit));
      assert((curry >= y_up_limit) && (curry <= y_down_limit));

    if (!skip)
    {
      visited.push_back(M[curry][currx]);
    }
    skip = false;
    switch (curr_direction)
    {
      case RIGHT:
        if (currx == x_right_limit)
        {
          curr_direction = DOWN;
          skip           = true;
          y_up_limit++;
          continue;
        }
        currx++;
        break;
      case DOWN:
        if (curry == y_down_limit)
        {
          curr_direction = LEFT;
          skip           = true;
          x_right_limit--;
          continue;
        }
        curry++;
        break;
      case LEFT:
        if (currx == x_left_limit)
        {
          curr_direction = UP;
          y_down_limit--;
          skip = true;
          continue;
        }
        currx--;
        break;
      case UP:
        if (curry == y_up_limit)
        {
          curr_direction = RIGHT;
          x_left_limit++;
          skip = true;
          continue;
        }
        curry--;
        break;
    }
  }
  return visited;
}
