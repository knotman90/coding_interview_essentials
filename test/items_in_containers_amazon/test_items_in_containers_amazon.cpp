#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "items_in_containers_amazon_solution1.cpp"
#include "items_in_containers_amazon_solution2.cpp"

#include "algorithm.h"
TEST(items_in_containers_amazon, test1)
{
  const std::string s                      = "|*|*|";
  const std::vector<std::pair<int, int>> Q = {{0, 2}, {0, 4}};
  const std::vector<int> expected          = {1, 2};

  {
    EXPECT_EQ(expected, items_in_containers_naive(s, Q));
  }
  {
    EXPECT_EQ(expected, items_in_containers_lineartime(s, Q));
  }
}

TEST(items_in_containers_amazon, test2)
{
  const std::string s                      = "|**|*|*";
  const std::vector<std::pair<int, int>> Q = {{0, 4}, {0, 5}};
  const std::vector<int> expected          = {2, 3};

  {
    EXPECT_EQ(expected, items_in_containers_naive(s, Q));
  }
  {
    EXPECT_EQ(expected, items_in_containers_lineartime(s, Q));
  }
}

TEST(items_in_containers_amazon, test3)
{
  const std::string s                      = "|**|**|";
  const std::vector<std::pair<int, int>> Q = {{1, 5}, {0, 5}};
  const std::vector<int> expected          = {0, 2};

  {
    EXPECT_EQ(expected, items_in_containers_naive(s, Q));
  }
  {
    EXPECT_EQ(expected, items_in_containers_lineartime(s, Q));
  }
}

TEST(items_in_containers_amazon, test4)
{
  const std::string s                      = "|*|**|";
  const std::vector<std::pair<int, int>> Q = {{3, 5}, {2, 3}, {0, 4}, {1, 3}};
  const std::vector<int> expected          = {0, 0, 1, 0};

  {
    EXPECT_EQ(expected, items_in_containers_naive(s, Q));
  }
  {
    EXPECT_EQ(expected, items_in_containers_lineartime(s, Q));
  }
}

TEST(items_in_containers_amazon, test5)
{
  const std::string s                      = "|**|*||**||*|";
  const std::vector<std::pair<int, int>> Q = {
      {9, 10}, {3, 7}, {2, 10}, {7, 8}, {4, 11}};
  const std::vector<int> expected = {0, 1, 3, 0, 2};

  {
    EXPECT_EQ(expected, items_in_containers_naive(s, Q));
  }
  {
    EXPECT_EQ(expected, items_in_containers_lineartime(s, Q));
  }
}

std::string input_string_containers(const int stride_size,
                                    const int max_strides,
                                    const char sep  = '|',
                                    const char item = '*')
{
  std::ostringstream ss;
  const auto num_strides =
      Book::Algorithm::get_random_in_range<int>(0, max_strides);

  for (int i = 0; i < num_strides; i++)
  {
    ss << sep;
    const auto len = Book::Algorithm::get_random_in_range<int>(0, stride_size);
    for (int j = 0; j < len; j++)
      ss << item;
  }
  return ss.str();
}

template <typename T>
auto generate_random_pair_in_range(const T s, const T e)
{
  assert(s <= e);
  auto M = Book::Algorithm::get_random_in_range<T>(s, e);
  auto m = Book::Algorithm::get_random_in_range<T>(s, e);
  if (M < m)
    swap(M, m);
  return std::pair<T, T>(m, M);
}

std::string to_string(const int& v)
{
  std::ostringstream ss;
  ss << v;
  return ss.str();
}

std::string to_string(const std::pair<int, int>& q)
{
  std::ostringstream ss;
  ss << "(";
  ss << std::get<0>(q);
  ss << ",";
  ss << std::get<1>(q);
  ss << ") ";
  return ss.str();
}

template <typename T>
std::string to_string(const std::vector<T>& Q)
{
  std::ostringstream ss;
  ss << "[";
  for (const auto& q : Q)
  {
    ss << to_string(q);
    ss << ", ";
  }
  ss << "]";
  return ss.str();
}

TEST(items_in_containers_amazon, test_random_all_solution_equal)
{
  const std::string s = input_string_containers(1000, 100);
  std::vector<std::pair<int, int>> Q(1000);
  std::generate(Q.begin(), Q.end(), [&]() {
    return generate_random_pair_in_range<int>(0, s.size() - 1);
  });

  std::vector<std::vector<int>> answers;

  answers.push_back(items_in_containers_naive(s, Q));
  answers.push_back(items_in_containers_lineartime(s, Q));

  ASSERT_TRUE(std::all_of(std::begin(answers),
                          std::end(answers),
                          [&](const auto& v) { return v == answers.back(); }))
      << "error for " << s << std::endl
      << " Q= " << to_string(Q) << std::endl
      << "answers = " << to_string(answers);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
