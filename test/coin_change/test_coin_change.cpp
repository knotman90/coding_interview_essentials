#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "coin_change_solution1.cpp"
#include "coin_change_solution2.cpp"

TEST(coin_change, test1)
{
  const long long amount       = 5;
  const std::vector<int> coins = {1, 2, 5, 7};
  const long long expected     = 4;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

TEST(coin_change, test2)
{
  const long long amount       = 4;
  const std::vector<int> coins = {1, 2, 3};
  const long long expected     = 4;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}
TEST(coin_change, test3)
{
  const long long amount       = 10;
  const std::vector<int> coins = {2,5,3,6};
  const long long expected     = 5;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

TEST(coin_change, test4)
{
  const long long amount       = 50;
  const std::vector<int> coins = {11};
  const long long expected     = 0;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

TEST(coin_change, test5)
{
  const long long amount       = 50;
  const std::vector<int> coins = {1,11};
  const long long expected     = 5;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}


TEST(coin_change, test6)
{
  const long long amount       = 8;
  const std::vector<int> coins = {1,3,5,7};
  const long long expected     = 6;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
