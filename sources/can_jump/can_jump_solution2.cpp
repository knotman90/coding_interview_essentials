bool can_jump_linear(const vector<int>& nums)
{
  const int size = nums.size();
  int m          = size - 1;
  for (auto i = size - 2; i >= 0; i--)
  {
    const int max_reach = i + nums[i];
    if (max_reach >= m)
      m = i;
  }
  return m == 0;
}