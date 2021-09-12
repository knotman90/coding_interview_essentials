auto merge(const Interval& a, const Interval& b)
{
  Interval ans(a);
  bool ok = false;
  if ((a.start >= b.start && a.start <= b.end) || (b.start >= a.start && b.start <= a.end))
  {
    ok      = true;
    ans.start = std::min(a.start, b.start);
    ans.end = std::max(a.end, b.end);
  }
  return std::make_tuple(ok, ans);
}

std::vector<Interval> merge_list_intervals_entire_list_bruteforce(
    std::vector<Interval>& intervals)
{
  if (intervals.size() <= 0)
    return intervals;

  std::vector<Interval> ans;
  std::vector<bool> excluded(intervals.size(), false);
  
  for (size_t i = 0; i < intervals.size(); i++)
  {  
    if(excluded[i])
      continue;
    ans.push_back(intervals[i]);
    for (size_t j = 1; j < intervals.size(); j++){
        if (const auto [ok, merged] = merge(ans.back(), intervals[j]); !excluded[j] && ok ){
            ans.back() = merged;
            excluded[j] = true;
        }
    }
  }
  

  return ans;
}
