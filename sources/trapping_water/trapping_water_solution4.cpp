int trapping_water_stack(const std::vector<int> &H)
{
  int ans = 0, current = 0;
  // w store indexes of the bars
  std::stack<int> w;

  for (size_t bar_right = 0; bar_right < H.size(); bar_right++)
  {
    while (!w.empty() && H[bar_right] > H[w.top()])
    {
      const int old_top = w.top();
      w.pop();
      if (w.empty())
        break;
      const int bar_left = w.top();
      const int distance = bar_right - bar_left - 1;
      const int bounded_height =
          std::min(H[bar_right], H[bar_left]) - H[old_top];
      ans += distance * bounded_height;
    }
    w.push(bar_right);
  }
  return ans;
}
