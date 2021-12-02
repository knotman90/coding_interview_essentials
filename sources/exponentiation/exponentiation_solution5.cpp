unsigned exponentiation_linear_recursive(const unsigned n, unsigned k)
{
  if (k == 0)
    return 1;
  // n * n^{k-1}
  return n * exponentiation_linear_recursive(n, k - 1);
}