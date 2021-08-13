unsigned exponentiation_fast_iterative_simple(unsigned n, unsigned k)
{
  if (k == 0)
    return 1;

  int ans = 1;
  for (int i = 0; i < std::numeric_limits<int>::digits; i++)
  {
    const bool bit = (k >> i) & 1;
    if (bit)
      ans *= n;
    n *= n;
  }
  return ans;
}