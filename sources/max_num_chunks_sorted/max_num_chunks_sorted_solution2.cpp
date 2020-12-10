int max_chunks_to_sorted_lineartime(std::vector<int>& arr)
{
  constexpr int INF = std::numeric_limits<int>::min();

  if (arr.size() <= 0)
    return 0;

  std::set<int> N(std::begin(arr), std::end(arr));
  int ans      = 0;
  int curr_max = INF;
  for (int i = 0; i < std::ssize(arr); i++)
  {
    N.erase(arr[i]);
    const int new_max = std::max(curr_max, arr[i]);
    if (N.size() > 0 && new_max >= *(N.begin()))
    {
      curr_max = new_max;
    }
    else
    {
      ans++;
      curr_max = INF;
    }
  }
  return ans;
}
