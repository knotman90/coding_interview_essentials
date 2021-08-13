int max_triplet_sum_bruteforce(const std::vector<int>& I)
{
  const auto n = std::ssize(I);
  int ans      = -1;
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++)
    {
      if (!(I[i] < I[j]))
        continue;

      for (int k = j + 1; k < n; k++)
      {
        if (!(I[j] < I[k]))
          continue;
        // here: i < j < k and I[i] < I[j] < I[k]
        ans = std::max(ans, I[i] + I[j] + I[k]);
      }
    }
  }
  return ans;
}