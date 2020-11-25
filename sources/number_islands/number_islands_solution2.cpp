using cell = std::pair<int, int>;

void visit(const cell& c, std::vector<std::vector<bool>>& grid)
{
  const int n = grid.size();
  const int m = grid[0].size();

  std::stack<cell> S;
  S.push(c);
  while (!S.empty())
  {
    auto p = S.top();
    S.pop();

    const auto [x, y] = p;
    grid[x][y]        = false;  // mark the original map

    constexpr std::array<cell, 4> cross = {
        cell{-1, 0}, cell{1, 0}, cell{0, -1}, cell{0, 1}};
    for (const auto& inc : cross)
    {
      const auto nx = x + inc.first;
      const auto ny = y + inc.second;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny])
      {
        S.push({nx, ny});
      }
    }  // for
  }    // while
}

int count_island_iterative_DFS_improved(std::vector<std::vector<bool>>& grid)
{
  if (grid.size() == 0 || grid[0].size() == 0)
    return 0;

  const int n = grid.size();
  const int m = grid[0].size();
  int ans     = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      // visited cells are turned into water during the visit
      if (!grid[i][j])
        continue;
      ans++;
      visit({i, j}, grid);
    }
  }
  return ans;
}
