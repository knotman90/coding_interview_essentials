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
#include "square_in_matrix_solution4.cpp"
#include "square_in_matrix_solution5.cpp"

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
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}


TEST(square_in_matrix, test2)
{
  const std::vector<std::vector<int>> M = {
      {1, 0, 1, 0, 0},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 1},
      {1, 1, 1, 1, 0},
  };
  constexpr int expected = 9;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}


TEST(square_in_matrix, test3)
{
  const std::vector<std::vector<int>> M = {
      {0,0,0,0,0,0},
      {0,0,0,0,0,0},
      {0,0,0,0,0,0},
      {0,0,0,0,0,0},
      {0,0,0,0,0,0},
  };
  constexpr int expected = 0;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}

TEST(square_in_matrix, test4)
{
  const std::vector<std::vector<int>> M = {
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
  };
  constexpr int expected = 64;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}

TEST(square_in_matrix, test5)
{
  const std::vector<std::vector<int>> M = {
      {0,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
  };
  constexpr int expected = 49;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}

TEST(square_in_matrix, test6)
{
  const std::vector<std::vector<int>> M = {
      {0,1,1,1,1,1,1,0},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {1,1,1,1,1,1,1,1},
      {0,1,1,1,1,1,1,0},
  };
  constexpr int expected = 36;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}

TEST(square_in_matrix, test7)
{
  const std::vector<std::vector<int>> M = {
      {0,1,1,1,1,1,1,0},
  };
  constexpr int expected = 1;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}


TEST(square_in_matrix, test8)
{
  const std::vector<std::vector<int>> M = {
      {1},
      {1},
      {1},
      {1},
      {1},
      {1},
      {1},
      {1},
  };
  constexpr int expected = 1;

  EXPECT_EQ(expected, maximal_square_brute_force_1(M));
  EXPECT_EQ(expected, maximal_square_brute_force_2(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_bottom_up(M));
  EXPECT_EQ(expected, maximal_square_in_matrix_top_down(M));
}



int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
