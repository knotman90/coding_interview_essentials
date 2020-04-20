using cell = std::pair<int, int>;
void visit_recursive(const cell& c, std::vector<std::vector<bool>>& grid)
{
  const int n = grid.size();
  const int m = grid[0].size();

  const auto [x, y] = c;
  // base case: a cell is out of the map or already visited or water
  if (x < 0 || y < 0 || x >= n || y >= m || !grid[x][y])
    return;

  // mark as visited
  grid[x][y] = false;

  // visit all cells that can potentially extend this island
  visit_recursive({x + 1, y}, grid);
  visit_recursive({x - 1, y}, grid);
  visit_recursive({x, y + 1}, grid);
  visit_recursive({x, y - 1}, grid);
}
int count_island_recursive_DFS(std::vector<std::vector<bool>>& grid)
{
  if (grid.size() == 0 || grid[0].size() == 0)
    return 0;

  const int n = grid.size();
  const int m = grid[0].size();
  int ans     = 0;

  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (grid[i][j])
      {
        ans++;
        visit_recursive({i, j}, grid);
      }

  return ans;
}
