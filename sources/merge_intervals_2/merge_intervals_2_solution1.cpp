static bool overlap(const Interval& i1, const Interval& i2)
{
  return (i1.start >= i2.start && i1.start <= i2.end)
         || (i2.start >= i1.start && i2.start <= i1.end);
}

std::vector<Interval> merge_intervals_lineartime(
    const std::vector<Interval>& intervals, Interval newInterval)
{
  std::vector<Interval> ans;
  if (intervals.empty())
  {
    ans.push_back(newInterval);
    return ans;
  }

  size_t k      = 0;
  bool inserted = false;

  for (; k < intervals.size();)
  {
    if (intervals[k].end < newInterval.start)
    {
      ans.push_back(intervals[k]);
      k++;
    }
    else
    {
      inserted = true;
      ans.push_back(newInterval);
      break;
    }
  }
  if (!inserted)
  {
    ans.push_back(newInterval);
    return ans;
  }

  while (k < intervals.size())
  {
    if (overlap(intervals[k], ans.back()))
    {
      ans.back().start = std::min(ans.back().start, intervals[k].start);
      ans.back().end   = std::max(ans.back().end, intervals[k].end);
    }
    else
    {
      ans.push_back(intervals[k]);
    }
    k++;
  }

  return ans;
}
