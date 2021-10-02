auto merge(const Interval& a, const Interval& b)
{
  Interval ans(a);
  bool ok = false;
  if (a.start >= b.start && a.start < b.end)
  {
    ok        = true;
    ans.start = std::min(a.start, b.start);
    ans.end   = std::max(a.end, b.end);
  }
  return std::make_tuple(ok, ans);
}

unsigned calculate_number_meeting_rooms2(std::vector<Interval>& meetings)
{
  if (meetings.empty())
    return 0;

  std::sort(meetings.begin(), meetings.end(), [](const auto& a, const auto b) {
    if (a.start < b.start)
      return true;
    if (a.start == b.start)
      return a.end > b.end;
    return false;
  });

  unsigned ans = 0;

  return ans;
}