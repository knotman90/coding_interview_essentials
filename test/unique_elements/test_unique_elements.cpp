#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "unique_elements_brute_force.cpp"
#include "unique_elements_brute_force_final.cpp"
#include "unique_elements_brute_force_map.cpp"
#include "unique_elements_brute_force_std.cpp"

using std::string;

std::string get_alphabet()
{
  string s = "";
  for (char c = 'a'; c <= 'z'; c++)
    s += c;
  return s;
}

TEST(unique_elements, given_empty_string_should_return_true)
{
  string a = "";
  EXPECT_TRUE(unique_elements_brute_force(a));
  EXPECT_TRUE(unique_elements_brute_force_std(a));
  EXPECT_TRUE(unique_elements_map(a));
  EXPECT_TRUE(unique_elements_final(a));
}

TEST(unique_elements, given_one_char_string_should_return_true)
{
  string a = "x";
  EXPECT_TRUE(unique_elements_brute_force(a));
  EXPECT_TRUE(unique_elements_brute_force_std(a));
  EXPECT_TRUE(unique_elements_map(a));
  EXPECT_TRUE(unique_elements_final(a));
}

TEST(unique_elements, given_two_unique_chars_string_should_return_true)
{
  string a = "xy";
  EXPECT_TRUE(unique_elements_brute_force(a));
  EXPECT_TRUE(unique_elements_brute_force_std(a));
  EXPECT_TRUE(unique_elements_map(a));
  EXPECT_TRUE(unique_elements_final(a));
}

TEST(unique_elements, given_two_duplicate_chars_string_should_return_false)
{
  string a = "xx";
  EXPECT_FALSE(unique_elements_brute_force(a));
  EXPECT_FALSE(unique_elements_brute_force_std(a));
  EXPECT_FALSE(unique_elements_map(a));
  EXPECT_FALSE(unique_elements_final(a));
}

TEST(unique_elements, given_string_all_alphabet_should_return_true)
{
  string s = get_alphabet();

  EXPECT_TRUE(unique_elements_brute_force(s));
  EXPECT_TRUE(unique_elements_brute_force_std(s));
  EXPECT_TRUE(unique_elements_map(s));
  EXPECT_TRUE(unique_elements_final(s));
}

TEST(unique_elements, given_string_two_times_all_alphabet_should_return_false)
{
  string s = get_alphabet() + get_alphabet();

  EXPECT_FALSE(unique_elements_brute_force(s));
  EXPECT_FALSE(unique_elements_brute_force_std(s));
  EXPECT_FALSE(unique_elements_map(s));
  EXPECT_FALSE(unique_elements_final(s));
}

TEST(unique_elements, given_almost_all_unique_string_should_return_false)
{
  string s = get_alphabet();
  s += 'a';

  EXPECT_FALSE(unique_elements_brute_force(s));
  EXPECT_FALSE(unique_elements_brute_force_std(s));
  EXPECT_FALSE(unique_elements_map(s));
  EXPECT_FALSE(unique_elements_final(s));
}

TEST(unique_elements, given_string_davide_return_false)
{
  string s                      = "davide";
  constexpr bool expected_value = false;

  EXPECT_EQ(expected_value, unique_elements_brute_force(s));
  EXPECT_EQ(expected_value, unique_elements_brute_force_std(s));
  EXPECT_EQ(expected_value, unique_elements_map(s));
  EXPECT_EQ(expected_value, unique_elements_final(s));
}

TEST(unique_elements, given_string_piano_return_true)
{
  string s                      = "piano";
  constexpr bool expected_value = true;

  EXPECT_EQ(expected_value, unique_elements_brute_force(s));
  EXPECT_EQ(expected_value, unique_elements_brute_force_std(s));
  EXPECT_EQ(expected_value, unique_elements_map(s));
  EXPECT_EQ(expected_value, unique_elements_final(s));
}

TEST(unique_elements, given_string_michelangeli_return_false)
{
  string s                      = "michelangeli";
  constexpr bool expected_value = false;

  EXPECT_EQ(expected_value, unique_elements_brute_force(s));
  EXPECT_EQ(expected_value, unique_elements_brute_force_std(s));
  EXPECT_EQ(expected_value, unique_elements_map(s));
  EXPECT_EQ(expected_value, unique_elements_final(s));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}