#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "nesting_depths_solution1.cpp"
#include "nesting_depths_solution2.cpp"

TEST(nesting_depths, test_empty)
{
  std::vector<int> D = {};
  ASSERT_EQ("", nesting_depths(D));
}

TEST(nesting_depths, test_example1)
{
  std::vector<int> D = {0, 0, 0, 0};
  ASSERT_EQ("0000", nesting_depths(D));
}

TEST(nesting_depths, test_zero_one_1)
{
  std::vector<int> D = {0, 0, 0, 0,1,1,1,1,1};
  ASSERT_EQ("0000(11111)", nesting_depths(D));
}


TEST(nesting_depths, test_example2)
{
  std::vector<int> D = {1,0,1};
  ASSERT_EQ("(1)0(1)", nesting_depths(D));
}

TEST(nesting_depths, test_example3)
{
  std::vector<int> D = {1,1,1,0,0,0,0,0};
  ASSERT_EQ("(111)00000", nesting_depths(D));
}

TEST(nesting_depths, test_incremental)
{
  std::vector<int> D = {1,2,3,4,5,6,7,8,9};
  ASSERT_EQ("(1(2(3(4(5(6(7(8(9)))))))))", nesting_depths(D));
}

TEST(nesting_depths, test_single_1)
{
  std::vector<int> D = {1};
  ASSERT_EQ("(1)", nesting_depths(D));
}

TEST(nesting_depths, test_single_n)
{
  for (int i = 1; i < 9; i++)
  {
    std::vector<int> D = {i};
    
    string expected    = "";
    for (int j = 0; j < i; j++)
      expected += '(';
    expected += std::to_string(i);
    for (int j = 0; j < i; j++)
      expected += ')';

    ASSERT_EQ(expected, nesting_depths(D));
  }
}





int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
