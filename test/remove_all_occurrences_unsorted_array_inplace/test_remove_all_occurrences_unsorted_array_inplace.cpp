#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "remove_all_occurrences_unsorted_array_inplace_solution1.cpp"
#include "remove_all_occurrences_unsorted_array_inplace_solution2.cpp"
#include "remove_all_occurrences_unsorted_array_inplace_solution3.cpp"
#include "remove_all_occurrences_unsorted_array_inplace_solution4.cpp"

TEST(remove_all_occurrences_unsorted_array_inplace, example1)
{
  std::vector<int> original_input = {4, 1, 1, 2, 1, 3};
  const int expected              = 4;
  auto fn                         = [](const auto& x) { return x % 2 == 0; };

  {
    std::vector<int> input = {4, 1, 1, 2, 1, 3};
    EXPECT_EQ(remove_elements_unsorted_array_remove_STL(input, fn), expected);
    EXPECT_EQ(input[0], 1);
    EXPECT_EQ(input[1], 1);
    EXPECT_EQ(input[2], 1);
    EXPECT_EQ(input[3], 3);
  }

  {
    std::vector<int> input = {4, 1, 1, 2, 1, 3};
    EXPECT_EQ(remove_elements_unsorted_array_linear_space(input, fn), expected);
    EXPECT_EQ(input[0], 1);
    EXPECT_EQ(input[1], 1);
    EXPECT_EQ(input[2], 1);
    EXPECT_EQ(input[3], 3);
  }

  {
    std::vector<int> input = {4, 1, 1, 2, 1, 3};
    EXPECT_EQ(remove_elements_unsorted_array(input, fn), expected);
    EXPECT_EQ(input[0], 1);
    EXPECT_EQ(input[1], 1);
    EXPECT_EQ(input[2], 1);
    EXPECT_EQ(input[3], 3);
  }
}

TEST(remove_all_occurrences_unsorted_array_inplace, example2)
{
  std::vector<int> input = {4, 1, 1, 2, 1, 3};
  auto fn                = [](const auto x) { return x % 2 != 0; };
  EXPECT_EQ(remove_elements_unsorted_array(input, fn), 2);
  EXPECT_EQ(input[0], 4);
  EXPECT_EQ(input[1], 2);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
