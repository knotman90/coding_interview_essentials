size_t longest_consecutive_sequence_sorting(std::vector<int>& L)
{
  if (const auto size = L.size(); size <= 1)
    return size;

  std::sort(std::begin(L), std::end(L));
  auto last = std::unique(L.begin(), L.end());
  L.erase(last, L.end());

  size_t ans        = 1;
  auto it_curr      = std::begin(L);
  auto it_next      = std::next(it_curr);
  size_t curr_count = 1;
  while (it_next != std::end(L))
  {
    if ((*it_next) == (*it_curr) + 1)
    {
      curr_count++;
      ans = std::max(ans, curr_count);
    }
    else
    {
      curr_count = 1;
    }
    it_curr = it_next;
    it_next = std::next(it_curr);
  }
  return ans;
}