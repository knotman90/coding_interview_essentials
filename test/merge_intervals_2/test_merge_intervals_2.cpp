#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "Interval.h"
#include "merge_intervals_2_solution1.cpp"
#include "merge_intervals_2_solution2.cpp"

bool operator==(const Interval&i1, const Interval& i2){
    return i1.start == i2.start && i1.end == i2.end;
}


TEST(merge_intervals_2, test_empty)
{
    std::vector<Interval> intervals = {};
    Interval newInterval = {1,1};

    std::vector<Interval> merged_intervals = {{1,1}};

    const auto ans = merge_intervals_lineartime(intervals, newInterval);
    EXPECT_EQ(merged_intervals,ans);
}

TEST(merge_intervals_2, test_single__no_overlap_before)
{
    std::vector<Interval> intervals = {{10,20}};
    Interval newInterval = {1,1};

    std::vector<Interval> merged_intervals = {{1,1},{10,20}};

    const auto ans = merge_intervals_lineartime(intervals, newInterval);
    EXPECT_EQ(merged_intervals,ans);
}

TEST(merge_intervals_2, test_single__no_overlap_after)
{
    std::vector<Interval> intervals = {{-10,-20}};
    Interval newInterval = {1,1};

    std::vector<Interval> merged_intervals = {{-10,-20},{1,1}};

    const auto ans = merge_intervals_lineartime(intervals, newInterval);
    EXPECT_EQ(merged_intervals,ans);
}

TEST(merge_intervals_2, test_single_fully_contained)
{
    const std::vector<Interval> intervals = {{10,20}};
    
    {
        const Interval newInterval = {11,19};
        const std::vector<Interval> merged_intervals = {{10,20}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

        {
        const Interval newInterval = {10,20};
        const std::vector<Interval> merged_intervals = {{10,20}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

    {
        const Interval newInterval = {10,10};
        const std::vector<Interval> merged_intervals = {{10,20}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }
}


TEST(merge_intervals_2, test_single_example1)
{
    std::vector<Interval> intervals = {{1,3},{6,9}};

    {
        const Interval newInterval = {2,5};
        const std::vector<Interval> merged_intervals = {{1,5},{6,9}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

        {
        const Interval newInterval = {4,5};
        const std::vector<Interval> merged_intervals = {{1,3},{4,5},{6,9}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }
}
TEST(merge_intervals_2, test_single_example2)
{
    std::vector<Interval> intervals = {{1, 2}, {3, 5}, {6 ,7}, {8, 10}, {12, 16}};

    {
        const Interval newInterval = {4,9};
        const std::vector<Interval> merged_intervals = {{1, 2}, {3, 10}, {12, 16}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

    {
        const Interval newInterval = {6,12};
        const std::vector<Interval> merged_intervals = {{1, 2}, {3, 5}, {6, 16}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

    {
        const Interval newInterval = {6,11};
        const std::vector<Interval> merged_intervals = {{1, 2}, {3, 5}, {6, 11},{12,16}};

        const auto ans = merge_intervals_lineartime(intervals, newInterval);
        EXPECT_EQ(merged_intervals,ans);
    }

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

