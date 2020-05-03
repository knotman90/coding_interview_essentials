// https://cp-algorithms.com/string/string-hashing.html
static constexpr int MOD = 1000000000 + 7;
static constexpr int p   = 31;

constexpr int to_int(const char c)
{
  return c - 'a' + 1;
}

using WordList = std::unordered_map<int, std::vector<string>>;
using Cache    = std::unordered_map<int, bool>;

size_t hash_string(const string& s)
{
  size_t ans = 0;
  for (size_t i = 0, ppow = 1; i < s.size(); i++)
  {
    ans = ans + (to_int(s[i]) * ppow) % MOD;
    ans %= MOD;
    ppow = (ppow * p) % MOD;
  }
  return ans;
}

bool can_break_top_down(const string& s,
                        const int l,
                        const WordList& wl,
                        Cache& cache)
{
  if (l >= s.size())
    return true;

  if (const auto it = cache.find(l); it != cache.end())
    return it->second;

  size_t h = 0;
  std::stringstream ss;
  bool ans = false;
  for (size_t i = l, ppow = 1; !ans && i < s.size(); i++)
  {
    h    = (h + to_int(s[i]) * ppow) % MOD;
    ppow = (ppow * p) % MOD;
    ss << s[i];

    if (auto it = wl.find(h); it != wl.end())
    {
      const auto& words = it->second;
      if (std::find(begin(words), end(words), ss.str()) != words.end()
          && can_break_top_down(s, i + 1, wl, cache))
      {
        ans = true;
      }
    }
  }
  cache[l] = ans;
  return ans;
}

WordList create_wl(const vector<string>& words)
{
  WordList wl;
  for (int i = 0; i < words.size(); i++)
  {
    const auto h = hash_string(words[i]);
    wl[h].push_back(words[i]);
  }
  return wl;
}

bool word_break_top_down(const string& s, const vector<string>& wordDict)
{
  WordList wl = create_wl(wordDict);
  Cache cache;
  return can_break_top_down(s, 0, wl, cache);
}
