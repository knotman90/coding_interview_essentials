#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "exponentiation_solution1.cpp"
#include "exponentiation_solution2.cpp"
#include "exponentiation_solution3.cpp"
#include "exponentiation_solution4.cpp"
#include "exponentiation_solution5.cpp"

using std::string;

TEST(exponentiation, test_n_k)
{
  for (int i = 0; i < 10; i++)
    for (int j = 0; j < 10; j++)
    {
      EXPECT_EQ((unsigned)std::pow(i, j), exponentiation_linear(i, j));
      EXPECT_EQ((unsigned)std::pow(i, j), exponentiation_linear_recursive(i, j));
      EXPECT_EQ((unsigned)std::pow(i, j), exponentiation_fast(i, j));
      EXPECT_EQ((unsigned)std::pow(i, j), exponentiation_fast_iterative(i, j));
      EXPECT_EQ((unsigned)std::pow(i, j),
                exponentiation_fast_iterative_simple(i, j));
    }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
