int solve_gast_station_lineartime(const std::vector<int>& G,
                                  const std::vector<int>& C)
{
  const int n         = G.size();
  const auto sum_gas  = std::reduce(std::begin(G), std::end(G), 0);
  const auto sum_cost = std::reduce(std::begin(C), std::end(C), 0);

  // if there is not enough gas along the way and we need to make at least one
  // leg of the trip
  if ((sum_gas < sum_cost) && (n > 1))
    return -1;

  if (n <= 0)
    return -1;

  int ans  = 0;
  int tank = 0;
  for (int i = 0; i < n; i++)
  {
    tank += G[i] - C[i];
    if (tank < 0)
    {
      // i+1 is the new starting point. We can ignore all stations from and to
      // (i+1) as they are for sure not good starting point
      ans  = (i + 1) % n;
      tank = 0;
    }
  }
  return ans;
}