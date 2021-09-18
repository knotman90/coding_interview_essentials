#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "brute_force.cpp"
#include "hashset.cpp"
#include "two_numbers_sum_sorting.cpp"
#include "two_numbers_sum_two_pointers.cpp"

#include "test_utils.h"

TEST(two_numbers_problem, test1)
{
  for (const std::tuple<std::vector<int>, int, bool> p : {
           std::make_tuple(std::vector<int>({1}), 10, false),
           std::make_tuple(std::vector<int>({1}), 1, false),
           std::make_tuple(std::vector<int>({1, 0}), 1, true),
           std::make_tuple(std::vector<int>({1, 2}), 1, false),
           std::make_tuple(std::vector<int>({-1, 2}), 1, true),
           std::make_tuple(std::vector<int>({1, 3, 7}), 8, true),
           std::make_tuple(std::vector<int>({1, 3, 7}), 6, false),
           std::make_tuple(
               std::vector<int>({9, 4, 17, 42, 36, -3, 15}), 14, true),
           std::make_tuple(
               std::vector<int>({9, 4, 17, 42, 36, -3, 15}), 17, false),
       })
  {
    const auto& T        = std::get<1>(p);
    const auto& expected = std::get<2>(p);
    {
      const auto input = std::get<0>(p);
      ASSERT_EQ(expected, two_numers_sum_bruteforce(input, T))
          << "failed for " << to_string(input) << " and " << T;
    }
    {
      const auto input = std::get<0>(p);
      ASSERT_EQ(expected, two_numers_sum_hashset(input, T))
          << "failed for " << to_string(input) << " and " << T;
    }

    {
      auto input = std::get<0>(p);
      ASSERT_EQ(expected, two_numers_sum_sorting(input, T))
          << "failed for " << to_string(input) << " and " << T;
    }
    {
      auto input = std::get<0>(p);
      ASSERT_EQ(expected, two_numers_sum_two_pointers(input, T))
          << "failed for " << to_string(input) << " and " << T;
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
