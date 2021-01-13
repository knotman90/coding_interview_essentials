#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "string_to_int_solution1.cpp"
#include "string_to_int_solution2.cpp"

TEST(string_to_int, test_zer0)
{
  const std::string s = "0";
  EXPECT_EQ(0, string_to_int1(s));
}

TEST(string_to_int, test_no_trailing_1234)
{
  const std::string s = "1234";
  EXPECT_EQ(1234, string_to_int1(s));
}

TEST(string_to_int, test_10000)
{
  const std::string s = "10000";
  EXPECT_EQ(10000, string_to_int1(s));
}

TEST(string_to_int, test_zer000000000000000)
{
  const std::string s = "00000000000000";
  EXPECT_EQ(0, string_to_int1(s));
}

TEST(string_to_int, test_no_trailing_000000000000001234)
{
  const std::string s = "000000000000001234";
  EXPECT_EQ(1234, string_to_int1(s));
}

TEST(string_to_int, test_no_trailing_0000000000000010000)
{
  const std::string s = "0000000000000010000";
  EXPECT_EQ(10000, string_to_int1(s));
}

// NEGATIVE SIGN

TEST(string_to_int, test_negative_zer0)
{
  const std::string s = "-0";
  EXPECT_EQ(0, string_to_int_negative(s));
}

TEST(string_to_int, test_negative_no_trailing_1234)
{
  const std::string s = "-1234";
  EXPECT_EQ(-1234, string_to_int_negative(s));
}

TEST(string_to_int, test_negative_10000)
{
  const std::string s = "-10000";
  EXPECT_EQ(-10000, string_to_int_negative(s));
}

TEST(string_to_int, test_negative_zer000000000000000)
{
  const std::string s = "-00000000000000";
  EXPECT_EQ(0, string_to_int_negative(s));
}

TEST(string_to_int, test_negative_no_trailing_000000000000001234)
{
  const std::string s = "-000000000000001234";
  EXPECT_EQ(-1234, string_to_int_negative(s));
}

TEST(string_to_int, test_negative_no_trailing_0000000000000010000)
{
  const std::string s = "-0000000000000010000";
  EXPECT_EQ(-10000, string_to_int_negative(s));
}

// POSITIVE SIGN

TEST(string_to_int, test_positive_zer0)
{
  const std::string s = "+0";
  EXPECT_EQ(0, string_to_int_negative(s));
}

TEST(string_to_int, test_positive_no_trailing_1234)
{
  const std::string s = "+1234";
  EXPECT_EQ(1234, string_to_int_negative(s));
}

TEST(string_to_int, test_positive_10000)
{
  const std::string s = "+10000";
  EXPECT_EQ(10000, string_to_int_negative(s));
}

TEST(string_to_int, test_positive_zer000000000000000)
{
  const std::string s = "+00000000000000";
  EXPECT_EQ(0, string_to_int_negative(s));
}

TEST(string_to_int, test_positive_no_trailing_000000000000001234)
{
  const std::string s = "+000000000000001234";
  EXPECT_EQ(1234, string_to_int_negative(s));
}

TEST(string_to_int, test_positive_no_trailing_0000000000000010000)
{
  const std::string s = "+0000000000000010000";
  EXPECT_EQ(10000, string_to_int_negative(s));
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
