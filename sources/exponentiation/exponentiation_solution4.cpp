unsigned exponentiation_fast_iterative(unsigned n, unsigned k) {
  if (k == 0)
    return 1;

  int ans = 1;
  while (k > 1) {
    if (k & 1) // bit set
      ans *= n;

    k >>= 1;
    n *= n;
  }
  return n * ans;
}