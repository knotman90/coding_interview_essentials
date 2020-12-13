int find_majority_element_sorting(std::vector<int>& N)
{
  const size_t threshold = N.size() / 2;
  if (N.size() == 0)
    return -1;

  std::sort(std::begin(N), std::end(N));

  // current.first = number
  // number.second = occurrences
  std::pair<int, int> current;
  for (size_t i = 0; i < N.size(); i++)
  {
    if (N[i] != current.first || i == 0)
      current = {N[i], 1};
    else
      current.second++;

    if (current.second > threshold)
      return current.first;
  }
  return -1;
}
