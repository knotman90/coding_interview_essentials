using Index           = size_t;
using EqualIndicesMap = std::unordered_map<int, std::vector<Index>>;

EqualIndicesMap build_equal_map(const std::vector<int>& I)
{
  EqualIndicesMap ans;
  for (size_t i = 0; i < I.size(); i++)
  {
    if (ans.find(I[i]) == ans.end())
    {
      ans.insert({I[i], {i}});
    }
    else
    {
      ans[I[i]].push_back(i);
    }
  }
  return ans;
}

int can_jump4(const std::vector<int>& I)
{
  const auto size            = I.size();
  EqualIndicesMap equals_map = build_equal_map(I);
  std::unordered_set<int> added;

  std::queue<std::pair<int, int>> S;
  S.push({0, 0});
  while (!S.empty())
  {
    const auto [idx, level] = S.front();
    if (idx == size - 1)
      return level;
    S.pop();
    if (added.find(I[idx]) == added.end())
    {
      for (const auto i : equals_map[I[idx]])
      {
        if (i != idx)
        {
          S.push({i, level + 1});
        }
      }
    }
    added.insert(I[idx]);
    if (const auto next = idx + 1;
        next < size && added.find(I[next]) == added.end())
    {
      S.push({next, level + 1});
    }
    if (const auto prev = idx - 1;
        prev >= 0 && added.find(I[prev]) == added.end())
    {
      S.push({prev, level + 1});
    }
  }

  return 0;
}