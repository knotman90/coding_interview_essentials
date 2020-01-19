int string_to_int1(const std::string &s) {
  int ans = 0;
  int p = 1; // 10^i
  for (int i = s.size() - 1; i >= 0; i--) {
    const int char_to_int = (int)(s[i] - '0');
    ans += char_to_int * p;
    p *= 10;
  }
  return ans;
}