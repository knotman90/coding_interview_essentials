inline bool is_odd(const int x)
{
  return x & 1;
}
int odd_appearing_element_bruteforce_rawloop(const std::vector<int>& A)
{
  for (const auto& x : A)
  {
    const size_t number_appeareance = std::count(begin(A), end(A), x);
    if (is_odd(number_appeareance))
      return x;
  }
  throw std::invalid_argument(
      "Invalid input array. No elements appear an odd number of times");
}