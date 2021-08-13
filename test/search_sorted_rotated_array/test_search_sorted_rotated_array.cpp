#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "search_sorted_rotated_array_solution1.cpp"
#include "search_sorted_rotated_array_solution2.cpp"

TEST(search_sorted_rotated_array, test_empty)
{
  const vector<int> A = {};
  const int t         = 5;
  const int expected  = -1;
  EXPECT_EQ(expected, search_sorted_rotated_array_bruteforce(A, t));
  EXPECT_EQ(expected, search_sorted_rotated_array_log(A, t));
}

TEST(search_sorted_rotated_array, test_no_rotation_present)
{
  const vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int t         = 5;
  const int expected  = 5;
  EXPECT_EQ(expected, search_sorted_rotated_array_bruteforce(A, t));
  EXPECT_EQ(expected, search_sorted_rotated_array_log(A, t));
}

TEST(search_sorted_rotated_array, test_no_rotation_absent)
{
  const vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  const int t         = 50;
  const int expected  = -1;
  EXPECT_EQ(expected, search_sorted_rotated_array_bruteforce(A, t));
  EXPECT_EQ(expected, search_sorted_rotated_array_log(A, t));
}

TEST(search_sorted_rotated_array, test_all_rotations_present)
{
  constexpr int size = 100;
  vector<int> input(size);
  std::iota(begin(input), end(input), 0);
  for (int i = 0; i < size; i++)
  {
    vector<int> A(input);
    std::rotate(begin(A), begin(A) + i, end(A));
    for (int t = 0; t < size; t++)
    {
      const int expected = ((t - i) + size) % size;
      EXPECT_EQ(expected, search_sorted_rotated_array_bruteforce(A, t));
      EXPECT_EQ(expected, search_sorted_rotated_array_log(A, t));
    }
  }
}

TEST(search_sorted_rotated_array, test_all_rotations_absent)
{
  constexpr int size = 100;
  vector<int> input(size);
  std::iota(begin(input), end(input), 0);
  for (int i = 0; i < size; i++)
  {
    vector<int> A(input);
    std::rotate(begin(A), begin(A) + i, end(A));
    for (int t = 0; t < size; t++)
    {
      const int expected = -1;
      EXPECT_EQ(expected, search_sorted_rotated_array_bruteforce(A, t + size));
      EXPECT_EQ(expected, search_sorted_rotated_array_log(A, t + size));
    }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
