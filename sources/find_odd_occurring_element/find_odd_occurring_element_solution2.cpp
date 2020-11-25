int odd_appearing_element_bruteforce_standard(const std::vector<int> &A)
{
  return *std::find_if(begin(A), end(A), [&](const auto x) {
    return is_odd(std::count(begin(A), end(A), x));
  });
}