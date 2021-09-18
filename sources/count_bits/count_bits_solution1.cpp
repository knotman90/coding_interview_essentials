unsigned my_pop_count(unsigned num)
{
  int ans = 0;
  while (num)
  {
    ans += num & 1;  // is the last bit set
    num >>= 1;       // shift num one bit to the right
  }
  return ans;
}

std::vector<int> count_bits_bruteforce(const unsigned n)
{
  std::vector<int> ans;
  ans.reserve(n + 1);
  for (unsigned num = 0; num <= n; num++)
  {
    // alternatively std::popcount or __builtin_popcount (only on gcc)
    const int num_bit_set = my_pop_count(num);
    assert(std::popcount(num) == num_bit_set);

    ans.push_back(num_bit_set);
  }
  return ans;
}