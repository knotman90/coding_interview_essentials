bool can_add_queen(const Solution& solution,
                   const CellCoordinate& candidate_position)
{
  const auto sgn = [](auto val) {
    using T = decltype(val);
    return (T(0) < val) - (val < T(0));
  };

  for (int i = 0; i < std::ssize(solution); i++)
  {
    const auto rows_difference = solution[i].first - candidate_position.first;
    const auto cols_difference = solution[i].second - candidate_position.second;

    const bool same_row   = rows_difference == 0;
    const bool same_col   = cols_difference == 0;
    const bool same_diag1 = rows_difference == cols_difference;

    const bool same_diag2 =
        std::abs(rows_difference) == std::abs(cols_difference)
        && sgn(rows_difference) != sgn(cols_difference);
    if (same_row || same_col || same_diag1 || same_diag2)
      return false;
  }
  return true;
}

void nqueen_bruteforce_helper_revised(
    const unsigned n,
    const std::vector<CellCoordinate>& locations,
    const int location_idx,
    Solution& solution_candidate,
    std::vector<ChessBoardSnapshot>& ans)
{
  if (solution_candidate.size() >= n)
  {
    // all intermediate steps have been checked
    ans.push_back(make_chessboard_snapshot(solution_candidate));

    return;
  }

  for (int i = location_idx; i < std::ssize(locations); i++)
  {
    if (!can_add_queen(solution_candidate, locations[i]))
      continue;
    // adding a queen in locations[i] does not conflict with the rest of the
    // queen specified in solution_candidate
    solution_candidate.push_back(locations[i]);
    nqueen_bruteforce_helper_revised(
        n, locations, i + 1, solution_candidate, ans);
    solution_candidate.pop_back();
  }
}

auto nqueen_bruteforce_revised(const unsigned n)
{
  std::vector<CellCoordinate> locations;
  locations.reserve(n * n);
  for (unsigned i = 0; i < n; i++)
    for (unsigned j = 0; j < n; j++)
      locations.push_back(CellCoordinate(i, j));

  Solution sol_candidate;
  std::vector<ChessBoardSnapshot> ans;
  nqueen_bruteforce_helper_revised(n, locations, 0, sol_candidate, ans);
  return ans;
}