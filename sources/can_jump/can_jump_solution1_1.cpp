bool can_jump_DFS_forward_only_helper(const vector<int>& nums, const int n)
{
  const int tgt = nums.size() - 1;
  if (n == tgt)
    return true;

  int r = std::min(tgt, n + nums[n]);
  for (int i = n + 1; i <= r; i++)
  {
    if (can_jump_DFS_forward_only_helper(nums, i))
      return true;
  }
  return false;
}

bool can_jump_DFS_forward_only(const vector<int>& nums)
{
  return can_jump_DFS_forward_only_helper(nums, 0);
}
