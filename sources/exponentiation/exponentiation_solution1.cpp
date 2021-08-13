unsigned exponentiation_linear(const unsigned n, unsigned k)
{
  unsigned ans = 1;
  while (k > 0)
  {
    ans *= n;
    k--;
  }
  return ans;
}