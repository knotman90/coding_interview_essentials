std::vector<int> count_bits_DP_powers(const unsigned n)
{
  std::vector<int> B(n + 1, 0);
  for (int i = 1, next_pow = 2, back_idx = 0; i <= n; i++)
  {
    if (i == next_pow)
    {
      //next power of two. 
      next_pow *= 2;
      //we use all the solutions from the start to build the next ones
      back_idx = 0;
    }
    B[i] = 1 + B[back_idx++];
  }
  return B;
}
