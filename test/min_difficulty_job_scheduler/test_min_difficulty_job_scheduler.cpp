#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "generate_combinations.h"
#include "min_difficulty_job_scheduler_solution1.cpp"
#include "min_difficulty_job_scheduler_solution2.cpp"
#include "min_difficulty_job_scheduler_solution3.cpp"
#include "min_difficulty_job_scheduler_solution4.cpp"

TEST(min_difficulty_job_scheduler, example1)
{
  const vector<int> I = {6, 5, 4, 3, 2, 1};
  for (const auto& test_data : {
           std::make_tuple<int, int>(1, 6),
           std::make_tuple<int, int>(2, 7),
           std::make_tuple<int, int>(3, 9),
           std::make_tuple<int, int>(4, 12),
           std::make_tuple<int, int>(5, 16),
           std::make_tuple<int, int>(6, 21),
           std::make_tuple<int, int>(7, -1),
           std::make_tuple<int, int>(8, -1),
       })
  {
    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_combinations(I, d);
      ASSERT_EQ(expected, actual);
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_topdown(I, d);
      ASSERT_EQ(expected, actual);
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_bottomup(I, d);
      ASSERT_EQ(expected, actual);
    }
  }
}

TEST(min_difficulty_job_scheduler, example2)
{
  const vector<int> I = {10, 10, 10};
  for (const auto& test_data : {
           std::make_tuple<int, int>(1, 10),
           std::make_tuple<int, int>(2, 20),
           std::make_tuple<int, int>(3, 30),
           std::make_tuple<int, int>(4, -1),
       })
  {
    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_combinations(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_topdown(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_bottomup(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }
  }
}

TEST(min_difficulty_job_scheduler, example3)
{
  const vector<int> I = {11, 111, 22, 222, 33, 333, 44, 444};
  for (const auto& test_data : {
           std::make_tuple<int, int>(1, 444),
           std::make_tuple<int, int>(6, 843),
       })
  {
    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_combinations(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_topdown(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }

    {
      auto [d, expected] = test_data;
      auto actual        = min_difficulty_scheduler_DP_bottomup(I, d);
      ASSERT_EQ(expected, actual) << "failed for days = " << d;
    }

  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
