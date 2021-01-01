


void nqueen_one_per_row_helper(const unsigned n,
                               const int current_row,
                               Solution& solution_candidate,
                               std::vector<ChessBoardSnapshot>& ans)
{
  if (current_row >= n)
  {
    if (is_valid_solution(solution_candidate))
      ans.push_back(make_chessboard_snapshot(solution_candidate));
    return;
  }

  // try to place a queen in each of the column of this row
  for (unsigned column = 0; column < n; column++)
  {
    solution_candidate.push_back(CellCoordinate(current_row, column));
    nqueen_one_per_row_helper(n, current_row + 1, solution_candidate, ans);
    solution_candidate.pop_back();
  }
}

auto nqueen_one_per_row(const unsigned n)
{
  Solution sol_candidate;
  std::vector<ChessBoardSnapshot> ans;
  nqueen_one_per_row_helper(n, 0, sol_candidate, ans);
  return ans;
}