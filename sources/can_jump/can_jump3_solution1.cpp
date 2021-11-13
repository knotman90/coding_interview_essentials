bool can_jump3_DFS(const std::vector<int>& I, const int s)
{
  const auto size = I.size();
  std::vector<bool> visited(size, false);
  std::stack<int> S;
  S.push(s); //start the visit from s
  while (!S.empty())
  {
    const auto curr = S.top();
    S.pop();
    if (I[curr] == 0)
    {
      return true; //we have reached a node of the type we want
    }
    visited[curr] = true;
    if (const auto right = curr + I[curr]; right < size && !visited[right])
    {
      S.push(right);
    }
    if (const auto left = curr - I[curr]; left >= 0 && !visited[left])
    {
      S.push(left);
    }
  }
  return false;
}