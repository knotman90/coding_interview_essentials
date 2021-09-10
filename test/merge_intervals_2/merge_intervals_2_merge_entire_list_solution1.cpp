auto merge(const Interval& a, const Interval& b)
{
  Interval ans(a);
  bool ok = false;
  if (b.start >= a.start && b.start <= a.end)
  {
    ok      = true;
    ans.end = std::max(a.end, b.end);
  }
  return std::make_tuple(ok, ans);
}

std::vector<Interval> merge_list_intervals_entire_list_lin_time(
    std::vector<Interval>& intervals)
{
  if (intervals.size() <= 0)
    return intervals;

  std::sort(std::begin(intervals),
            std::end(intervals),
            [](const auto& a, const auto& b) {
              return (a.start < b.start)
                     || ((a.start == b.start) && (a.end < b.end));
            });

  std::vector<Interval> ans;
  ans.push_back(intervals.front());
  for (size_t i = 1; i < intervals.size(); i++)
  {
    if (auto [ok, merged] = merge(ans.back(), intervals[i]); ok)
      ans.back() = merged;
    else
      ans.push_back(intervals[i]);
  }
  return ans;
}
