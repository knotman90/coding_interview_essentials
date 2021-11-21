void addNeighbors(const std::string w,
                  const int count,
                  std::queue<std::pair<std::string, int>>& Q,
                  std::unordered_set<std::string>& visited,
                  const std::unordered_set<std::string>& W_un_set)
{
  const auto size = w.size();
  for (int i = 0; i < size; i++)
  {
    for (char c = 'a'; c <= 'z'; c++)
    {
      if (c != w[i])
      {
        std::string nw = w;
        nw[i]          = c;
        if (!visited.contains(nw) && W_un_set.contains(nw) )
        {
          visited.insert(nw);
          Q.push({nw, count + 1});
        }
      }
    }
  }
}

int word_ladder_BFS(const std::string s,
                    const std::string e,
                    const std::vector<std::string>& W)
{
  std::unordered_set<std::string> W_un_set(W.begin(), W.end());
  if (!W_un_set.contains(e)) //no solution if e is not in W_un_set 
    return 0;

  std::queue<std::pair<std::string, int>> Q;
  std::unordered_set<std::string> visited;
  Q.push({s, 0});
  visited.insert(s);

  while (!Q.empty())
  {
    auto [w, c] = Q.front();
    Q.pop();
    if (w == e)
      return c + 1;
    addNeighbors(w, c, Q, visited, W_un_set);
  }
  return 0;
}