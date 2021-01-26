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
#include "mirror_binary_tree_solution1.cpp"
#include "mirror_binary_tree_solution2.cpp"

template <typename T>
Node<T>* treeFromList_helper(const std::vector<std::optional<T>>& payloads,
                             const int pos)
{
  if (pos >= payloads.size() || !(payloads[pos].has_value()))
    return nullptr;
  Node<T>* root = new Node<T>(payloads[pos].value());
  root->left    = treeFromList_helper<T>(payloads, pos * 2);
  root->right   = treeFromList_helper<T>(payloads, pos * 2 + 1);
  return root;
}

template <typename T>
Node<T>* treeFromList(std::vector<std::optional<T>>& payloads)
{
  payloads.insert(begin(payloads), std::nullopt);
  return treeFromList_helper(payloads, 1);
}

template <typename T>
bool equals(Node<T>* t1, Node<T>* t2)
{
  if (!t1 && !t2)
    return true;
  if ((!t1 && t2) || (t1 && !t2))
    return false;

  return (t1 != t2) && (t1->payload == t2->payload)
         && equals(t1->left, t2->left) && equals(t1->right, t2->right);
}

TEST(mirror_binary_tree, test_equals)
{
  /*
    1      1
   2         2
  */
  std::vector<std::optional<int>> values        = {1, 2};
  std::vector<std::optional<int>> values_mirror = {
      1, std::nullopt, 2, std::nullopt, std::nullopt, 5};

  auto tree  = treeFromList<int>(values);
  auto tree1 = treeFromList<int>(values_mirror);

  EXPECT_FALSE(equals(tree, tree1));
  EXPECT_FALSE(equals(tree1, tree));
}

TEST(mirror_binary_tree, test_equals1)
{
  /*
    1      1
   2         2
  */
  std::vector<std::optional<int>> values        = {1, 2, 3, 4, 5};
  std::vector<std::optional<int>> values_mirror = {1, 2, 3, 4, 5};

  auto tree  = treeFromList<int>(values);
  auto tree1 = treeFromList<int>(values_mirror);

  EXPECT_TRUE(equals(tree, tree1));
  EXPECT_TRUE(equals(tree1, tree));
}

//---------------

TEST(mirror_binary_tree, test_empty)
{
  std::vector<std::optional<int>> values        = {};
  std::vector<std::optional<int>> values_mirror = {};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_leaf)
{
  std::vector<std::optional<int>> values        = {1};
  std::vector<std::optional<int>> values_mirror = {1};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_single_double_leaf)
{
  /*
    1      1
   2 3    3  2
  */
  std::vector<std::optional<int>> values        = {1, 2, 3};
  std::vector<std::optional<int>> values_mirror = {1, 3, 2};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_single_left_child_only_leaf)
{
  /*
    1      1
   2         2
  */
  std::vector<std::optional<int>> values        = {1, 2};
  std::vector<std::optional<int>> values_mirror = {1, std::nullopt, 2};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_single_right_child_only_leaf)
{
  /*
    1      1
      2  2
  */
  std::vector<std::optional<int>> values        = {1, std::nullopt, 2};
  std::vector<std::optional<int>> values_mirror = {1, 2, std::nullopt};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_example1)
{
  /*
    1      1
      2  2
  */
  std::vector<std::optional<int>> values        = {5, 3, 6, 2, 4};
  std::vector<std::optional<int>> values_mirror = {
      5, 6, 3, std::nullopt, std::nullopt, 4, 2};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_example2)
{
  /*
    1      1
      2  2
  */
  std::vector<std::optional<int>> values = {
      2, 1, 8, 12, std::nullopt, 9, std::nullopt};
  std::vector<std::optional<int>> values_mirror = {
      2, 8, 1, std::nullopt, 9, std::nullopt, 12};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

TEST(mirror_binary_tree, test_example3)
{
  /*
    1      1
      2  2
  */
  std::vector<std::optional<int>> values        = {1,
                                            2,
                                            3,
                                            4,
                                            5,
                                            6,
                                            7,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt,
                                            6,
                                            7,
                                            std::nullopt,
                                            std::nullopt,
                                            std::nullopt};
  std::vector<std::optional<int>> values_mirror = {1,
                                                   3,
                                                   2,
                                                   7,
                                                   6,
                                                   5,
                                                   4,
                                                   std::nullopt,
                                                   std::nullopt,
                                                   std::nullopt,
                                                   7,
                                                   6,
                                                   std::nullopt,
                                                   std::nullopt,
                                                   std::nullopt};

  auto tree        = treeFromList<int>(values);
  auto tree_mirror = treeFromList<int>(values_mirror);

  auto res = mirror_binary_tree(tree);
  EXPECT_TRUE(equals(tree_mirror, res));

  auto res_fly = mirror_binary_tree_on_the_fly(tree);
  EXPECT_TRUE(equals(tree_mirror, res_fly));
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
