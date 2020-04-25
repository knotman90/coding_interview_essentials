#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "can_jump_solution1.cpp"
#include "can_jump_solution2.cpp"

TEST(can_jump, impossible_1)
{
  const std::vector<int> N = {3, 2, 1, 0, 4};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_linear(N));
}

TEST(can_jump, single_1)
{
  const std::vector<int> N = {3};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_linear(N));
}

TEST(can_jump, random012_one)
{
  const std::vector<int> N = {2, 1, 0, 2, 1, 0, 0, 1, 2, 2, 1,
                              0, 0, 2, 1, 0, 1, 2, 0, 1, 2};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_linear(N));
}
TEST(can_jump, random012_two)
{
  const std::vector<int> N = {2, 1, 0, 0, 2, 1, 2, 0, 1, 2, 0,
                              1, 0, 1, 2, 0, 2, 1, 1, 0, 2};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_linear(N));
}

TEST(can_jump, random12_one)
{
  const std::vector<int> N = {1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_linear(N));
}

TEST(can_jump, random05_one)
{
  const std::vector<int> N = {5, 2, 1, 3, 4, 5, 1, 3, 4, 0, 2, 1, 5, 2, 3,
                              4, 0, 2, 3, 5, 1, 4, 0, 0, 2, 3, 4, 5, 1, 2,
                              3, 4, 5, 0, 1, 5, 2, 3, 1, 4, 0, 0, 3, 1, 0,
                              3, 4, 1, 5, 3, 0, 4, 2, 0, 4, 1, 5, 2, 3};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_linear(N));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
