template <typename Iterator>
auto find_range(Iterator begin, Iterator end, Iterator closest, int k, const int x)
{
  assert(begin < end);
  assert(closest >= begin);
  assert(closest < end);

  auto l        = closest;
  auto r        = l + 1;
  auto difference = [](const auto x, const auto y) { return std::abs(x - y); };
  
  k--; //closest is already included in the range
  while (k && l > begin && r < end)
  {
    if (difference(*(l-1), x) <= difference(*r, x))
    {
      l--;
    }
    else
    {
      r++;
    }
    k--;
  }
  while (k && l > begin)
  {
    l--;
    k--;
  }
  while (k && r < end)
  {
    r++;
    k--;
  }
  assert(k == 0);

  return std::make_tuple(l, r);
}
std::vector<int> kth_closest_in_array_binary_search_lower_bound(
    const vector<int>& I, const int k, const int x)
{
  auto closest = std::lower_bound(begin(I), end(I), x);
  if (auto prec = std::prev(closest);
      closest != begin(I) && closest != end(I) && (std::abs(*closest -x) >= std::abs(*prec -x)))
  {
    closest = prec;
  }
  // if no element is larger than x
  // then the closest to it is the largest in I
  if (closest == end(I))
    closest = std::prev(end(I));

  auto [l, r] = find_range(begin(I), end(I), closest, k,x);
  return std::vector<int>(l,  r);
}