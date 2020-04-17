bool validate_parenthesized_string_bruteforce_helper(std::string s,
                                                     const int pos,
                                                     const int open,
                                                     const int closed)
{
  if (pos == s.size())
    return open==closed;

  if (closed > open)
    return false;

  //cout<<pos<<" "<<open<<" "<<closed<<endl;

  const char curr = s[pos];
  bool ans = false;
  if (curr != '{')
    ans = validate_parenthesized_string_bruteforce_helper(s, pos + 1, open, closed + 1);

  if (curr != '}' && !ans)
    ans = validate_parenthesized_string_bruteforce_helper(s, pos + 1, open + 1, closed);

  if (curr == '*' && !ans)
    ans = validate_parenthesized_string_bruteforce_helper(s, pos + 1, open, closed);
  return ans;
}

bool validate_parenthesized_string_bruteforce(std::string s)
{
  return validate_parenthesized_string_bruteforce_helper(s, 0, 0, 0);
}