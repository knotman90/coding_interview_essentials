bool can_complete_loop_from_station(const std::vector<int>& G,
                                    const std::vector<int>& C,
                                    const int station)
{
  const auto size  = G.size(); 
  int curr_station = station;
  int next_station = (curr_station + 1) % size;
  int tank         = G[curr_station];
  while (next_station != station)
  {
    if (tank < C[curr_station])
    {
      return false;
    }
    tank -= C[curr_station];
    curr_station = next_station;
    next_station = (curr_station + 1) % size;
    tank += G[curr_station];
  }
  return tank >= C[curr_station]; //make sure you can make the last leg
}

int solve_gast_station_bruteforce(const std::vector<int>& G,
                                  const std::vector<int>& C)
{
  const auto size = G.size();
  if(size == 1)
    return 0;

  for (int i = 0; i < size; i++)
  {
    if (can_complete_loop_from_station(G, C, i))
      return i;
  }
  return -1;
}