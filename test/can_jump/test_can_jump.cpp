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
#include "can_jump_solution1_1.cpp"
#include "can_jump_solution2.cpp"
#include "can_jump2_solution1.cpp"
#include "can_jump3_solution1.cpp"
#include "can_jump4_solution1.cpp"

TEST(can_jump, impossible_1)
{
  const std::vector<int> N = {3, 2, 1, 0, 4};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_DFS_forward_only(N));
  ASSERT_FALSE(can_jump_linear(N));
}

TEST(can_jump, single_1)
{
  const std::vector<int> N = {3};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_DFS_forward_only(N));
  ASSERT_TRUE(can_jump_linear(N));
}

TEST(can_jump, random012_one)
{
  const std::vector<int> N = {2, 1, 0, 2, 1, 0, 0, 1, 2, 2, 1,
                              0, 0, 2, 1, 0, 1, 2, 0, 1, 2};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_DFS_forward_only(N));
  ASSERT_FALSE(can_jump_linear(N));
}
TEST(can_jump, random012_two)
{
  const std::vector<int> N = {2, 1, 0, 0, 2, 1, 2, 0, 1, 2, 0,
                              1, 0, 1, 2, 0, 2, 1, 1, 0, 2};

  ASSERT_FALSE(can_jump_DFS(N));
  ASSERT_FALSE(can_jump_DFS_forward_only(N));
  ASSERT_FALSE(can_jump_linear(N));
}

TEST(can_jump, random12_one)
{
  const std::vector<int> N = {1, 2, 2, 1, 2, 1, 1, 2, 1, 2, 2, 1, 1, 2};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_DFS_forward_only(N));
  ASSERT_TRUE(can_jump_linear(N));
}

TEST(can_jump, random05_one)
{
  const std::vector<int> N = {5, 2, 1, 3, 4, 5, 1, 3, 4, 0, 2, 1, 5, 2, 3,
                              4, 0, 2, 3, 5, 1, 4, 0, 0, 2, 3, 4, 5, 1, 2,
                              3, 4, 5, 0, 1, 5, 2, 3, 1, 4, 0, 0, 3, 1, 0,
                              3, 4, 1, 5, 3, 0, 4, 2, 0, 4, 1, 5, 2, 3};

  ASSERT_TRUE(can_jump_DFS(N));
  ASSERT_TRUE(can_jump_DFS_forward_only(N));
  ASSERT_TRUE(can_jump_linear(N));
}

TEST(can_jump, random06_impossible)
{
  const std::vector<int> N = {
      5, 2, 1, 3, 4, 5, 1, 3, 4, 0, 2, 1, 5, 2, 3, 4, 0, 2, 3, 5, 1, 4, 0,
      0, 2, 3, 4, 5, 1, 2, 3, 4, 5, 0, 1, 5, 2, 3, 1, 4, 0, 0, 3, 1, 0, 3,
      4, 1, 5, 3, 0, 4, 2, 0, 4, 1, 5, 2, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

  ASSERT_FALSE(can_jump_DFS(N));
  // ASSERT_FALSE(can_jump_DFS_forward_only(N)); //takes too long to complete
  ASSERT_FALSE(can_jump_linear(N));
}
/////////////////////////////////////////
TEST(can_jump2, example1)
{
  const std::vector<int> N = {2,3,0,1,4};

  ASSERT_EQ(2,can_jump2_levels(N));
}

TEST(can_jump2, chain)
{
  const std::vector<int> N = {1,1,1,1,1,1,1,1,1,1};

  ASSERT_EQ(9,can_jump2_levels(N));
}

/////////////////////////////////////////
TEST(can_jump4, example1)
{
  const std::vector<int> N = {100,-23,-23,404,100,23,23,23,3,404};

  ASSERT_EQ(3,can_jump4(N));
}

TEST(can_jump4, example2)
{
  const std::vector<int> N = {7};

  ASSERT_EQ(0,can_jump4(N));
}

TEST(can_jump4, example3)
{
  const std::vector<int> N = {11,22,7,7,7,7,7,7,7,22,13};

  ASSERT_EQ(3,can_jump4(N));
}

TEST(can_jump4, example4)
{
  const std::vector<int> N = {6,1,9};

  ASSERT_EQ(2,can_jump4(N));
}

TEST(can_jump4, example5)
{
  const std::vector<int> N = {7,6,9,6,9,6,9,7};

  ASSERT_EQ(1,can_jump4(N));
}

/////////////////////////////////////////


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
