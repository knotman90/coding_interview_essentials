#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "max_num_chunks_sorted_solution1.cpp"
#include "max_num_chunks_sorted_solution2.cpp"

TEST(max_num_chunks_sorted, example1)
{
  const std::vector<int> input = {1, 4, 3, 5, 2, 10, 9};
  for (auto [I, expected] : {
           std::pair<std::vector<int>, int>(input, 3),
       })
  {
    {
     auto I_copy(I);
      EXPECT_EQ(max_chunks_to_sorted_lineartime(I_copy), expected);
    }

    {
        auto I_copy(I);
      EXPECT_EQ(max_chunks_to_sorted_bruteforce(I_copy), expected);
    }
  }
}


TEST(max_num_chunks_sorted, example2)
{
  const std::vector<int> input = {9,8,7,6,5,4,3,2,1};
  for (auto [I, expected] : {
           std::pair<std::vector<int>, int>(input, 1),
       })
  {
    {
        auto I_copy(I);
      EXPECT_EQ(max_chunks_to_sorted_lineartime(I_copy), expected);
    }

    {
        auto I_copy(I);
      EXPECT_EQ(max_chunks_to_sorted_bruteforce(I_copy), expected);
    }
  }
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
