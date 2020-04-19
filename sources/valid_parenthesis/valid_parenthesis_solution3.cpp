bool validate_parenthesized_string_linear(std::string s)
{
  int min, max;
  min = max = 0;
  for (const char c : s)
  {
    if (c == '(')
    {
      min++;
      max++;
    }
    if (c == ')')
    {
      if (min > 0)
        min--;
      max--;
    }
    if (c == '*')
    {
      if (min > 0)
        min--;
      max++;
    }
    if (max < 0)
      return false;
  }
  return min == 0;
}