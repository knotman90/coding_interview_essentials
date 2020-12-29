#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;
using std::vector;

#include "list.h"
using Book::List::Node;

#include "delete_duplicates_list_solution1.cpp"
#include "delete_duplicates_list_solution2.cpp"

using Ni = Node<int>;

TEST(delete_duplicates_list, test_to_vector_1)
{
  Ni a(1), b(2), c(3), d(4), e(5);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  auto v              = Book::List::to_vector(&a);
  const auto expected = std::vector<int>({1, 2, 3, 4, 5});
  EXPECT_EQ(v, expected);
}

TEST(delete_duplicates_list, test_to_vector_2)
{
  Ni a(1), b(1), c(1), d(-1), e(-1);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  const auto v        = Book::List::to_vector(&a);
  const auto expected = std::vector<int>({1, 1, 1, -1, -1});
  EXPECT_EQ(v, expected);
}

TEST(delete_duplicates_list, test_from_vector_2)
{
  const auto input = std::vector<int>({1, 1, 1, -1, -1});

  Ni *list = Book::List::from_vector(input);
  for (const auto x : input)
  {
    EXPECT_NE(nullptr, list);
    EXPECT_EQ(x, list->val);
    list = list->next;
  }
  EXPECT_EQ(nullptr, list);
}

TEST(delete_duplicates_list, test_from_vector_1)
{
  const auto input = std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});

  Ni *list = Book::List::from_vector(input);
  for (const auto x : input)
  {
    EXPECT_NE(nullptr, list);
    EXPECT_EQ(x, list->val);
    list = list->next;
  }
  EXPECT_EQ(nullptr, list);
}

TEST(delete_duplicates_list, test_from_vector_empty)
{
  const auto input = std::vector<int>();

  Ni *list = Book::List::from_vector(input);
  EXPECT_EQ(nullptr, list);
}

TEST(delete_duplicates_list, test_remove_dupliacate_1)
{
  const vector<int> V        = {1, 1, 2, 2, 3, 3, 3, 3, 4};
  const vector<int> expected = {1, 2, 3, 4};
  Ni *list                   = Book::List::from_vector(V);
  EXPECT_NE(nullptr, list);
  Ni *list_unique_bf  = remove_duplicates_from_linked_list_1(list);
  Ni *list_unique_lin = remove_duplicates_from_linked_list_linear_space(list);

  for (const auto x : expected)
  {
    EXPECT_NE(nullptr, list_unique_bf);
    EXPECT_EQ(x, list_unique_bf->val);
    list_unique_bf = list_unique_bf->next;

    // linear time solution
    EXPECT_NE(nullptr, list_unique_lin);
    EXPECT_EQ(x, list_unique_lin->val);
    list_unique_lin = list_unique_lin->next;
  }
  EXPECT_EQ(nullptr, list_unique_bf);
  EXPECT_EQ(nullptr, list_unique_lin);
}

TEST(delete_duplicates_list, test_remove_duplicate_up_100)
{
  vector<int> V = {
      1,  1,  1,  2,  2,  2,  3,  3,  3,  4,   4,   4,  5,  5,  5,  6,  6,  6,
      7,  7,  7,  8,  8,  8,  9,  9,  9,  10,  10,  10, 11, 11, 11, 12, 12, 12,
      13, 13, 13, 14, 14, 14, 15, 15, 15, 16,  16,  16, 17, 17, 17, 18, 18, 18,
      19, 19, 19, 20, 20, 20, 21, 21, 21, 22,  22,  22, 23, 23, 23, 24, 24, 24,
      25, 25, 25, 26, 26, 26, 27, 27, 27, 28,  28,  28, 29, 29, 29, 30, 30, 30,
      31, 31, 31, 32, 32, 32, 33, 33, 33, 34,  34,  34, 35, 35, 35, 36, 36, 36,
      37, 37, 37, 38, 38, 38, 39, 39, 39, 40,  40,  40, 41, 41, 41, 42, 42, 42,
      43, 43, 43, 44, 44, 44, 45, 45, 45, 46,  46,  46, 47, 47, 47, 48, 48, 48,
      49, 49, 49, 50, 50, 50, 51, 51, 51, 52,  52,  52, 53, 53, 53, 54, 54, 54,
      55, 55, 55, 56, 56, 56, 57, 57, 57, 58,  58,  58, 59, 59, 59, 60, 60, 60,
      61, 61, 61, 62, 62, 62, 63, 63, 63, 64,  64,  64, 65, 65, 65, 66, 66, 66,
      67, 67, 67, 68, 68, 68, 69, 69, 69, 70,  70,  70, 71, 71, 71, 72, 72, 72,
      73, 73, 73, 74, 74, 74, 75, 75, 75, 76,  76,  76, 77, 77, 77, 78, 78, 78,
      79, 79, 79, 80, 80, 80, 81, 81, 81, 82,  82,  82, 83, 83, 83, 84, 84, 84,
      85, 85, 85, 86, 86, 86, 87, 87, 87, 88,  88,  88, 89, 89, 89, 90, 90, 90,
      91, 91, 91, 92, 92, 92, 93, 93, 93, 94,  94,  94, 95, 95, 95, 96, 96, 96,
      97, 97, 97, 98, 98, 98, 99, 99, 99, 100, 100, 100};
  const vector<int> expected = {
      1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
      18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34,
      35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51,
      52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
      69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85,
      86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100};

  Ni *list = Book::List::from_vector(V);
  EXPECT_NE(nullptr, list);
  Ni *list_unique     = remove_duplicates_from_linked_list_1(list);
  Ni *list_unique_lin = remove_duplicates_from_linked_list_linear_space(list);

  for (const auto x : expected)
  {
    EXPECT_NE(nullptr, list_unique);
    EXPECT_EQ(x, list_unique->val);
    list_unique = list_unique->next;

    // linear time solution
    EXPECT_NE(nullptr, list_unique_lin);
    EXPECT_EQ(x, list_unique_lin->val);
    list_unique_lin = list_unique_lin->next;
  }
  EXPECT_EQ(nullptr, list_unique);
  EXPECT_EQ(nullptr, list_unique_lin);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
