void greatest_right_final2(std::vector<int> &V) {
  if (V.size() > 0) {
    for (int i = V.size() - 2, M = V.back(); i >= 0; i--) {
      const int m = std::max(M, V[i]);
      V[i] = M;
      M = m;
    }
    V.back() = -1;
  }
}