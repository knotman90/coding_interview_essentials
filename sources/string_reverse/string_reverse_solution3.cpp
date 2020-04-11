std::string reverse_string_outplace_iterator(const std::string &s)
{
  std::string ans;
  ans.reserve(s.size());

  auto it_s = std::prev(end(s));
  while (it_s >= s.begin())
  {
    ans.push_back(*it_s);
    --it_s;
  }

  return ans;
}