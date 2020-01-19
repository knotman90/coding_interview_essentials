
std::string reverse_string_outplace_raw_loop(const std::string &s) {

  std::string ans;
  ans.reserve(s.size());

  for (int i = s.size() - 1; i >= 0; i--)
    ans.push_back(s[i]);

  return ans;
}
