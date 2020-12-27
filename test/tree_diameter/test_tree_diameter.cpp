#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

#include "binary_tree.h"
template <typename T>
using Node = Book::BinaryTree::Node<T>;

#include "tree_diameter_solution1.cpp"
#include "tree_diameter_solution2.cpp"

TEST(tree_diameter, test_full_2_levels)
{
  using Book::BinaryTree::Direction;
  auto root =
      Book::BinaryTree::from_arcs_and_values<int>(7,
                                                  {
                                                      {0, Direction::Left, 1},
                                                      {0, Direction::Right, 2},

                                                      {1, Direction::Left, 3},
                                                      {1, Direction::Right, 4},

                                                      {2, Direction::Left, 5},
                                                      {2, Direction::Right, 6},

                                                  },
                                                  {0, 1, 2, 3, 4, 5, 6});

  //  Book::BinaryTree::visit_in_order(
  //     root, [](const auto v) { cout << v << endl; });

  constexpr int expected = 4;
  {
    ASSERT_EQ(expected, diameter_of_binary_tree_quadratic(root));
  }

  {
    std::unordered_map<Node<int> *, int> D;
    ASSERT_EQ(expected, diameter_of_binary_tree_linear(root, D));
  }
}

TEST(tree_diameter, test_full_0_levels)
{
  using Book::BinaryTree::Direction;
  auto root =
      Book::BinaryTree::from_arcs_and_values<int>(7,
                                                  {
                                                      // empty tree
                                                  },
                                                  {0, 1, 2, 3, 4, 5, 6});

  constexpr int expected = 0;
  {
    ASSERT_EQ(expected, diameter_of_binary_tree_quadratic(root));
  }

  {
    std::unordered_map<Node<int> *, int> D;
    ASSERT_EQ(expected, diameter_of_binary_tree_linear(root, D));
  }
}

TEST(tree_diameter, test_full_3_levels)
{
  using Book::BinaryTree::Direction;
  auto root = Book::BinaryTree::from_arcs_and_values<int>(
      15,
      {
          {0, Direction::Left, 1},
          {0, Direction::Right, 2},

          {1, Direction::Left, 3},
          {1, Direction::Right, 4},

          {2, Direction::Left, 5},
          {2, Direction::Right, 6},

          {3, Direction::Left, 7},
          {3, Direction::Right, 8},

          {4, Direction::Left, 9},
          {4, Direction::Right, 10},

          {5, Direction::Left, 11},
          {5, Direction::Right, 12},

          {6, Direction::Left, 13},
          {6, Direction::Right, 14},

      },
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14});

  // Book::BinaryTree::visit_in_order(
  //    root, [](const auto v) { cout << v << endl; });

  constexpr int expected = 6;
  {
    ASSERT_EQ(expected, diameter_of_binary_tree_quadratic(root));
  }

  {
    std::unordered_map<Node<int> *, int> D;
    ASSERT_EQ(expected, diameter_of_binary_tree_linear(root, D));
  }
}

TEST(tree_diameter, test_example1)
{
  using Book::BinaryTree::Direction;
  auto root = Book::BinaryTree::from_arcs_and_values<int>(
      15,
      {

          {0, Direction::Left, 1},
          {0, Direction::Right, 2},

          {1, Direction::Left, 3},
          {1, Direction::Right, 4},

          {2, Direction::Left, 5},
          {2, Direction::Right, 6},

          {5, Direction::Left, 11},
          {5, Direction::Right, 12},

          {6, Direction::Left, 13},
          {6, Direction::Right, 14},

      },
      {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14});

  // Book::BinaryTree::visit_in_order(
  //    root, [](const auto v) { cout << v << endl; });

  constexpr int expected = 5;
  {
    ASSERT_EQ(expected, diameter_of_binary_tree_quadratic(root));
  }

  {
    std::unordered_map<Node<int> *, int> D;
    ASSERT_EQ(expected, diameter_of_binary_tree_linear(root, D));
  }
}

TEST(tree_diameter, test_list_7_nodes)
{
  using Book::BinaryTree::Direction;
  auto root =
      Book::BinaryTree::from_arcs_and_values<int>(7,
                                                  {
                                                      {0, Direction::Left, 1},
                                                      {1, Direction::Right, 2},
                                                      {2, Direction::Left, 3},
                                                      {3, Direction::Right, 4},
                                                      {4, Direction::Left, 5},
                                                      {5, Direction::Left, 6},
                                                  },
                                                  {0, 1, 2, 3, 4, 5, 6});

  //  Book::BinaryTree::visit_in_order(
  //     root, [](const auto v) { cout << v << endl; });

  constexpr int expected = 6;
  {
    ASSERT_EQ(expected, diameter_of_binary_tree_quadratic(root));
  }

  {
    std::unordered_map<Node<int> *, int> D;
    ASSERT_EQ(expected, diameter_of_binary_tree_linear(root, D));
  }
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
