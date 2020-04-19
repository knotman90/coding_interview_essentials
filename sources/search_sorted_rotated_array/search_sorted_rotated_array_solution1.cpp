int search_sorted_rotated_array_bruteforce(const std::vector<int>& A,
                                           const int t)
{
  const auto it = std::find(std::begin(A), std::end(A), t);
  return it != std::end(A) ? std::distance(std::begin(A), it) : -1;
}