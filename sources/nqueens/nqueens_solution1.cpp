using ChessBoardSnapshot = std::vector<std::string>;
using CellCoordinate     = std::pair<int, int>;
using Solution           = std::vector<CellCoordinate>;

ChessBoardSnapshot make_chessboard_snapshot(const Solution& solution)
{
  ChessBoardSnapshot ans(solution.size(), std::string(solution.size(), '.'));

  for (const auto& queen_location : solution)
  {
    const auto [row, col] = queen_location;
    ans[row][col]         = 'Q';
  }
  return ans;
}

bool is_valid_solution(const Solution& solution)
{

    const auto sgn = [](auto val) {
        using T = decltype(val);
        return (T(0) < val) - (val < T(0));
    };

  for (int i = 0; i < std::ssize(solution); i++)
  {
    for (int j = i + 1; j < std::ssize(solution); j++)
    {
      const auto rows_difference = solution[i].first - solution[j].first;
      const auto cols_difference = solution[i].second - solution[j].second;
      
      const bool same_row   = rows_difference == 0;
      const bool same_col   = cols_difference == 0;
      const bool same_diag1 = rows_difference == cols_difference;
      
      const bool same_diag2 = std::abs(rows_difference) == std::abs(cols_difference) && 
                              sgn(rows_difference) != sgn(cols_difference);
      if (same_row || same_col || same_diag1 || same_diag2)
        return false;
    }
  }
  return true;
}

void nqueen_bruteforce_helper(const unsigned n,
                              const std::vector<CellCoordinate>& locations,
                              const int location_idx,
                              Solution& solution_candidate,
                              std::vector<ChessBoardSnapshot>& ans)
{
  if (solution_candidate.size() >= n)
  {
    if (is_valid_solution(solution_candidate))
      ans.push_back(make_chessboard_snapshot(solution_candidate));

    return;
  }

  for (int i = location_idx; i < std::ssize(locations); i++)
  {
    solution_candidate.push_back(locations[i]);
    nqueen_bruteforce_helper(n, locations, i + 1, solution_candidate, ans);
    solution_candidate.pop_back();
  }
}

auto nqueen_bruteforce(const unsigned n)
{
  std::vector<CellCoordinate> locations;
  locations.reserve(n * n);
  for (unsigned i = 0; i < n; i++)
    for (unsigned j = 0; j < n; j++)
      locations.push_back(CellCoordinate(i, j));

  Solution sol_candidate;
  std::vector<ChessBoardSnapshot> ans;
  nqueen_bruteforce_helper(n, locations, 0, sol_candidate, ans);
  return ans;
}