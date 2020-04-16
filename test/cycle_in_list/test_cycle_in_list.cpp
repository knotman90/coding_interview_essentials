#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "list.h"
using Book::List::Node;

#include "cycle_in_list_solution1.cpp"
#include "cycle_in_list_solution2.cpp"


template <typename T>
Node<T> *create_list_from(std::vector<int> &vec, const int loop = -1)
{
  using N = Node<T>;
  if (vec.size() <= 0)
    return nullptr;

  std::vector<N *> p;

  for (size_t i = 0; i < vec.size(); i++)
    p.push_back(new N(vec[i]));

  for (int i = 0; i < (int)p.size() - 1; i++)
    p[i]->next = p[i + 1];

  if (loop >= (int)vec.size())
    throw std::invalid_argument(
        "loop index is larger than the length of the list");

  if (loop != -1)
    p.back()->next = p[loop];
  return p[0];
}

TEST(cycle_in_list, test_no_loop)
{

  std::vector<int> v = {1, 2, 3, 4};
  Node<int> *head    = create_list_from<int>(v, -1);

  Node<int> *ans_lin_space = detect_cycle_linear_time_space(head);
  EXPECT_EQ(nullptr, ans_lin_space);

  Node<int> *ans_floyd = detect_cycle_constant_time(head);
  EXPECT_EQ(nullptr, ans_floyd);
}

TEST(cycle_in_list, test_loop1)
{

  std::vector<int> v = {1, 2, 3, 4};
  Node<int> *head    = create_list_from<int>(v, 1);

  Node<int> *ans_lin_space = detect_cycle_linear_time_space(head);
  EXPECT_NE(nullptr, ans_lin_space);
  EXPECT_EQ(2, ans_lin_space->val);

  Node<int> *ans_floyd = detect_cycle_constant_time(head);
  EXPECT_NE(nullptr, ans_floyd);
  EXPECT_EQ(2, ans_floyd->val);
}

TEST(cycle_in_list, test_loop_long)
{

  std::vector<int> v = {
      1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
      35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
      52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
      69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
      86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

  for (int i = 0; i < v.size() - 1; i++)
  {
  	const int expected = v[i];
    Node<int> *head = create_list_from<int>(v, i);

    Node<int> *ans_lin_space = detect_cycle_linear_time_space(head);
    EXPECT_NE(nullptr, ans_lin_space);
    EXPECT_EQ(expected, ans_lin_space->val);

    Node<int> *ans_floyd = detect_cycle_constant_time(head);
    EXPECT_NE(nullptr, ans_floyd);
    EXPECT_EQ(expected, ans_floyd->val);
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
