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

#include "lowest_common_ancestor_solution1.cpp"
#include "lowest_common_ancestor_solution2.cpp"
#include "lowest_common_ancestor_solution3.cpp"

TEST(lowest_common_ancestor, test1)
{
  using Book::BinaryTree::Direction;
  auto root = Book::BinaryTree::from_arcs_and_values<int>(3,
                                                          {
                                                              {0, Direction::Left, 1},
                                                              {0, Direction::Right, 2},
                                                          },
                                                          {2, 1, 3});

  for (std::tuple<int, int, int> value : {
           std::make_tuple(1, 3, 2),
           std::make_tuple(1, 1, 1),
           std::make_tuple(2, 3, 2),
           std::make_tuple(3, 3, 3),

       })
  {
    auto [p, q, expected] = value;
    {
      const auto& LCA = findLeastCommonAncestor_reference(root, p, q);
      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
    {
      const auto& LCA = findLeastCommonAncestor_paths(root, p, q);
      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
    {
      const auto& LCA = findLeastCommonAncestor_paths_optimized(root, p, q);
      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
  }
}

TEST(lowest_common_ancestor, example1)
{
  using Book::BinaryTree::Direction;
  auto root = Book::BinaryTree::from_arcs_and_values<int>(
      63,
      {
          {0, Direction::Left, 1},  // 13
          {0, Direction::Right, 2},

          {1, Direction::Left, 3},  // 3
          {1, Direction::Right, 4},

          {2, Direction::Right, 6},  // 14

          {3, Direction::Right, 8},  // 1

          {4, Direction::Right, 10},  // 4

          {10, Direction::Left, 21},  // 12

          {21, Direction::Left, 43},   // 10
          {21, Direction::Right, 44},  // 10

      },
      {13, 3, 14, 1, 4, 0, 18, 0, 2, 0, 12, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
       0,  0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  5, 11, 0, 0, 0, 0, 0, 0, 0, 0, 0,  0, 0, 0, 0, 0, 0, 0, 0, 0});

  for (std::tuple<int, int, int> value : {
           std::make_tuple(3, 14, 13),
           std::make_tuple(1, 12, 3),
           std::make_tuple(5, 2, 3),
           std::make_tuple(11, 2, 3),
           std::make_tuple(11, 18, 13),
           std::make_tuple(14, 18, 14),
           std::make_tuple(11, 11, 11),
       })
  {
    auto [p, q, expected] = value;
    {
      const auto& LCA = findLeastCommonAncestor_reference(root, p, q);

      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
    {
      const auto& LCA = findLeastCommonAncestor_paths(root, p, q);
      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
    {
      const auto& LCA = findLeastCommonAncestor_paths_optimized(root, p, q);
      ASSERT_TRUE(LCA) << "error for nodes " << p << "and " << q;
      ASSERT_EQ(LCA->val, expected);
    }
  }
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
