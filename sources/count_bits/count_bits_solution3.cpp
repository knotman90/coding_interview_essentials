std::vector<int> count_bits_DP_short(const unsigned n)
{
  std::vector<int> B(n + 1, 0);
  for (unsigned num = 1; num <= n; num++)
    B[num] = B[num >> 1] + (num & 1);
  return B;
}
