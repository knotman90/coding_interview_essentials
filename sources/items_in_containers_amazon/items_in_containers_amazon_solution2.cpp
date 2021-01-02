
std::vector<int> prefix_sum_containers_items(const std::string& s)
{
  std::vector<int> cont_prefix_sum;
  cont_prefix_sum.reserve(s.size());

  auto it = std::begin(s);
  while (it != std::end(s) && *it != '|')
  {
    cont_prefix_sum.push_back(0);
    it = std::next(it);
  }
  cont_prefix_sum.push_back(0);
  it = std::next(it);

  int cont_curr_countainer = 0;
  while (it != std::end(s))
  {
    const auto count_prev_containers =
        (cont_prefix_sum.size() > 0 ? cont_prefix_sum.back() : 0);
    if (*it == '|')
    {
      // sum of the previous and previous container items
      cont_prefix_sum.push_back(count_prev_containers + cont_curr_countainer);
      cont_curr_countainer = 0;
    }
    else
    {
      cont_prefix_sum.push_back(count_prev_containers);
      cont_curr_countainer++;
    }
    it = std::next(it);
  }
  return cont_prefix_sum;
}

std::vector<int> find_closest_bars_right(const std::string& s)
{
  std::vector<int> ans(s.size());
  int idx_last_bar = std::ssize(s) - 1;
  for (int i = std::ssize(s) - 1; i >= 0; i--)
  {
    if (s[i] == '|')
      idx_last_bar = i;
    ans[i] = idx_last_bar;
  }
  return ans;
}
std::vector<int> items_in_containers_lineartime(const std::string& s,
                                                const std::vector<Query>& Q)
{
  const std::vector<int>& prefix_sum_count_items =
      prefix_sum_containers_items(s);
  const std::vector<int>& closest_bars_right = find_closest_bars_right(s);

  std::vector<int> ans;
  ans.reserve(Q.size());
  for (const auto& [start, end] : Q)
  {
    const auto& new_start = closest_bars_right[start];
    if (new_start >= end)
    {
      ans.push_back(0);
    }
    else
    {
      const auto& count_before_start =
          (new_start <= 0) ? 0 : prefix_sum_count_items[new_start];
      ans.push_back(prefix_sum_count_items[end] - count_before_start);
    }
  }
  return ans;
}