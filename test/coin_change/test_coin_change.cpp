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
#include "coin_change_solution3.cpp"
#include "coin_change_solution4.cpp"
#include "coin_change_solution5.cpp"


TEST(coinChangeMinCoins, test_only_one)
{
  const std::vector<int> coins = {1};
  for(int i = 0 ; i < 100 ; i++){
    const long long amount       = i;
    const long long expected     = i;
    ASSERT_EQ(expected, change_ways_bruteforce(coins, amount));
    ASSERT_EQ(expected, change_ways_DP_topdown(coins, amount));
    ASSERT_EQ(expected, change_min_ways_bottom_up(amount, coins));
  }
}


TEST(coinChangeMinCoins, test0)
{
  const long long amount       = 0;
  const std::vector<int> coins = {1, 2, 5, 7};
  const long long expected     = 0;
  ASSERT_EQ(expected, change_ways_bruteforce(coins, amount));
  ASSERT_EQ(expected, change_ways_DP_topdown(coins, amount));
  ASSERT_EQ(expected, change_min_ways_bottom_up(amount, coins));
}

TEST(coinChangeMinCoins, test1)
{
  const long long amount       = 5;
  const std::vector<int> coins = {1, 2, 5, 7};
  const long long expected     = 1;
  ASSERT_EQ(expected, change_ways_bruteforce(coins, amount));
  ASSERT_EQ(expected, change_ways_DP_topdown(coins, amount));
  ASSERT_EQ(expected, change_min_ways_bottom_up(amount, coins));
}

TEST(coinChangeMinCoins, test2)
{
  const long long amount       = 8;
  const std::vector<int> coins = {1, 2, 5, 7};
  const long long expected     = 2;
  ASSERT_EQ(expected, change_ways_bruteforce(coins, amount));
  ASSERT_EQ(expected, change_ways_DP_topdown(coins, amount));
  ASSERT_EQ(expected, change_min_ways_bottom_up(amount, coins));
}

TEST(coinChangeMinCoins, testexample3)
{
  const long long amount       = 4;
  const std::vector<int> coins = {1, 2, 3};
  const long long expected     = 2;
  ASSERT_EQ(expected, change_ways_bruteforce(coins, amount));
  ASSERT_EQ(expected, change_ways_DP_topdown(coins, amount));
  ASSERT_EQ(expected, change_min_ways_bottom_up(amount, coins));
}

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
  const std::vector<int> coins = {2, 5, 3, 6};
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
  const std::vector<int> coins = {1, 11};
  const long long expected     = 5;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

TEST(coin_change, test6)
{
  const long long amount       = 8;
  const std::vector<int> coins = {1, 3, 5, 7};
  const long long expected     = 6;

  ASSERT_EQ(expected, count_change_ways_top_down(amount, coins));
  ASSERT_EQ(expected, change_ways_bottom_up(amount, coins));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
