#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "remove_duplicated_sorted_array_inplace_solution1.cpp"
#include "remove_duplicated_sorted_array_inplace_solution2.cpp"
#include "remove_duplicated_sorted_array_inplace_solution3.cpp"

namespace rng = std::ranges;

TEST(remove_duplicated_sorted_array_inplace, test1)
{
  for (auto [I, expected] : {
           std::make_tuple<std::vector<int>, int>(
               {1, 2, 2, 3, 3, 4, 5, 6, 6, 6, 6, 7}, 7),
           {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1},
           {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 10},
           {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 20, 20, 20, 20, 20}, 11},
           {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
             0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
            11},
           {{-1}, 1},
           {{-1, -1}, 1},
       })
  {
    {
      auto input     = I;
      const auto res = remove_duplicates_constant_space(input);
      EXPECT_EQ(expected, res);
      ASSERT_TRUE(rng::is_sorted(rng::views::counted(input.begin(), expected)));
      std::unordered_set unique_elements(std::begin(input),
                                         std::begin(input) + expected);
      ASSERT_EQ(expected, unique_elements.size());
    }

    {
      auto input     = I;
      const auto res = remove_duplicates_linear_space(input);
      EXPECT_EQ(expected, res);
      ASSERT_TRUE(rng::is_sorted(rng::views::counted(input.begin(), expected)));
      std::unordered_set unique_elements(std::begin(input),
                                         std::begin(input) + expected);
      ASSERT_EQ(expected, unique_elements.size());
    }

    {
      auto input     = I;
      const auto res = remove_duplicates_STL(input);
      EXPECT_EQ(expected, res);
      ASSERT_TRUE(rng::is_sorted(rng::views::counted(input.begin(), expected)));
      std::unordered_set unique_elements(std::begin(input),
                                         std::begin(input) + expected);
      ASSERT_EQ(expected, unique_elements.size());
    }
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
