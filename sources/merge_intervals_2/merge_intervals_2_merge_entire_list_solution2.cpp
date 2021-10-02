

std::vector<Interval> merge_list_intervals_entire_list_bruteforce(
    std::vector<Interval>& intervals)
{
  if (intervals.size() <= 0)
    return intervals;

  std::vector<Interval> ans;
  std::vector<bool> excluded(intervals.size(), false);

  for (size_t i = 0; i < intervals.size(); i++)
  {
    if (excluded[i])
      continue;
    ans.push_back(intervals[i]);
    excluded[i] = true;
    for (size_t j = i + 1; j < intervals.size(); j++)
    {
      if (const auto [ok, merged] = merge(ans.back(), intervals[j]);
          !excluded[j] && ok)
      {
        ans.back()  = merged;
        excluded[j] = true;
      }
    }
  }

  return ans;
}
