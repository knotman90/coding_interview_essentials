#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "buy_sell_stocks_4_solution0.cpp"
#include "buy_sell_stocks_4_solution1.cpp"
#include "buy_sell_stocks_4_solution2.cpp"

static auto do_test(const std::vector<int> P, const int K, const int expected)
{
  std::vector<int> ans;
  {
    const auto val = buy_sell_stock4_DP_unoptimized(K, P);
    EXPECT_EQ(expected, val);
    ans.push_back(val);
  }

  {
    const auto val = buy_sell_stock4_DP_time_optimized(K, P);
    EXPECT_EQ(expected, val);
    ans.push_back(val);
  }

  {
    const auto val = buy_sell_stock4_DP_time_and_space_optimized(K, P);
    EXPECT_EQ(expected, val);
    ans.push_back(val);
  }

  ASSERT_TRUE(std::all_of(std::begin(ans),
                          std::end(ans),
                          [expected](const auto &x) { return x == expected; }));
}

TEST(buy_sell_stocks_4, test_1)
{
  std::vector<int> P     = {3, 2, 6, 5, 0, 3};
  constexpr int K        = 2;
  constexpr int expected = 7;

  do_test(P, K, expected);
}

TEST(buy_sell_stocks_4, test_2)
{
  std::vector<int> P     = {2, 4, 1};
  constexpr int K        = 2;
  constexpr int expected = 2;

  do_test(P, K, expected);
}

TEST(buy_sell_stocks_4, test_2_1)
{
  std::vector<int> P     = {2, 4, 1};
  constexpr int K        = 50;
  constexpr int expected = 2;

  do_test(P, K, expected);
}

TEST(buy_sell_stocks_4, test_3_1)
{
  std::vector<int> P     = {3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9};
  constexpr int K        = 3;
  constexpr int expected = 19;

  do_test(P, K, expected);
}

TEST(buy_sell_stocks_4, test_3)
{
  std::vector<int> P     = {3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9};
  constexpr int K        = 4;
  constexpr int expected = 19;

  do_test(P, K, expected);
}

TEST(buy_sell_stocks_4, test_3_large)
{
  std::vector<int> P = {
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3,
      8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8,
      2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5,
      9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3,
      3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6,
      5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3,
      2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3,
      8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8,
      2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5,
      9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3,
      3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6,
      5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3,
      8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3,
      3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3,
      2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5,
      9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3,
      8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3,
      3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3,
      2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5,
      9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0,
      3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5,
      0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3,
      5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 6, 5, 0, 3, 3, 8, 2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2,
      6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3,
      2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 3, 2, 6, 5, 0, 3, 3, 8, 2,
      3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8,
      2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3,
      8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 6, 5, 0, 3, 3, 8,
      2, 3, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9,
      3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5,
      9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5,
      5, 9, 3, 2, 6, 5, 0, 3, 3, 8, 2, 3, 5, 5, 9};
  constexpr int K        = 50;
  constexpr int expected = 450;

  do_test(P, K, expected);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
