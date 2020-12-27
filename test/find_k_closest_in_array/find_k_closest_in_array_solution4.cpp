#include "my_lower_bound.h"

std::vector<int> kth_closest_in_array_my_lower_bound(vector<int>& I,
                                                     const int k,
                                                     const int x)
{
  auto closest = my_lower_bound(begin(I), end(I), x);
  if (auto prec = std::prev(closest);
      closest != begin(I) && closest != end(I)
      && (std::abs(*closest - x) >= std::abs(*prec - x)))
  {
    closest = prec;
  }
  // if no element is larger than x
  // then the closest to it is the largest in I
  if (closest == end(I))
    closest = std::prev(end(I));

  auto [l, r] = find_range(begin(I), end(I), closest, k, x);
  return std::vector<int>(l, r);
}