// a pair of indices identifying a substring
using substr = std::tuple<int, int>;

bool validate_parenthesized_string_DP_helper(const std::string& s,
                                             std::map<substr>& DP,
                                             const substr& substr)
{
  const auto [i, j] = substr;
  if ((i - j) <= 0)
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
  else if (!ans && c == '*')
    ans = validate_parenthesized_string_DP_helper(s, DP, std::make_tuple(i + 1, j));
  else if (!ans)
  {
    for (int k = i + 1; !ans && i <= j; k++)
    {
      if (s[k] == ')')
      {
        ans = validate_parenthesized_string_DP_helper(s, DP, std::make_tuple(i+1, k-1))
              && validate_parenthesized_string_DP_helper(s, DP, std::make_tuple(k+1, j));
      }
    }
  }
  DP[substr] = ans;
  return ans;
}

bool validate_parenthesized_string_DP(std::string s)
{
  std::unordered_map<substr> DP;
  return validate_parenthesized_string_DP_helper(s, DP, std::make_tuple(0, s.size() - 1));
}