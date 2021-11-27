constexpr int gcd_euclide_cpp11(const int x, const int y)
{
  return (x % y == 0) ? y : gcd_euclide_cpp11(y, x % y);
}
