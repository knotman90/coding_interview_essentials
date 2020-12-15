bool two_numbers_sum_sorting_indices_multimap_2(std::vector<int> &A,
                                                const int T)
{
  std::vector<int> twoSum(vector<int> & nums, const int target)
  {
    map<int, int> N;

    for (int i = 0; i < nums.size(); i++)
    {
      const int rest = target - nums[i];
      if (auto itr = N.find(rest); itr != N.end())
        return {i, itr->second};
      N.insert({nums[i], i});
    }

    return {-1};
  }
}