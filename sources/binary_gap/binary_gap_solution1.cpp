int binary_gap_raw_loop(const int n)
{
  int ans = 0;

  int nn      = n;
  int count   = 0;
  bool found1 = false;
  while (nn > 0)
  {
    const int bit = nn & 1;
    if (!bit)
    {
      ++count;
    }
    else
    {
      if (found1)
      {
        ans = std::max(ans, count);
      }
      count  = 0;
      found1 = true;
    }
    nn >>= 1;
  }
  return ans;
}