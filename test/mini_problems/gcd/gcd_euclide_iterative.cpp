int gcd_euclide_iterative(int x, int y)
{
  while ((x % y) != 0)
  {
    const auto reminder = x % y;
    x                   = y;
    y                   = reminder;
  }
  return y;
}
