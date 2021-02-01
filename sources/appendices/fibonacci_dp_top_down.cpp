using Cache = std::unordered_map<unsigned, unsigned>;

unsigned F_helper(const unsigned n, Cache& c)
{
  if (n <= 1)
    return n;
  if (c.contains(n))
    return cache[n];

  const auto ans = F(n - 1) + F(n - 2);
  cache[n]       = ans;
  return ans;
}

unsigned F(const unsigned n)
{
  Cache cache;
  return F_helper(n, cache);
}


