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

  size_t i      = 0;
  bool inserted = false;

  for (; i < intervals.size();)
  {
    if (intervals[i].end < newInterval.start)
    {
      ans.push_back(intervals[i]);
      i++;
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

  while (i < intervals.size())
  {
    if (overlap(intervals[i], ans.back()))
    {
      ans.back().start = std::min(ans.back().start, intervals[i].start);
      ans.back().end   = std::max(ans.back().end, intervals[i].end);
    }
    else
    {
      ans.push_back(intervals[i]);
    }
    i++;
  }

  return ans;
}
