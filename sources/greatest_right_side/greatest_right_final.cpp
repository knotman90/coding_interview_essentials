void greatest_right_final1(std::vector<int> &V) {
  if (V.size() <= 0)
    return;
  // max so far
  int M = -1;
  int i = V.size() - 1;
  do {
    const int m = std::max(M, V[i]);
    V[i] = M;
    M = m;
    i--;
  } while (i >= 0);
}