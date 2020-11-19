#include <bits/stdc++.h>
#include <cassert>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "median_sorted_arrays_solution1.cpp"
#include "median_sorted_arrays_solution2.cpp"
#include "median_sorted_arrays_solution3.cpp"

TEST(median_sorted_arrays, test_when_A_is_empty)
{
  std::vector<int> A{};
  std::vector<int> B{1, 2, 3};
  constexpr double expected = 2;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_when_B_is_empty)
{
  std::vector<int> A{1, 2, 3};
  std::vector<int> B{};
  constexpr double expected = 2;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_when_A_all_smaller_than_B)
{
  std::vector<int> A{1, 2, 3};
  std::vector<int> B{5, 6, 7, 8};
  constexpr double expected = 5;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_when_A_all_smaller_than_B_even)
{
  std::vector<int> A{1, 2, 3};
  std::vector<int> B{4, 5, 6};
  constexpr double expected = 4.5;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_when_B_all_smaller_than_A)
{
  std::vector<int> A{5, 6, 7, 8};
  std::vector<int> B{1, 2, 3};
  constexpr double expected = 5;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_when_B_all_smaller_than_A_even)
{
  std::vector<int> A{4, 5, 6};
  std::vector<int> B{1, 2, 3};
  constexpr double expected = 4.5;
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_odd1)
{
  std::vector<int> A{1, 3, 5};
  std::vector<int> B{2, 4};
  constexpr double expected = 3;
  EXPECT_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_big_1_even)
{
  std::vector<int> A{
      1469,  8911,  12102, 4582,  1567,  3106, 4774,  12310, 11148, 3804,
      11445, 12155, 11700, 12301, 4417,  2674, 3171,  6796,  7349,  10403,
      8693,  11678, 3298,  4893,  1115,  1431, 10829, 10432, 11939, 442,
      1718,  9682,  9522,  6721,  7555,  3207, 11380, 892,   1062,  11797,
      4853,  9211,  7430,  8554,  11988, 5697, 326,   8970,  8067,  8028,
      7919,  4722,  11350, 8538,  8045,  9686, 9719,  5997,  4751,  9283,
      10760, 7848,  2700,  1842,  4479,  11588};
  sort(begin(A), end(A));

  std::vector<int> B{9384,  2231,  7644,  4567,  9604,  10619, 7544,
                     11290, 1213,  10718, 10275, 11627, 5876,  4623,
                     4124,  12049, 2918,  10255, 1914,  5741,  10260,
                     11136, 10505, 8076,  8732,  9731,  7836,  3308,
                     6989,  7166,  10248, 5835,  5601,  7614};
  sort(begin(B), end(B));

  constexpr double expected = 7883.5;
  EXPECT_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_big_2_even)
{
  std::vector<int> A{97, 68, 96, 34, 86, 70, 60, 99, 22, 5,  61,
                     12, 40, 41, 14, 67, 57, 17, 13, 16, 8,  56,
                     25, 62, 78, 90, 21, 4,  27, 32, 28, 53, 23};
  sort(begin(A), end(A));

  std::vector<int> B{39, 94, 59, 92, 52, 63, 54,  47, 3,  48, 64, 75, 38, 46,
                     11, 37, 73, 79, 7,  10, 87,  1,  77, 42, 95, 44, 31, 58,
                     93, 85, 91, 82, 84, 45, 6,   9,  71, 88, 55, 20, 30, 89,
                     29, 43, 98, 51, 50, 66, 100, 19, 74, 24, 15, 76, 72, 35,
                     2,  80, 18, 33, 83, 69, 26,  81, 49, 65, 36};
  sort(begin(B), end(B));

  constexpr double expected = 51.5;
  EXPECT_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}

TEST(median_sorted_arrays, test_big_2_odd)
{
  std::vector<int> A{97, 68, 96, 34, 86, 70, 60, 99, 22, 5,  61,
                     12, 40, 41, 14, 67, 57, 17, 13, 16, 8,  56,
                     25, 62, 78, 90, 21, 4,  27, 32, 28, 53, 23};
  sort(begin(A), end(A));

  std::vector<int> B{39, 94, 59, 92, 52, 63, 54,  47, 3,  48, 64, 75, 38, 46,
                     11, 37, 73, 79, 7,  10, 87,  1,  77, 42, 95, 44, 31, 58,
                     93, 85, 91, 82, 84, 45, 6,   9,  71, 88, 55, 20, 30, 89,
                     29, 43, 98, 51, 50, 66, 100, 19, 74, 24, 15, 76, 72, 35,
                     2,  80, 18, 33, 83, 69, 26,  81, 49, 65, 36,101};
  sort(begin(B), end(B));

  constexpr double expected = 51;
  EXPECT_EQ(expected, mediam_sorted_arrays_naive(A, B));
  EXPECT_DOUBLE_EQ(expected, mediam_sorted_arrays_merge(A, B));
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
