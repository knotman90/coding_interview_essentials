using cell = std::pair<int, int>;
void visit(const cell& c,
           const std::vector<std::vector<bool>>& grid,
           std::vector<std::vector<bool>>& visited)
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
    visited[x][y]     = true;

    constexpr std::array<cell, 4> cross = {
      cell{ -1, 0 }, cell{ 1, 0 }, cell{ 0, -1 }, cell{ 0, 1 }
    };
    for (const auto& inc : cross)
    {
      const auto nx = x + inc.first;
      const auto ny = y + inc.second;
      if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] && !visited[nx][ny])
      {
        S.push({ nx, ny });
      }
    }
  }
}

int count_island_iterative_DFS(const std::vector<std::vector<bool>>& grid)
{
  if (grid.size() == 0 || grid[0].size() == 0)
    return 0;

  const int n = grid.size();
  const int m = grid[0].size();
  int ans     = 0;

  std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
  // search for a piece of unvisited land
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (!grid[i][j] || visited[i][j])
        continue;
      // found one, mark as visited all the piece of
      // land you can reach from here
      ans++;
      visit({ i, j }, grid, visited);
    }
  }
  return ans;
}