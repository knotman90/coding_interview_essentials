int trapping_water_two_pointers(const std::vector<int>& H)
{
  int m_l, m_r;
  m_l = m_r = 0;

  int l = 0;
  int r = H.size() - 1;

  int ans = 0;
  while (l < r)
  {
    if (H[l] <= H[r])
    {
      m_l = std::max(m_l, H[l]);
      ans += m_l - H[l];
      l++;
    }
    else
    {
      m_r = std::max(m_r, H[r]);
      ans += m_r - H[r];
      r--;
    }
  }
  return ans;
}