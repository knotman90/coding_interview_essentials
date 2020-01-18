#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "capitalize_words_first_letter_solution1.cpp"
#include "capitalize_words_first_letter_solution2.cpp"

using std::string;

TEST(capitalize_words_first_letter, test_special_characters)
{

  const std::string lorem_original =
      "     333%mich456elangeli  SKJDH5R564FKSJD    3904857394     ciaone ";
  const std::string expected =
      "     333%mich456elangeli  SKJDH5R564FKSJD    3904857394     Ciaone ";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_one_word_space_front_back)
{

  const std::string lorem_original = "     michelangeli       ";
  const std::string expected       = "     Michelangeli       ";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_one_word_space_front)
{

  const std::string lorem_original = "     michelangeli";
  const std::string expected       = "     Michelangeli";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_one_word)
{

  const std::string lorem_original = "michelangeli";
  const std::string expected       = "Michelangeli";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_all_capitals)
{

  const std::string lorem_original = "ABCLSKDFOSIHOERIHOEDNGLSDKJOFIEHROTIER "
                                     "ABCLSKDFOSIHOERIHOEDNGLSDKJOFIEHROTIER "
                                     "ABCLSKDFOSIHOERIHOEDNGLSDKJOFIEHROTIER";
  const std::string expected = lorem_original;
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_only_spaces)
{

  const std::string lorem_original = R"(                  )";
  const std::string expected       = lorem_original;
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_empty)
{

  const std::string lorem_original = "";
  const std::string expected       = "";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

TEST(capitalize_words_first_letter, test_lorem)
{

  const std::string lorem_original =
      "Lorem ipsum dolor sit amet, consectetur adipiscing elit";
  const std::string expected =
      "Lorem Ipsum Dolor Sit Amet, Consectetur Adipiscing Elit";
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_iterator(ans));
    EXPECT_EQ(expected, ans);
  }
  {
    std::string ans(lorem_original);
    EXPECT_NO_THROW(capitalize_words_first_letter_adj_find(ans));
    EXPECT_EQ(expected, ans);
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
