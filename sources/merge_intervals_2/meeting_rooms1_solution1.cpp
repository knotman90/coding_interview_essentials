unsigned calculate_number_meeting_rooms1(const std::vector<Interval>& meetings)
{
    if(meetings.empty())
        return 0;
    
    auto [min_hour, max_hour] = std::tuple(0,0);
    for(const auto [start, end] : meetings){
        min_hour = std::min(min_hour, start);
        max_hour = std::max(max_hour, end);
    }
    
    std::vector<uint> meeting_at_time(max_hour-min_hour);
    unsigned ans = 0;
    const auto shift = -min_hour; // we want min_hour to be mapped to index 0 
    for(auto [start, end] : meetings){
        while(start < end){ //end hour of the meeting is excluded
            const auto shifted_time = start+shift;
            meeting_at_time[shifted_time]++;
            ans = std::max(ans, meeting_at_time[shifted_time]);
            start++;
        }
    }
    return ans;
}