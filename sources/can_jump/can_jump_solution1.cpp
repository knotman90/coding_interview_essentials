bool can_jump_DFS_helper(const vector<int>& nums,
                         vector<bool>& visited,
                         const int n)
{
  const int tgt = nums.size() - 1;
  if (n == tgt)
    return true;

  visited[n] = true;

  int l          = std::max(0, n - nums[n]);
  int r          = std::min(tgt, n + nums[n]);
  bool sol_found = (r == tgt);
  for (int i = l; i <= r && !sol_found; i++)
  {
    if (visited[i])
      continue;

    sol_found = can_jump_DFS_helper(nums, visited, i);
  }
  return sol_found;
}

bool can_jump_DFS(const vector<int>& nums)
{
  std::vector<bool> visited(nums.size(), false);
  return can_jump_DFS_helper(nums, visited, 0);
}
