#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "Interval.h"
#include "merge_intervals_2_merge_entire_list_solution1.cpp"

TEST(merge_intervals_2_entire_list, test_empty)
{
  std::vector<Interval> intervals = {};
  std::vector<Interval> expected  = {};

  const auto ans = merge_list_intervals_entire_list_lin_time(intervals);
  EXPECT_EQ(expected, ans);
}


TEST(merge_intervals_2_entire_list, example_1)
{
  
  std::vector<Interval> intervals = {{1,3},{2,6},{8,10},{15,18}};
  std::vector<Interval> expected  = {{1,6},{8,10},{15,18}};

  const auto ans = merge_list_intervals_entire_list_lin_time(intervals);
  EXPECT_EQ(expected, ans);
}

TEST(merge_intervals_2_entire_list, example_2)
{
  std::vector<Interval> intervals = {{1,4},{4,5}};
  std::vector<Interval> expected  = {{1,5}};

  const auto ans = merge_list_intervals_entire_list_lin_time(intervals);
  EXPECT_EQ(expected, ans);
}