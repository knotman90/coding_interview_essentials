int stair_climbing_arbitrary(const int n, const std::vector<int> &steps)
{
  if (n < 0)
    return 0;
  if (n == 0)
    return 1;

  int ans = 0;
  for (int i = 0; i < steps.size(); i++)
    ans += stair_climbing_arbitrary(n - steps[i], steps);

  return ans;
}