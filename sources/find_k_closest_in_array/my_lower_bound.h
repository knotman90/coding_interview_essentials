
template <typename It, typename Target = typename It::value_type>
It my_lower_bound(const It& begin, const It& end, const Target& target)
{
  auto l = begin;
  auto r = end;
  while (l < r)
  {
    auto mid = l + std::distance(l, r) / 2;

    if (*mid < target)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }
  return l;
}
