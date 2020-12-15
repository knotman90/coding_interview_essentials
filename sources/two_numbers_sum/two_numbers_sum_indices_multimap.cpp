bool two_numbers_sum_sorting_indices(vector<int> &A, const int T)
{
  multimap<int, int> N;

  for (int i = 0; i < nums.size(); i++)
    N.insert({nums[i], i});

  auto it = N.begin();
  while (it != N.end())
  {
    auto val       = *it;
    it             = N.erase(it);
    const int rest = target - val.first;

    if (auto itr = N.find(rest); itr != N.end())
      return {val.second, itr->second};
  }

  return {-1};
}