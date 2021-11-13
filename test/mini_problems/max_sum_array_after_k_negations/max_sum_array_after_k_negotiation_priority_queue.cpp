int largestSumAfterKNegations(vector<int>& nums, int k)
{
  std::priority_queue<int, std::vector<int>, std::greater<int>> P(nums.begin(),
                                                                  nums.end());
  while (k--)
  {
    auto x = P.top();
    P.pop();
    P.push(-x);
  }
  int ans = 0;
  while (!P.empty())
  {
    ans += P.top();
    P.pop();
  }
  return std::accumulate(P.begin(), P.end(), 0);
}