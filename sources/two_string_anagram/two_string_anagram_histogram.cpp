int solution_histogram(const std::string &a, const std::string &b) {
  if (a.length() != b.length())
    return -1;

  std::array<int, 128> F = {0};
  for (int i = 0; i < a.size(); i++) {
    F[a[i] - 'a']++;
    F[b[i] - 'a']--;
  }

  int ans = 0;
  for (const auto x : F)
    if (x > 0)
      ans += x;

  return ans;
}