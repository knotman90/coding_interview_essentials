template<typename Iterator>
 auto find_range(Iterator begin,
                                            Iterator end,
                                            Iterator closest){
return std::make_tuple(0,0);            
                                            }
    std::vector<int> kth_closest_in_array_binary_search_lower_bound(
        vector<int>& I, const int k, const int x)
{
  auto closest = std::lower_bound(begin(I), end(I), x);
  if (auto prec = std::prev(closest);
      closest != begin(I) && closest != end(I) && (*closest > *prec))
  {
    closest = prec;
  }
  // if no element is larger than x
  // then the closest to it is the largest in I
  if (closest == end(I))
    closest = std::prev(end(I));

  auto [l, r] = find_range(begin(I), end(I), closest, k);
  return std::vector<int>(begin(I) + l, begin(I) + r);
}