#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "number_islands_solution1.cpp"
#include "number_islands_solution2.cpp"

TEST(number_islands, test_no_island)
{
  const vector<vector<bool>> map = {
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},
      {0, 0, 0, 0},

  };

  const int expected = 0;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));

  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_all_land)
{
  const vector<vector<bool>> map = {
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 1, 1, 1},
      {1, 1, 1, 1},
  };

  const int expected = 1;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_example1)
{
  const vector<vector<bool>> map = {
      {1, 1, 1, 1, 0},
      {1, 1, 0, 1, 0},
      {1, 1, 0, 0, 0},
      {0, 0, 0, 0, 0},
  };

  const int expected = 1;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_example2)
{
  const vector<vector<bool>> map = {
      {1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 1, 0, 0}, {0, 0, 0, 1, 1}};

  const int expected = 3;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_interleaved_land)
{
  const vector<vector<bool>> map = {
      {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}, {0, 1, 0, 1, 0}, {1, 0, 1, 0, 1}};

  const int expected = 13;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_diagonal_1)
{
  const vector<vector<bool>> map = {
      {1, 0, 0, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 0, 0, 1},
  };

  const int expected = 7;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_diagonal_2)
{
  const vector<vector<bool>> map = {
      {0, 0, 0, 0, 0, 0, 1},
      {0, 0, 0, 0, 0, 1, 0},
      {0, 0, 0, 0, 1, 0, 0},
      {0, 0, 0, 1, 0, 0, 0},
      {0, 0, 1, 0, 0, 0, 0},
      {0, 1, 0, 0, 0, 0, 0},
      {1, 0, 0, 0, 0, 0, 0},
  };

  const int expected = 7;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));
  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

TEST(number_islands, test_first_last_row)
{
  const vector<vector<bool>> map = {
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
      {1, 0, 0, 0, 0, 0, 1},
  };

  const int expected = 2;
  EXPECT_EQ(expected, count_island_iterative_DFS(map));

  {
    vector<vector<bool>> input_map(map);
    EXPECT_EQ(expected, count_island_iterative_DFS_improved(input_map));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
