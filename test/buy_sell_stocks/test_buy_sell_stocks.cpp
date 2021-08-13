#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "buy_sell_stocks_solution1.cpp"
#include "buy_sell_stocks_solution2.cpp"

TEST(buy_sell_stocks, test_empty)
{
  std::vector<int> P     = {};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_single)
{
  std::vector<int> P     = {1};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_all_negative)
{
  std::vector<int> P     = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_all_decreasing)
{
  std::vector<int> P     = {9, 8, 7, 6, 5, 4, 3, 2, 1};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_all_decreasing_negative)
{
  std::vector<int> P     = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_all_increasing_negative)
{
  std::vector<int> P     = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_increasing)
{
  std::vector<int> P     = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  constexpr int expected = 8;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_random_1)
{
  std::vector<int> P     = {7, 1, 5, 3, 6, 4};
  constexpr int expected = 5;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_random_2)
{
  std::vector<int> P     = {96,  573, 861, 437, 986, 121, 155, 532, 608, 730,
                        56,  501, 850, 376, 753, 18,  83,  548, 372, 236,
                        129, 261, 991, 584, 774, 295, 939, 229, 634, 179,
                        543, 838, 360, 432, 493, 203, 434, 482, 279, 500,
                        410, 42,  357, 525, 601, 891, 972, 842, 565, 438};
  constexpr int expected = 973;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

TEST(buy_sell_stocks, test_random_3)
{
  std::vector<int> P = {
      6071,  6312,  5391,  11435, 7200,  1925,  3429,  1690, 8833,  11901,
      6162,  6887,  3848,  4741,  9967,  5529,  11176, 6660, 12199, 1425,
      4512,  11728, 3533,  3337,  2060,  9558,  10856, 5274, 11334, 3049,
      11603, 2381,  3815,  4733,  7539,  11795, 11593, 6311, 3947,  548,
      8588,  5189,  3212,  10055, 1285,  9820,  6483,  6055, 2122,  11926,
      12084, 7594,  11203, 924,   8671,  5187,  4506,  8966, 8666,  8331,
      3519,  11170, 4986,  1716,  6314,  10240, 8037,  1986, 7327,  4413,
      9545,  11559, 2876,  1240,  11499, 856,   5739,  6773, 943,   9257,
      430,   560,   12195, 8772,  6273,  6058,  12045, 778,  10245, 5112,
      1856,  275,   8763,  11393, 3323,  447,   6456,  4794, 2520,  538};
  constexpr int expected = 11765;

  EXPECT_EQ(expected, buy_sell_stocks_bruteforce(P));
  EXPECT_EQ(expected, buy_sell_stocks_DP(P));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
