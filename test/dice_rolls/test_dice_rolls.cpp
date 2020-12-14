#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "dice_rolls_solution1.cpp"
#include "dice_rolls_solution2.cpp"
#include "dice_rolls_solution3.cpp"

TEST(dice_rolls, test_d1_f6_t3)
{
  constexpr int d = 1;
  constexpr int f = 6;
  constexpr int t = 3;

  constexpr int expected = 1;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d2_f6_t7)
{
  constexpr int d = 2;
  constexpr int f = 6;
  constexpr int t = 7;

  constexpr int expected = 6;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d2_f5_t10)
{
  constexpr int d = 2;
  constexpr int f = 5;
  constexpr int t = 10;

  constexpr int expected = 1;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
   ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d1_f2_t3)
{
  constexpr int d = 1;
  constexpr int f = 2;
  constexpr int t = 3;

  constexpr int expected = 0;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d1_f100_t101)
{
  constexpr int d = 1;
  constexpr int f = 100;
  constexpr int t = 101;

  constexpr int expected = 0;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d7_f10_t71)
{
  constexpr int d = 7;
  constexpr int f = 10;
  constexpr int t = 1 + d * f;

  constexpr int expected = 0;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d7_f10_t70)
{
  constexpr int d = 7;
  constexpr int f = 10;
  constexpr int t = d * f;

  constexpr int expected = 1;

  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}

TEST(dice_rolls, test_d7_f10_t69)
{
  constexpr int d = 7;
  constexpr int f = 10;
  constexpr int t = 0.5*(d * f);

  constexpr int expected = 465795;


  ASSERT_EQ(expected, num_rolls_to_target_bruteforce(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_memoization(d, f, t));
  ASSERT_EQ(expected, num_rolls_to_target_bottom_up(d, f, t));
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
