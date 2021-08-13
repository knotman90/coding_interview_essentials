#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "sudoku_solution1.cpp"
#include "sudoku_solution2.cpp"

class SudokuFixuture : public ::testing::Test
{
  const char* const sudoku_dataset_file = "test/sudoku/sudoku.csv";
  using PuzzleSolution                  = std::pair<std::string, std::string>;

 protected:
  void SetUp() override
  {
    std::ifstream infile(sudoku_dataset_file);
    ASSERT_TRUE(infile);
    std::string puzzle, solution;
    while (std::getline(infile, puzzle, ',') && std::getline(infile, solution))
    {
      puzzles_solutions.emplace_back(PuzzleSolution(puzzle, solution));
    }
  }

  template <typename SolverFunction>
  void solveAllSudokus()
  {
    int i = 0;
    for (const auto sudoku : puzzles_solutions)
    {
      auto [puzzle, solution] = sudoku;
      SolverFunction solver(puzzle);
      const auto& result = solver.solve();
      ASSERT_EQ(solution, result);
      cout << "Solved Sudoku " << i++ << endl;
    }
  }

 private:
  std::vector<PuzzleSolution> puzzles_solutions;
};

TEST_F(SudokuFixuture, test1)
{
  solveAllSudokus<SudokuSolver>();
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
