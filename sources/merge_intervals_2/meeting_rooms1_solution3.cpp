
unsigned calculate_number_meeting_rooms3_touchpoints(
    const std::vector<Interval>& meetings)
{
  if (meetings.empty())
    return 0;

  std::vector<int> startPoints;
  startPoints.reserve(meetings.size());

  std::vector<int> endPoints;
  endPoints.reserve(meetings.size());

  for (const auto& [s, e] : meetings)
  {
    startPoints.push_back(s);
    endPoints.push_back(e);
  }

  std::sort(std::begin(startPoints), std::end(startPoints));
  std::sort(std::begin(endPoints), std::end(endPoints));

  unsigned ans = 1, concurrentMeetings = 0;
  size_t idxS = 0;  // index on startPoints array
  size_t idxE = 0;  // index on endPoints array
  while (idxS < startPoints.size())
  {
    if (startPoints[idxS] < endPoints[idxE])
    {
      concurrentMeetings++;
      ans = std::max(ans, concurrentMeetings);
      idxS++;
    }
    else
    {
      assert(concurrentMeetings >= 1);
      concurrentMeetings--;
      idxE++;
    }
  }
  return ans;
}