auto nqueen_one_per_row_and_column(const unsigned n)
{
  std::vector<ChessBoardSnapshot> ans;
  std::vector<int> positions(n);
  std::iota(std::begin(positions), std::end(positions), 0);

  Solution sol_candidate(n);
  do
  {
    for (int i = 0; i < std::ssize(positions); i++)
      sol_candidate[i] = CellCoordinate(i, positions[i]);

    if (is_valid_solution(sol_candidate))
      ans.push_back(make_chessboard_snapshot(sol_candidate));

  } while (std::next_permutation(std::begin(positions), std::end(positions)));

  return ans;
}