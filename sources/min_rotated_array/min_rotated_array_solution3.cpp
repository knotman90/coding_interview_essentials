template <typename T>
auto min_rotated_array_brute_force_log(const std::vector<T> &V)
{
  const auto size = V.size();

  int l = 0, r = size - 1;
  while (l <= r)
  {
    const int mid = l + (r - l) / 2;
    const auto curr = V[mid];
    const auto prec = V[(mid - 1 + size) % size];
    const auto succ = V[(mid + 1) % size];
    

    if ((curr <= prec ) || (curr >= succ))
    {
      return std::min(std::min(curr, succ), prec);
    }

    if (curr > V[0])
      l = mid + 1;
    else
      r = mid - 1;
  }
  return -1;
}