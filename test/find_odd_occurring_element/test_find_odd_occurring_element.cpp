#include <bits/stdc++.h>
#include <gtest/gtest.h>

#include "find_odd_occurring_element_solution1.cpp"
#include "find_odd_occurring_element_solution2.cpp"
#include "find_odd_occurring_element_solution3.cpp"
#include "find_odd_occurring_element_solution4.cpp"
#include "find_odd_occurring_element_solution5.cpp"

using std::string;

TEST(find_odd_occurring_element, test1)
{
  const int expected       = 1;
  const std::vector<int> A = {1};

  EXPECT_EQ(odd_appearing_element_bruteforce_rawloop(A), expected);
  EXPECT_EQ(odd_appearing_element_bruteforce_standard(A), expected);
  EXPECT_EQ(odd_appearing_element_linear_space(A), expected);
  EXPECT_EQ(odd_appearing_element_final(A), expected);
  EXPECT_EQ(odd_appearing_element_final_std(A), expected);
}

TEST(find_odd_occurring_element, test_2)
{
  const int expected       = 2;
  const std::vector<int> A = {1, 1, 2};

  EXPECT_EQ(odd_appearing_element_bruteforce_rawloop(A), expected);
  EXPECT_EQ(odd_appearing_element_bruteforce_standard(A), expected);
  EXPECT_EQ(odd_appearing_element_linear_space(A), expected);
  EXPECT_EQ(odd_appearing_element_final(A), expected);
  EXPECT_EQ(odd_appearing_element_final_std(A), expected);
}

TEST(find_odd_occurring_element, test3)
{
  const int expected       = 2;
  const std::vector<int> A = {1, 1, 2, 2, 2, 2, 2, 3, 3};

  EXPECT_EQ(odd_appearing_element_bruteforce_rawloop(A), expected);
  EXPECT_EQ(odd_appearing_element_bruteforce_standard(A), expected);
  EXPECT_EQ(odd_appearing_element_linear_space(A), expected);
  EXPECT_EQ(odd_appearing_element_final(A), expected);
  EXPECT_EQ(odd_appearing_element_final_std(A), expected);
}

TEST(find_odd_occurring_element, test4)
{
  const int expected       = 2;
  const std::vector<int> A = {5,4,6,5,1,6,2,1,3,3,4,2,2};

  EXPECT_EQ(odd_appearing_element_bruteforce_rawloop(A), expected);
  EXPECT_EQ(odd_appearing_element_bruteforce_standard(A), expected);
  EXPECT_EQ(odd_appearing_element_linear_space(A), expected);
  EXPECT_EQ(odd_appearing_element_final(A), expected);
  EXPECT_EQ(odd_appearing_element_final_std(A), expected);
}

TEST(find_odd_occurring_element, test5)
{
  const int expected       = 95;
  const std::vector<int> A = { 9, 92, 41, 46,100, 11, 33, 73, 98, 50, 87, 18, 84, 99, 45, 13, 25, 28,  7, 20, 49, 35, 64, 78, 94, 76, 17,  4, 70, 82, 26, 77, 72,  3, 61,  2, 43, 91, 22, 32, 81, 75, 54, 36, 56, 53, 95, 79, 68, 14, 96,  1, 85, 62, 47, 39, 71, 83, 74, 10, 59, 12, 97, 67, 15,  5, 58, 23, 52, 88, 27, 16, 40, 93, 80, 66,  6, 34, 55, 90, 30, 19, 24, 29, 38, 69, 63, 21, 89, 42, 86, 37, 65,  8, 60, 44, 57, 51, 48, 31, 9, 92, 41, 46,100, 11, 33, 73, 98, 50, 87, 18, 84, 99, 45, 13, 95, 25, 28,  7, 20, 49, 35, 64, 78, 94, 76, 17,  4, 70, 82, 26, 77, 72,  3, 61,  2, 43, 91, 22, 32, 81, 75, 54, 36, 56, 53, 95, 79, 68, 14, 96,  1, 85, 62, 47, 39, 71, 83, 74, 10, 59, 12, 97, 67, 15,  5, 58, 23, 52, 88, 27, 16, 40, 93, 80, 66,  6, 34, 55, 90, 30, 19, 24, 29, 38, 69, 63, 21, 89, 42, 86, 37, 65,  8, 60, 44, 57, 51, 48, 31};

  EXPECT_EQ(odd_appearing_element_bruteforce_rawloop(A), expected);
  EXPECT_EQ(odd_appearing_element_bruteforce_standard(A), expected);
  EXPECT_EQ(odd_appearing_element_linear_space(A), expected);
  EXPECT_EQ(odd_appearing_element_final(A), expected);
  EXPECT_EQ(odd_appearing_element_final_std(A), expected);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
