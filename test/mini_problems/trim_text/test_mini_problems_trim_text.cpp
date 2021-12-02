#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "trim_text_solution1.cpp"

TEST(trim_text, example1)
{
  const std::string input_text = "Lorem ipsum dolor  sit      amet    ";

  {
    size_t start               = 0;
    size_t end                 = 4;
    const std::string expected = "";
    for (size_t i = start; i <= end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }

  {
    size_t start               = 5;
    size_t end                 = 6;
    const std::string expected = "Lorem";
    for (size_t i = start; i <= end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }

  {
    size_t start               = 5;
    size_t end                 = 10;
    const std::string expected = "Lorem";
    for (size_t i = start; i < end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }

  {
    size_t start               = 11;
    size_t end                 = 17;
    const std::string expected = "Lorem ipsum";
    for (size_t i = start; i < end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }

  {
    size_t start               = 18;
    size_t end                 = 22;
    const std::string expected = "Lorem ipsum dolor";
    for (size_t i = start; i < end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans);
    }
  }

  {
    size_t start               = 23;
    size_t end                 = 31;
    const std::string expected = "Lorem ipsum dolor  sit";
    for (size_t i = start; i < end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }

  {
    size_t start               = 32;
    size_t end                 = input_text.size();
    const std::string expected = "Lorem ipsum dolor  sit      amet";
    for (size_t i = start; i < end; i++)
    {
      const auto ans = trim_text_lineartime(input_text, i);
      ASSERT_EQ(expected, ans) << "failed for " << i << std::endl;
      ;
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
