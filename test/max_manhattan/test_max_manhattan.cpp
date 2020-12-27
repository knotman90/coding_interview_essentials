#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "max_manhattan_solution1.cpp"
#include "max_manhattan_solution2.cpp"
#include "max_manhattan_solution3.cpp"

using Matrix = std::vector<std::vector<int>>;

TEST(max_manhattan, exmaple1)
{
  Matrix input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  constexpr int K = 1;

  Matrix expected = {
      {4, 5, 6},
      {7, 8, 9},
      {8, 9, 9},
  };

  {
    const auto ans = max_manhattan_matrix_k_bruteforce(input, K);
    ASSERT_EQ(ans, expected);
  }
  {
    const auto ans = max_manhattan_matrix_k_DP_topdown(input, K);
    ASSERT_EQ(ans, expected);
  }

  {
    const auto ans = max_manhattan_matrix_k_DP_bottomup(input, K);
    ASSERT_EQ(ans, expected);
  }
}

TEST(max_manhattan, exmaple2)
{
  Matrix input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  constexpr int K = 2;

  Matrix expected = {
      {7, 8, 9},
      {8, 9, 9},
      {9, 9, 9},
  };

  {
    const auto ans = max_manhattan_matrix_k_bruteforce(input, K);
    ASSERT_EQ(ans, expected);
  }

  {
    const auto ans = max_manhattan_matrix_k_DP_topdown(input, K);
    ASSERT_EQ(ans, expected);
  }
  {
    const auto ans = max_manhattan_matrix_k_DP_bottomup(input, K);
    ASSERT_EQ(ans, expected);
  }
}

TEST(max_manhattan, exmaple3)
{
  Matrix input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  constexpr int K = 3;

  Matrix expected = {
      {8, 9, 9},
      {9, 9, 9},
      {9, 9, 9},
  };

  {
    const auto ans = max_manhattan_matrix_k_bruteforce(input, K);
    ASSERT_EQ(ans, expected);
  }
  {
    const auto ans = max_manhattan_matrix_k_DP_topdown(input, K);
    ASSERT_EQ(ans, expected);
  }

  {
    const auto ans = max_manhattan_matrix_k_DP_bottomup(input, K);
    ASSERT_EQ(ans, expected);
  }
}

TEST(max_manhattan, exmaple4)
{
  Matrix input = {
      {1, 2, 3},
      {4, 5, 6},
      {7, 8, 9},
  };
  constexpr int K = 4;

  Matrix expected = {
      {9, 9, 9},
      {9, 9, 9},
      {9, 9, 9},
  };

  {
    const auto ans = max_manhattan_matrix_k_bruteforce(input, K);
    ASSERT_EQ(ans, expected);
  }
  {
    const auto ans = max_manhattan_matrix_k_DP_topdown(input, K);
    ASSERT_EQ(ans, expected);
  }

  {
    const auto ans = max_manhattan_matrix_k_DP_bottomup(input, K);
    ASSERT_EQ(ans, expected);
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
