std::string decode_string(const std::string& s)
{
  std::stack<std::pair<int, std::string>> stack;
  stack.push({1, std::string()});
  size_t i  = 0;
  int rep_f = 0;
  while (i < s.size())
  {
    if (std::isdigit(s[i]))
    {
      rep_f *= 10;
      rep_f += (s[i] - '0');
    }
    else if (s[i] >= 'a' && s[i] <= 'z')
    {
      stack.top().second.push_back(s[i]);
    }
    else if (s[i] == ']')
    {
      const auto [rep, str] = stack.top();
      stack.pop();
      for (int i = 0; i < rep; i++)
        stack.top().second += str;
    }
    else if (s[i] == '[')
    {
      stack.push({rep_f, string()});
      rep_f = 0;
    }
    i++;
  }
  assert(stack.size() == 1);
  return stack.top().second;
}