#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::string;
using std::swap;
using std::vector;
#include "binary_tree.h"

template <typename T>
using Node = Book::BinaryTree::Node<T>;
using Book::BinaryTree::Direction;

template <typename T>
Node<T>* find_LCA(Node<T>* root, const T& p, const T& q)
{
  while (root)
  {
    const auto& payload = root->val;
    if (payload > p && payload > q)
    {
      root = root->left;
    }
    else if (payload < p && payload < q)
    {
      root = root->right;
    }
    else
    {
      return root;
    }
  }
  return root;
}

#include "distance_between_nodes_in_tree_solution1.cpp"
#include "distance_between_nodes_in_tree_solution2.cpp"

constexpr size_t num_nodes_fulltree(const int height)
{
  assert(height > 0);
  return (1 << height) - 1;
}

TEST(distance_between_nodes_in_tree, test1)
{
  auto root = Book::BinaryTree::from_arcs_and_values<int>(
      num_nodes_fulltree(5),
      {
          {0, Direction::Left, 1},
          {0, Direction::Right, 2},
          {1, Direction::Right, 4},
          {2, Direction::Right, 6},
          {6, Direction::Left, 13},
          {13, Direction::Left, 27},
          {13, Direction::Right, 28},
      },
      {3, 1, 4, 0, 2, 0, 12, 0, 0, 0, 0, 0, 0,  10, 0, 0,
       0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 5, 11, 0,  0});

  // Book::BinaryTree::visit_in_order(root, [](const auto& val){cout<<val<<"
  // ";});
  for (std::tuple<int, int, int> value : {
           std::make_tuple(1, 3, 1),
           std::make_tuple(1, 1, 0),
           std::make_tuple(1, 4, 2),
           std::make_tuple(3, 3, 0),
           std::make_tuple(4, 4, 0),
           std::make_tuple(12, 2, 4),
           std::make_tuple(2, 12, 4),
           std::make_tuple(10, 2, 5),
           std::make_tuple(2, 10, 5),
           std::make_tuple(5, 11, 2),
           std::make_tuple(5, 12, 2),
           std::make_tuple(5, 3, 4),
           std::make_tuple(2, 11, 6),
           std::make_tuple(1, 11, 5),

       })
  {
    auto [p, q, expected] = value;
    {
      const auto& distance = min_distance_nodes_BST(root, p, q);
      ASSERT_EQ(distance, expected);
    }
  }
}

TEST(distance_between_nodes_in_tree, test2)
{
  auto root = Book::BinaryTree::from_arcs_and_values<int>(
      num_nodes_fulltree(4),
      {
          {0, Direction::Left, 1},
          {0, Direction::Right, 2},
          {1, Direction::Left, 3},
          {1, Direction::Right, 4},
          {2, Direction::Left, 5},
          {2, Direction::Right, 6},
          {6, Direction::Left, 13},
          {6, Direction::Right, 14},
      },
      {5, 2, 12, 1, 3, 9, 21, 0, 0, 0, 0, 0, 0, 19, 25});

  // Book::BinaryTree::visit_in_order(root, [](const auto& val){cout<<val<<"
  // ";});
  for (std::tuple<int, int, int> value : {
           std::make_tuple(3, 9, 4),
           std::make_tuple(3, 9, 4),
           std::make_tuple(9, 19, 3),
           std::make_tuple(12, 25, 2),
           std::make_tuple(1, 25, 5),

       })
  {
    auto [p, q, expected] = value;
    {
      const auto& distance = min_distance_nodes_BST(root, p, q);
      ASSERT_EQ(distance, expected);
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
