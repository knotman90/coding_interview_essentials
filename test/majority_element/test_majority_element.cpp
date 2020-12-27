#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "majority_element_solution1.cpp"
#include "majority_element_solution2.cpp"
#include "majority_element_solution3.cpp"
#include "majority_element_solution4.cpp"
#include "majority_element_solution5.cpp"

TEST(majority_element, test_empty_array)
{
  std::vector<int> V     = {};
  constexpr int expected = -1;
  EXPECT_EQ(expected, find_majority_element_brute_force(V));
  EXPECT_EQ(expected, find_majority_element_linear(V));
  EXPECT_EQ(expected, find_majority_element_hash_map(V));
  EXPECT_EQ(expected, find_majority_element_sorting(V));
  EXPECT_EQ(expected, find_majority_element_median(V));
}

TEST(majority_element, test_single_element)
{
  std::vector<int> V     = {1};
  constexpr int expected = 1;
  EXPECT_EQ(expected, find_majority_element_brute_force(V));
  EXPECT_EQ(expected, find_majority_element_linear(V));
  EXPECT_EQ(expected, find_majority_element_hash_map(V));
  EXPECT_EQ(expected, find_majority_element_sorting(V));
  EXPECT_EQ(expected, find_majority_element_median(V));
}

TEST(majority_element, test_all_different)
{
  std::vector<int> V     = {1, 2, 3, 4, 5, 6, 7, 8};
  constexpr int expected = -1;
  EXPECT_EQ(expected, find_majority_element_brute_force(V));
  EXPECT_EQ(expected, find_majority_element_linear(V));
  EXPECT_EQ(expected, find_majority_element_hash_map(V));
  EXPECT_EQ(expected, find_majority_element_sorting(V));
  EXPECT_EQ(expected, find_majority_element_median(V));
}

TEST(majority_element, test_equal_times)
{
  std::vector<int> V     = {1, 1, 2, 2};
  constexpr int expected = -1;
  EXPECT_EQ(expected, find_majority_element_brute_force(V));
  EXPECT_EQ(expected, find_majority_element_linear(V));
  EXPECT_EQ(expected, find_majority_element_hash_map(V));
  EXPECT_EQ(expected, find_majority_element_sorting(V));
  EXPECT_EQ(expected, find_majority_element_median(V));
}

TEST(majority_element, test_equal_times_plus_one)
{
  std::vector<int> V     = {2, 1, 1, 2, 2};
  constexpr int expected = 2;
  EXPECT_EQ(expected, find_majority_element_brute_force(V));
  EXPECT_EQ(expected, find_majority_element_linear(V));
  EXPECT_EQ(expected, find_majority_element_hash_map(V));
  EXPECT_EQ(expected, find_majority_element_sorting(V));
  EXPECT_EQ(expected, find_majority_element_median(V));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
