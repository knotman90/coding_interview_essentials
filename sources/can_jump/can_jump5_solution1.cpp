using Index = size_t;
using Graph = std::unordered_map<Index, std::vector<Index>>;

Graph build_graph(vector<int>& arr, int d)
{
  Graph ans;
  for (int i = 0; i < arr.size(); i++)
  {
    int curr       = arr[i];
    const int left = (i >= d) ? i - d : 0;
    for (int j = i - 1; j >= left; j--)
    {
      auto next = arr[j];
      if (curr <= next)
        break;

      ans[i].push_back(j);
    }

    for (int j = i + 1; j < arr.size() && j <= i + d; j++)
    {
      auto next = arr[j];
      if (curr <= next)
        break;
      ans[i].push_back(j);
    }
  }
  return ans;
}

using Cache = std::unordered_map<Index, int>;
int count   = 0;
int visit(const Graph& g, const size_t pos, Cache& c)
{
  if (g.find(pos) == g.end())
    return 0;
  if (c.find(pos) != c.end())
    return c[pos];

  int ans               = 0;
  const auto& neighbors = (g.find(pos))->second;
  for (const auto& n : neighbors)
  {
    count++;
    ans = std::max(ans, 1 + visit(g, n, c));
  }
  c[pos] = ans;
  return ans;
}

int max_jumps5__memoized(vector<int>& arr, int d)
{
  const auto g = build_graph(arr, d);

  Cache c;
  int ans = 0;
  for (size_t i = 0; i < arr.size(); i++)
  {
    ans = std::max(ans, visit(g, i, c));
  }
  std::cout << count << std::endl;
  return 1 + ans;
}