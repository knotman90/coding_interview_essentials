#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "kth_smallest_in_sorted_matrix_solution1.cpp"
#include "kth_smallest_in_sorted_matrix_solution2.cpp"
#include "kth_smallest_in_sorted_matrix_solution3.cpp"

using Matrix = std::vector<std::vector<int>>;

TEST(kth_smallest_in_sorted_matrix, example1)
{
  Matrix input = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};

  {
    const size_t k     = 8;
    const int expected = 13;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }

  {
    const size_t k     = 1;
    const int expected = 1;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 2;
    const int expected = 5;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 3;
    const int expected = 9;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 4;
    const int expected = 10;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 6;
    const int expected = 12;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 7;
    const int expected = 13;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
  {
    const size_t k     = 9;
    const int expected = 15;
    EXPECT_EQ(
        expected,
        kth_smallest_in_sorted_matrix_brute_force_constant_space(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_naive(input, k));
    EXPECT_EQ(expected, kth_smallest_in_sorted_matrix_nlogn(input, k));
  }
}

TEST(kth_smallest_in_sorted_matrix, simple)
{
  Matrix input = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  for (int i = 1; i <= 9; i++)
  {
    EXPECT_EQ(
        i, kth_smallest_in_sorted_matrix_brute_force_constant_space(input, i));
    EXPECT_EQ(i, kth_smallest_in_sorted_matrix_naive(input, i));
    EXPECT_EQ(i, kth_smallest_in_sorted_matrix_nlogn(input, i));
  }
}

TEST(kth_smallest_in_sorted_matrix, simpleRotated)
{
  Matrix input = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
  for (int i = 1; i <= 9; i++)
  {
    EXPECT_EQ(
        i, kth_smallest_in_sorted_matrix_brute_force_constant_space(input, i));
    EXPECT_EQ(i, kth_smallest_in_sorted_matrix_naive(input, i));
    EXPECT_EQ(i, kth_smallest_in_sorted_matrix_nlogn(input, i));
  }
}

TEST(kth_smallest_in_sorted_matrix, allEqual)
{
  Matrix input = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  for (int i = 1; i <= 9; i++)
  {
    EXPECT_EQ(
        1, kth_smallest_in_sorted_matrix_brute_force_constant_space(input, i));
    EXPECT_EQ(1, kth_smallest_in_sorted_matrix_naive(input, i));
    EXPECT_EQ(1, kth_smallest_in_sorted_matrix_nlogn(input, i));
  }
}


TEST(kth_smallest_in_sorted_matrix, oneColumn)
{
  Matrix input = {{0}, {1 }, {2}, {3 }, {4 }, {5 }, {6 }};
  for (int i = 1; i <= 6; i++)
  {
    EXPECT_EQ(
        i-1, kth_smallest_in_sorted_matrix_brute_force_constant_space(input, i));
    EXPECT_EQ(i-1, kth_smallest_in_sorted_matrix_naive(input, i));
    EXPECT_EQ(i-1, kth_smallest_in_sorted_matrix_nlogn(input, i));
  }
}


TEST(kth_smallest_in_sorted_matrix, oneRow)
{
  Matrix input = {{0,1,2,3,4,5,6}};
  for (int i = 1; i <= 6; i++)
  {
    EXPECT_EQ(
        i-1, kth_smallest_in_sorted_matrix_brute_force_constant_space(input, i));
    EXPECT_EQ(i-1, kth_smallest_in_sorted_matrix_naive(input, i));
    EXPECT_EQ(i-1, kth_smallest_in_sorted_matrix_nlogn(input, i));
  }
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
