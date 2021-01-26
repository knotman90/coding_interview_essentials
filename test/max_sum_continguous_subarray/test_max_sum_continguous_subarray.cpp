#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "max_sum_continguous_subarray_solution1.cpp"
#include "max_sum_continguous_subarray_solution2.cpp"
#include "max_sum_continguous_subarray_solution3.cpp"
#include "max_sum_continguous_subarray_solution4.cpp"

using std::string;

TEST(max_sum_continguous_subarray, test_single_positive)
{
  for (int i = 0; i < 100; i++)
  {
    std::vector<int> A = {i};
    EXPECT_EQ(i, max_sum_contiguous_subarray_bruteforce(A));
    EXPECT_EQ(i, max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
    EXPECT_EQ(i, max_sum_contiguous_subarray_kadane_space(A));
    EXPECT_EQ(i, max_sum_contiguous_subarray_kadane(A));
  }
}

TEST(max_sum_continguous_subarray, test_all_positive)
{
  constexpr size_t LENGHT = 100;
  std::vector<int> A(LENGHT);

  std::iota(begin(A), end(A), 1);
  constexpr int expected_result = (LENGHT * (LENGHT + 1)) / 2;
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_bruteforce(A));
  EXPECT_EQ(expected_result,
            max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane_space(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane(A));
}

TEST(max_sum_continguous_subarray, test_single_negative)
{
  for (int i = 0; i < 100; i++)
  {
    const std::vector<int> A = {-i};
    EXPECT_EQ(-i, max_sum_contiguous_subarray_bruteforce(A));
    EXPECT_EQ(-i, max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
    EXPECT_EQ(-i, max_sum_contiguous_subarray_kadane_space(A));
    EXPECT_EQ(-i, max_sum_contiguous_subarray_kadane(A));
  }
}

TEST(max_sum_continguous_subarray, test_all_negative)
{
  constexpr size_t LENGHT = 100;
  std::vector<int> A(LENGHT);

  std::iota(begin(A), end(A), -LENGHT);  //{-100,-99,...,-1}
  constexpr int expected_result = -1;    // smallest
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_bruteforce(A));
  EXPECT_EQ(expected_result,
            max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane_space(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane(A));
}

TEST(max_sum_continguous_subarray, test1)
{
  std::vector<int> A            = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  constexpr int expected_result = 6;  // smallest
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_bruteforce(A));
  EXPECT_EQ(expected_result,
            max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane_space(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane(A));
}

TEST(max_sum_continguous_subarray, test7)
{
  std::vector<int> A            = {-2, -5, 6, -2, -3, 1, 5, -6};
  constexpr int expected_result = 7;  // smallest
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_bruteforce(A));
  EXPECT_EQ(expected_result,
            max_sum_contiguous_subarray_bruteforce_prefix_sum(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane_space(A));
  EXPECT_EQ(expected_result, max_sum_contiguous_subarray_kadane(A));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
