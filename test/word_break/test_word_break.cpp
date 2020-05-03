#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "word_break_solution1.cpp"
#include "word_break_solution2.cpp"

TEST(word_break, test1)
{
  const std::string s                 = "ilovecoding";
  const std::vector<std::string> dict = {"i", "coding", "love"};

  // ASSERT_TRUE(word_break_rute_force(s, dict));
  ASSERT_TRUE(word_break_top_down(s, dict));
}

TEST(word_break, test2)
{
  const std::string s                 = "ilovecodding";
  const std::vector<std::string> dict = {"i", "coding", "love"};

  // ASSERT_TRUE(word_break_rute_force(s, dict));
  ASSERT_FALSE(word_break_top_down(s, dict));
}

TEST(word_break, test3)
{
  const std::string s                 = "catsandog";
  const std::vector<std::string> dict = {"cats", "and", "dog", "sand", "cat"};

  // ASSERT_TRUE(word_break_rute_force(s, dict));
  ASSERT_FALSE(word_break_top_down(s, dict));
}


int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
