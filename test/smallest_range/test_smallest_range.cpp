#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "smallest_range_solution1.cpp"
#include "smallest_range_solution2.cpp"

TEST(smallest_range_1, test1)
{
  for (const std::tuple<std::vector<int>, int, int>& t : {
           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({1, 3, 6}), 0, 5),
           std::make_tuple(std::vector<int>({1, 3, 6}), 1, 3),
           std::make_tuple(std::vector<int>({1, 3, 6}), 2, 1),
           std::make_tuple(std::vector<int>({1, 3, 6}), 3, 0),
           std::make_tuple(std::vector<int>({1, 3, 6}), 4, 0),
           std::make_tuple(std::vector<int>({1, 3, 6}), 50, 0),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),

           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({6, 1, 3}), 0, 5),
           std::make_tuple(std::vector<int>({6, 1, 3}), 1, 3),
           std::make_tuple(std::vector<int>({6, 1, 3}), 2, 1),
           std::make_tuple(std::vector<int>({6, 1, 3}), 3, 0),
           std::make_tuple(std::vector<int>({6, 1, 3}), 4, 0),
           std::make_tuple(std::vector<int>({6, 1, 3}), 50, 0),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),

           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 0, 5),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 1, 3),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 2, 1),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 3, 0),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 4, 0),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 50, 0),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),
       })
  {
    const auto [I, K, expected] = t;
    EXPECT_EQ(smallest_range_I(I, K), expected);
  }
}

TEST(smallest_range_2, test1)
{
  for (std::tuple<std::vector<int>, int, int> t : {
           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({1, 3, 6}), 0, 5),
           std::make_tuple(std::vector<int>({1, 3, 6}), 1, 3),
           std::make_tuple(std::vector<int>({1, 3, 6}), 2, 2),
           std::make_tuple(std::vector<int>({1, 3, 6}), 3, 3),
           std::make_tuple(std::vector<int>({1, 3, 6}), 4, 5),
           std::make_tuple(std::vector<int>({1, 3, 6}), 5, 5),
           std::make_tuple(std::vector<int>({1, 3, 6}), 50, 5),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),

           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({6, 1, 3}), 0, 5),
           std::make_tuple(std::vector<int>({6, 1, 3}), 1, 3),
           std::make_tuple(std::vector<int>({6, 1, 3}), 2, 2),
           std::make_tuple(std::vector<int>({6, 1, 3}), 3, 3),
           std::make_tuple(std::vector<int>({6, 1, 3}), 4, 5),
           std::make_tuple(std::vector<int>({6, 1, 3}), 5, 5),
           std::make_tuple(std::vector<int>({6, 1, 3}), 50, 5),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),

           std::make_tuple(std::vector<int>({1}), 0, 0),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 0, 5),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 1, 3),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 2, 2),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 3, 3),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 4, 5),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 5, 5),
           std::make_tuple(std::vector<int>({-6, -1, -3}), 50, 5),
           std::make_tuple(std::vector<int>({0, 10}), 2, 6),
       })
  {
    auto [I, K, expected] = t;
    EXPECT_EQ(smallest_range_II(I, K), expected);
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
