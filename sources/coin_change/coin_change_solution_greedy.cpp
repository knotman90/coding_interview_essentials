// Note:  This algorithm is neither correct nor complete
int change_ways_bruteforce(const std::vector<int>& I, int t)
{
  int ans = 0;

  while (t > 0)
  {
    int greedy_choice = 0;
    for (auto it = I.rbegin(); it != I.rend(); it++)
    {
      if (*it <= t)
      {
        greedy_choice = *it;
        break;
      }
    }
    if (greedy_choice == 0)  // no element smaller or equal to t found
      return -1;

    t -= greedy_choice;
    ans++;  // used one coin
  }
  return ans;
}