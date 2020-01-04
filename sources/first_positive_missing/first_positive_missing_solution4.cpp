int first_positive_missing_bruteforce1(const std::vector<int> A) {
  int ans = 0;
  // until ans is found
  while (std::find(begin(A), end(A), ans) != end(A))
    ans++;
  return ans;
}

int first_positive_missing_bruteforce2(const std::vector<int> A) {
  for (int i = 0;; i++) {
    // not found
    if (std::find(begin(A), end(A), i) == end(A))
      return i;
  }
}