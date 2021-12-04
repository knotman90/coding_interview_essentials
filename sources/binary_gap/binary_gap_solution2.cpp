int binary_gap_raw_loop_skip_trailing_zeros(const int n)
{
  int ans = 0;

  int nn = n;
  //skip all trailing zeros
  while (nn > 0)
  {
    const int bit = nn & 1;
    if (!bit)
    {
      nn >>= 1;
    }
    else
    {
      break;
    }
  }

  int count = 0;
  //nn is either zero or starts with a one (it is odd)
  while (nn > 0)
  {
    const int bit = nn & 1;
    if (!bit)
    {
      ++count;
    }
    else
    {
      ans   = std::max(ans, count);
      count = 0;
    }
    nn >>= 1;
  }
  return ans;
}