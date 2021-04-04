bool unique_elements_map(const std::string &s)
{
  std::unordered_set<char> L;
  for (size_t i = 0; i < s.size(); i++)
  {
    if (L.contains(s[i]))
      return false;
    L.insert(s[i]);
  }
  return true;
}