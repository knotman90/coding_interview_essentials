#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "algorithm.h"
#include "palindrome_partitioning2_solution1.cpp"
#include "palindrome_partitioning2_solution2.cpp"
#include "palindrome_partitioning2_solution3.cpp"
#include "palindrome_partitioning2_solution3_iterative.cpp"
#include "palindrome_partitioning2_solution4.cpp"

TEST(palindrome_partitioning2, test1)
{
  for (const auto [s, expected] : {
           std::pair<std::string, int>("itopinonavevanonipoti", 0),
           std::pair<std::string, int>("ab", 1),
           std::pair<std::string, int>("abc", 2),
           std::pair<std::string, int>("abac", 1),
           std::pair<std::string, int>("abacfbf", 2),
           std::pair<std::string, int>("ababbbabbababa", 3),
           std::pair<std::string, int>("acac", 1),
           std::pair<std::string, int>("adda", 0),
       })
  {
    ASSERT_EQ(expected, palindrome_partitioning2_bruteforce(s))
        << "failed for " << s << std::endl;
    ASSERT_EQ(expected, palindrome_partitioning2_DP_topdown(s))
        << "failed for " << s << std::endl;
    ASSERT_EQ(expected, palindrome_partitioning2_DP_bottomup(s))
        << "failed for " << s << std::endl;

    ASSERT_EQ(expected, palindrome_partitioning2_DP_topdown_optimized_it(s))
        << "failed for " << s << std::endl;
  }
}

std::string getRandomString(const auto& charset, const int size)
{
  std::ostringstream ss;
  for (int i = 0; i < size; i++)
    ss << charset[Book::Algorithm::get_random_in_range<int>(
        0, charset.size() - 1)];
  return ss.str();
}

TEST(palindrome_partitioning2, random1)
{
  constexpr size_t numTests = 50;
  constexpr size_t size     = 20;
  for (const auto charset : {
           std::string("abc"),
           std::string("ab"),
           std::string("abzy"),
           std::string("a"),
       })
  {
    for (int i = 0; i < numTests; i++)
    {
      const int size_test = Book::Algorithm::get_random_in_range<int>(1, size);
      const std::string s = getRandomString(charset, size_test);
      const auto x1       = palindrome_partitioning2_bruteforce(s);
      const auto x2       = palindrome_partitioning2_DP_topdown(s);
      const auto x3       = palindrome_partitioning2_DP_bottomup(s);
      const auto x4       = palindrome_partitioning2_DP_topdown_optimized_it(s);
      const auto x5       = palindrome_partitioning2_DP_topdown_optimized(s);
      ASSERT_TRUE((x1 == x2) && (x2 == x3) && (x3 == x4) && (x4 == x5))
          << "failed for " << s << " x1 = " << x1 << " x2 = " << x2
          << " x3 = " << x3 << " x4 = " << x4 << " x5 = " << x5;
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
