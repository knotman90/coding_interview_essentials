#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;

#include "buy_sell_stocks_2_solution1.cpp"
#include "buy_sell_stocks_2_solution2.cpp"


TEST(buy_sell_stocks, test_1)
{

  std::vector<int> P     = {7,1,5,3,6,4};
  constexpr int expected = 7;

  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_exp(P));
  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_lin(P));
}

TEST(buy_sell_stocks, test_all_increasing)
{

  std::vector<int> P     = {1,2,3,4,5};
  constexpr int expected = 4;

  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_exp(P));
  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_lin(P));
}


TEST(buy_sell_stocks, test_all_negative)
{

  std::vector<int> P     = {-1, -2, -3, -4, -5, -6, -7, -8, -9};
  constexpr int expected = 0;

  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_exp(P));
  EXPECT_EQ(expected, buy_sell_stocks_multiple_transactions_lin(P));
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

