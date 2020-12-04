bool validate_parenthesized_string_bruteforce_helper(std::string s,
                                                     const size_t pos,
                                                     const int open,
                                                     const int closed)
{
  if (pos == s.size())
    return open == closed;

  if (closed > open)
    return false;

  const char curr = s[pos];
  bool ans        = false;
  if (curr != '{')  // either } or *: add a right parenthesis
    ans = validate_parenthesized_string_bruteforce_helper(
        s, pos + 1, open, closed + 1);

  if (curr != '}' && !ans)  // either {} or *: add a left parenthesis
    ans = validate_parenthesized_string_bruteforce_helper(
        s, pos + 1, open + 1, closed);

  if (curr == '*' && !ans)  // if neither { nor } worked, then ignore this *
    ans = validate_parenthesized_string_bruteforce_helper(
        s, pos + 1, open, closed);

  return ans;
}

bool validate_parenthesized_string_bruteforce(std::string s)
{
  return validate_parenthesized_string_bruteforce_helper(s, 0, 0, 0);
}