#include <optional>
class SudokuSolver
{
 public:
  SudokuSolver(std::string _problem) : problem(std::move(_problem))
  {
    assert(problem.size() == 81);
  }
  auto solve()
  {
    printSudoku();
    getBlankCells();
    solve_helper(0);
    printSudoku();
    return problem;
  }

 private:
  void getBlankCells()
  {
    for (int i = 0; i < problem.size(); i++)
      if (problem[i] == '0')
        blankCells.push_back(i);
  }

  char intToChar(const char num)
  {
    assert(num >= '0' && num <= '9');
    return num;
  }

  bool canInsertInRow(const auto x, const auto row)
  {
    assert(row >= 0 && row < 9);
    auto start = std::begin(problem) + 9 * row;
    auto end   = start + 9;
    return find(start, end, intToChar(x)) == end;
  }

  bool canInsertInCol(const auto x, const auto column)
  {
    int curr = column;
    while (curr < 81)
    {
      if (problem[curr] == intToChar(x))
        return false;
      curr += 9;
    }
    return true;
  }

  bool canInsertInSquare(const auto x, const auto square)
  {
    int start_cell = (3 * 9 * (square / 3)) + (3 * (square % 3));
    for (int i = 0; i < 3; i++)
    {
      const bool found = (problem[start_cell + i * 9] == intToChar(x))
                         || (problem[start_cell + i * 9 + 1] == intToChar(x))
                         || (problem[start_cell + i * 9 + 2] == intToChar(x));
      if (found)
        return false;
    }
    return true;
  }
  bool canInsert(const auto x, const auto pos)
  {
    const auto row    = pos / 9;
    const auto col    = pos % 9;
    const auto square = (row / 3) * 3 + (col / 3);
    return canInsertInRow(x, row) && canInsertInCol(x, col)
           && canInsertInSquare(x, square);
  }

  void printSudoku()
  {
    for (int i = 0; i < 9; i++)
    {
      for (size_t j = 0; j < 9; j++)
      {
        cout << problem[i * 9 + j] << " ";
      }
      cout << endl;
    }
  }

  bool solve_helper(const int i)
  {
    if (i >= blankCells.size())
    {
      return true;
    }
    auto pos = blankCells[i];
    cout << pos << " +++++++   " << endl;
    // printSudoku();
    //  cout<<endl;
    for (char x = '1'; x <= '9'; x++)
    {
      problem[pos] = '0';
      /* if(pos == 27)
           cout<<"here";*/
      if (canInsert(x, pos))
      {
        problem[pos] = x;
        if (solve_helper(i + 1))
          return true;
      }
    }
    problem[pos] = '0';
    return false;
  }

  std::string problem;
  std::vector<int> blankCells;
};

std::string solve_sudoku_backtracking(std::string& sudoku)
{
  SudokuSolver solver(sudoku);
  solver.solve();
  return solver.solve();
}
