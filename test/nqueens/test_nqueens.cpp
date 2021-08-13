#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "nqueens_solution1.cpp"
#include "nqueens_solution2.cpp"
#include "nqueens_solution3.cpp"

#include "nqueens_solution4.cpp"

TEST(nqueens, testFrom1To8OnePerRow)
{
  EXPECT_EQ(1, nqueen_one_per_row(1).size());

  EXPECT_EQ(0, nqueen_one_per_row(2).size());

  EXPECT_EQ(0, nqueen_one_per_row(3).size());

  EXPECT_EQ(2, nqueen_one_per_row(4).size());

  EXPECT_EQ(10, nqueen_one_per_row(5).size());

  EXPECT_EQ(4, nqueen_one_per_row(6).size());

  EXPECT_EQ(40, nqueen_one_per_row(7).size());

  EXPECT_EQ(92, nqueen_one_per_row(8).size());
}

TEST(nqueens, testFrom1To6_bruteforce)
{
  EXPECT_EQ(1, nqueen_bruteforce(1).size());

  EXPECT_EQ(0, nqueen_bruteforce(2).size());

  EXPECT_EQ(0, nqueen_bruteforce(3).size());

  EXPECT_EQ(2, nqueen_bruteforce(4).size());

  EXPECT_EQ(10, nqueen_bruteforce(5).size());

  EXPECT_EQ(4, nqueen_bruteforce(6).size());
}

TEST(nqueens, testFrom1To6_bruteforce_revised)
{
  EXPECT_EQ(1, nqueen_bruteforce_revised(1).size());

  EXPECT_EQ(0, nqueen_bruteforce_revised(2).size());

  EXPECT_EQ(0, nqueen_bruteforce_revised(3).size());

  EXPECT_EQ(2, nqueen_bruteforce_revised(4).size());

  EXPECT_EQ(10, nqueen_bruteforce_revised(5).size());

  EXPECT_EQ(4, nqueen_bruteforce_revised(6).size());

  EXPECT_EQ(40, nqueen_bruteforce_revised(7).size());

  EXPECT_EQ(92, nqueen_bruteforce_revised(8).size());

  EXPECT_EQ(352, nqueen_bruteforce_revised(9).size());

  EXPECT_EQ(724, nqueen_bruteforce_revised(10).size());
}

TEST(nqueens, testFrom1To9OnePercolumnPerRow)
{
  EXPECT_EQ(1, nqueen_one_per_row_and_column(1).size());

  EXPECT_EQ(0, nqueen_one_per_row_and_column(2).size());

  EXPECT_EQ(0, nqueen_one_per_row_and_column(3).size());

  EXPECT_EQ(2, nqueen_one_per_row_and_column(4).size());

  EXPECT_EQ(10, nqueen_one_per_row_and_column(5).size());

  EXPECT_EQ(4, nqueen_one_per_row_and_column(6).size());

  EXPECT_EQ(40, nqueen_one_per_row_and_column(7).size());

  EXPECT_EQ(92, nqueen_one_per_row_and_column(8).size());

  EXPECT_EQ(352, nqueen_one_per_row_and_column(9).size());

  EXPECT_EQ(724, nqueen_one_per_row_and_column(10).size());
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
