#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "square_in_matrix_solution1.cpp"
#include "square_in_matrix_solution2.cpp"
#include "square_in_matrix_solution3.cpp"

TEST(square_in_matrix, test1)
{
  const std::vector<std::vector<int>> M = {
      {1, 0, 1, 0, 0},
      {1, 0, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 0, 0, 1, 0},
  };
  constexpr int expected = 4;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
