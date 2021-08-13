#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "trapping_water_solution1.cpp"
#include "trapping_water_solution2.cpp"
#include "trapping_water_solution3.cpp"
#include "trapping_water_solution4.cpp"

TEST(trapping_water, test_zero_alternate_zero_starting_ending)
{
  const vector<int> A = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_brute_force(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
}

TEST(trapping_water, test_one_zero_alternate_zero_starting_ending)
{
  const vector<int> A = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_brute_force(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
}

TEST(trapping_water, test_one_zero_alternate_zero_starting)
{
  const vector<int> A = {0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
}

TEST(trapping_water, test_one_zero_alternate_zero_ending)
{
  const vector<int> A = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
}

TEST(trapping_water, test_one_zero_alternate)
{
  const vector<int> A = {1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_5_4_alternate_zero_starting_ending)
{
  const vector<int> A = {4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4, 5, 4};
  const int expected  = 5;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_stairs_zero_to_10)
{
  const vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const int expected  = 0;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_stairs_3_to_0_to_3)
{
  const vector<int> A = {3, 2, 1, 0, 1, 2, 3};
  const int expected  = 9;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_double_stairs_3_to_0_to_3)
{
  const vector<int> A = {3, 2, 1, 0, 1, 2, 3, 3, 2, 1, 0, 1, 2, 3};
  const int expected  = 9 + 9;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_double_100_numbers_sequence)
{
  const vector<int> A = {
      20, 15, 17, 6,  2,  10, 14, 15, 1,  18, 6,  4,  6,  15, 8,  8,  10,
      14, 9,  14, 4,  5,  18, 7,  3,  9,  18, 8,  18, 10, 2,  6,  9,  10,
      4,  2,  12, 19, 15, 9,  8,  4,  14, 11, 5,  17, 6,  10, 13, 20, 10,
      19, 6,  8,  15, 9,  12, 7,  20, 8,  4,  7,  9,  13, 16, 2,  10, 14,
      8,  9,  16, 17, 1,  2,  6,  16, 9,  19, 16, 11, 13, 19, 5,  18, 2,
      2,  9,  19, 19, 14, 16, 5,  7,  7,  7,  12, 16, 10, 20, 8};
  const int expected = 933;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_double_100_numbers_upto_1000_sequence)
{
  const vector<int> A = {
      744, 63,  295, 324, 4,   256, 387, 505, 699, 699, 693, 832, 678, 283, 749,
      426, 569, 605, 356, 908, 912, 385, 451, 373, 28,  221, 691, 525, 944, 722,
      963, 800, 881, 953, 633, 746, 363, 158, 170, 869, 225, 43,  14,  598, 85,
      387, 816, 792, 360, 397, 112, 795, 885, 732, 480, 754, 42,  720, 305, 950,
      691, 762, 475, 41,  711, 308, 499, 107, 874, 472, 733, 86,  359, 458, 137,
      190, 233, 981, 301, 559, 392, 204, 138, 399, 400, 131, 704, 996, 418, 264,
      882, 862, 211, 132, 476, 160, 8,   397, 976, 148};
  const int expected = 43253;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_one_number)
{
  const vector<int> A = {744};
  const int expected  = 0;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_two_numbers)
{
  const vector<int> A = {744, 1};
  const int expected  = 0;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_three_numbers_1)
{
  const vector<int> A = {744, 0, 1598};
  const int expected  = 744;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test1)
{
  const vector<int> A = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  const int expected  = 6;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

TEST(trapping_water, test_stairs_10_to_0)
{
  const vector<int> A = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  const int expected  = 0;
  EXPECT_EQ(expected, trapping_water_stack(A));
  EXPECT_EQ(expected, trapping_water_DP(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
  EXPECT_EQ(expected, trapping_water_two_pointers(A));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
