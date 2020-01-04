int first_positive_missing_sorting(std::vector<int> A) {
  std::sort(begin(A), end(A));

  auto it =
      std::find_if(begin(A), end(A), [](const auto &x) { return x >= 0; });

  int expected = 0;
  while (it != end(A) && (*it) == expected) {
    expected++;
    it++;
  }
  return expected;
}