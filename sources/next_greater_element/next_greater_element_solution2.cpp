std::vector<int> 
next_greater_element_I_set(const std::vector<int>& A,
                           const std::vector<int>& B)
{
  std::vector<int> C(A.size());
  std::set<int> N;
  std::unordered_map<int, int> C_val;

  for (int idx_B = B.size() - 1; idx_B >= 0; idx_B--)

  {
    auto it         = N.upper_bound(B[idx_B]);
    C_val[B[idx_B]] = it != N.end() ? *it : -1;
    N.insert(B[idx_B]);
  }
  for (int i = 0; i < std::ssize(A); i++)
  {
    C[i] = C_val[A[i]];
  }
  return C;
}