#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "square_root_binary_search.cpp"
#include "square_root_brute_force.cpp"

using std::string;

TEST(square_root,
     given_numbers_from_0_to_10000_result_should_be_equal_to_std_floor_sqrt)
{
  for (int i = 0; i < 10000; i++)
  {
    const int expected_value = std::floor(std::sqrt(i));

    EXPECT_EQ(expected_value, square_root_binary_search(i));
    EXPECT_EQ(expected_value, square_root_brute_force(i));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}