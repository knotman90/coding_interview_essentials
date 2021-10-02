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
#include "meeting_rooms1_inputs.h"
#include "meeting_rooms1_solution1.cpp"

#include "meeting_rooms1_solution3.cpp"

#include "algorithm.h"
#include "test_utils.h"

TEST(meeting_rooms1, test_all_disjoint_all_negative)
{
  std::vector<Interval> intervals = {{-10, -9},
                                     {-9, -8},
                                     {-8, -7},
                                     {-7, -6},
                                     {-6, -5},
                                     {-5, -4},
                                     {-4, -3},
                                     {-3, -2},
                                     {-2, -1},
                                     {-1, -0}};
  const unsigned expected         = 1;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }

  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_all_disjoint_some_negative)
{
  std::vector<Interval> intervals = {{-10, -9},
                                     {-9, -8},
                                     {-8, -7},
                                     {-7, -6},
                                     {5, 6},
                                     {6, 7},
                                     {7, 8},
                                     {8, 9},
                                     {9, 10},
                                     {10, 11}};
  const unsigned expected         = 1;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }

  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_empty)
{
  std::vector<Interval> intervals = {};
  const unsigned expected         = 0;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_single)
{
  std::vector<Interval> intervals = {{0, 10}};
  const unsigned expected         = 1;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_all_disjoint)
{
  std::vector<Interval> intervals = {{1, 2},
                                     {2, 3},
                                     {3, 4},
                                     {4, 5},
                                     {5, 6},
                                     {6, 7},
                                     {7, 8},
                                     {8, 9},
                                     {9, 10},
                                     {10, 11}};
  const unsigned expected         = 1;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_all_disjoint_very_long)
{
  std::vector<Interval> intervals = disjoint_50k;
  const unsigned expected         = 1;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, test_all_overlapping)
{
  std::vector<Interval> intervals = all_overlapping_50;
  const unsigned expected         = 50;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, testDisjointOverlappingSeriesShuffled)
{
  // all_overlapping_50 + another smaller series of overlapping meetings all
  // happening after the last in all_overlapping_50
  std::vector<Interval> intervals = {
      {5, 95},  {44, 56},  {88, 102}, {32, 68},  {85, 105}, {31, 69}, {42, 58},
      {45, 55}, {43, 57},  {18, 82},  {26, 74},  {83, 107}, {93, 97}, {84, 106},
      {13, 87}, {20, 80},  {14, 86},  {50, 50},  {36, 64},  {15, 85}, {48, 52},
      {10, 90}, {21, 79},  {19, 81},  {37, 63},  {9, 91},   {34, 66}, {28, 72},
      {41, 59}, {81, 109}, {23, 77},  {2, 98},   {6, 94},   {46, 54}, {39, 61},
      {22, 78}, {4, 96},   {90, 100}, {27, 73},  {0, 100},  {35, 65}, {89, 101},
      {91, 99}, {3, 97},   {40, 60},  {86, 104}, {82, 108}, {7, 93},  {38, 62},
      {17, 83}, {16, 84},  {92, 98},  {12, 88},  {24, 76},  {29, 71}, {30, 70},
      {25, 75}, {11, 89},  {47, 53},  {80, 110}, {33, 67},  {94, 96}, {8, 92},
      {1, 99},  {87, 103}, {49, 51}};
  const unsigned expected = 50;

  {
    const auto ans = calculate_number_meeting_rooms1(intervals);
    EXPECT_EQ(expected, ans);
  }
  {
    const auto ans = calculate_number_meeting_rooms3_touchpoints(intervals);
    EXPECT_EQ(expected, ans);
  }
}

TEST(meeting_rooms1, all_solutions_are_equal)
{
  constexpr size_t num_tests = 1000;

  for (size_t i = 0; i < num_tests; i++)
  {
    const size_t input_size =
        Book::Algorithm::get_random_in_range<size_t>(1, 1000);
    std::vector<Interval> Q(input_size);
    std::generate(Q.begin(), Q.end(), [&]() {
      auto p = Book::Algorithm::generate_random_pair_in_range<int>(0, 100);
      while (p.first == p.second)
      {
        p = Book::Algorithm::generate_random_pair_in_range<int>(0, 100);
      }
      return Interval{std::min(p.first, p.second), std::max(p.first, p.second)};
    });

    for (auto& p : Q)
    {
      if (p.start > p.end)
      {
        std::swap(p.start, p.end);
      }
    }
    std::vector<unsigned> answers;
    {
      std::vector<Interval> input(Q);
      answers.push_back(calculate_number_meeting_rooms1(input));
    }
    {
      std::vector<Interval> input(Q);
      answers.push_back(calculate_number_meeting_rooms3_touchpoints(input));
    }

    ASSERT_TRUE(std::all_of(std::begin(answers),
                            std::end(answers),
                            [&](const auto& v) { return v == answers.back(); }))
        << "error for input  = " << to_string(Q) << std::endl
        << "answers = " << to_string(answers);
  }
}
