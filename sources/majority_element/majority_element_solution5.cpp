int find_majority_element_linear(const std::vector<int>& nums)
{
  if (nums.size() <= 0)
    return -1;

  int el    = nums.front();
  int count = 0;
  for (size_t i = 0; i < nums.size(); i++)
  {
    if (nums[i] == el)
    {
      count++;
    }
    else
    {
      count--;
    }
    if (count == 0)
    {
      el    = nums[i];
      count = 1;
    }
  }
  //check that el appears > n/2 times
  if (std::count(begin(nums), end(nums), el) > nums.size() / 2)
    return el;
  return -1;
}
