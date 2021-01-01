auto nqueen_one_per_row_and_column(const unsigned n)
{

  Solution sol_candidate;
  std::vector<ChessBoardSnapshot> ans;
  nqueen_one_per_row_helper(n, 0, sol_candidate, ans);
  return ans;
}