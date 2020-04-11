std::vector<std::vector<int>> power_set_incremental_improved(const std::vector<int> &A)
{
  const size_t limit = (1ll << A.size()) - 1;
  std::vector<std::vector<int>> PS;
  PS.push_back({});

  size_t lim = 1;
  for (const auto a : A)
  {
    for (int i = 0; i < lim; i++)
    {
      std::vector<int> subset = PS[i];
      subset.push_back(a);
      PS.push_back(subset);
    }
    lim = PS.size();
  }

  return PS;
}