// a pair of indices identifying a substring
using pii = std::pair<int, int>;

struct pair_hash
{
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2>& pair) const
  {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

bool validate_parenthesized_string_DP_helper(
    const std::string& s,
    std::unordered_map<pii, bool, pair_hash>& DP,
    const pii& substr)
{
  const auto [i, j] = substr;
  if (i > j)
  {
    // empty string is valid
    return true;
  }

  if (DP.find(substr) != DP.end())
    return DP[substr];

  bool ans     = false;
  const char c = s[i];

  if (c == ')')
    ans = false;

  if (!ans && c == '*')  // try ignoring this character
    ans = validate_parenthesized_string_DP_helper(s, DP, { i + 1, j });

  if (!ans
      && c != ')')  // either * or open brackets. Try turning it into a (
  {
    // find a something that can be turned into a ) further ahead in the
    // string
    for (int k = i + 1; !ans && k <= j; k++)
    {
      if (s[k] == ')' || s[k] == '*')
      {
        //validate the two resulting substring from pairing char i and k
        ans = validate_parenthesized_string_DP_helper(
                  s, DP, { i + 1, k - 1 })
              && (validate_parenthesized_string_DP_helper(
                  s, DP, { k + 1, j }));
      }
    }
  }

  DP[substr] = ans;
  return ans;
}

bool validate_parenthesized_string_DP(const std::string& s)
{
  std::unordered_map<pii, bool, pair_hash> DP;
  const int size = s.size() - 1;
  return validate_parenthesized_string_DP_helper(s, DP, { 0, size });
}