#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;
#include "list.h"
using Book::List::Node;
#include "list_reverse_solution1.cpp"
#include "list_reverse_solution2.cpp"

template <typename T>
Node<T> *create_list_from(const std::vector<int> &vec, const int loop = -1)
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

TEST(list_reverse, test_empty)
{
  const std::vector<int> input = {};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));

  Node<int> *head = create_list_from<int>(input, -1);
  ASSERT_EQ(nullptr, head);

  {
    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(nullptr, ans);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));
  }

  {
    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(nullptr, ans);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));
  }
}

TEST(list_reverse, test_one)
{
  const std::vector<int> input = {123456};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));

  Node<int> *head = create_list_from<int>(input, -1);

  {
    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_linear_space(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }

  {
    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_constant_space_iterative(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
}

TEST(list_reverse, test_single)
{
  std::vector<int> input = {};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(nullptr, head);
    ASSERT_EQ(input.size(), Book::List::length(head));

    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(nullptr, ans);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_linear_space(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(nullptr, head);
    ASSERT_EQ(input.size(), Book::List::length(head));
    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(nullptr, ans);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_constant_space_iterative(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
}

TEST(list_reverse, test_all_equal)
{
  std::vector<int> input = {1, 1, 1, 1, 1, 1, 1};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));
  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));
    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_linear_space(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));

    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_constant_space_iterative(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
}

TEST(list_reverse, example1)
{
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));
    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_linear_space(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));
    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_constant_space_iterative(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
}

TEST(list_reverse, example1_double_reverse)
{
  std::vector<int> input = {1, 2, 3, 4, 5};
  std::vector<int> expected(input);
  std::reverse(std::begin(expected), std::end(expected));

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));

    const auto ans = list_reverse_linear_space(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_linear_space(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }

  {
    Node<int> *head = create_list_from<int>(input, -1);
    ASSERT_EQ(input.size(), Book::List::length(head));
    const auto ans = list_reverse_constant_space_iterative(head);
    ASSERT_EQ(input.size(), Book::List::length(ans));
    ASSERT_EQ(expected, Book::List::to_vector(ans));

    const auto ans_double_reverse = list_reverse_constant_space_iterative(ans);
    ASSERT_EQ(input.size(), Book::List::length(ans_double_reverse));
    ASSERT_EQ(input, Book::List::to_vector(ans_double_reverse))
        << "double reverse should be equal to original list";
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
