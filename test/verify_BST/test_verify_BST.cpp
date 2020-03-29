#include <bits/stdc++.h>
#include <gtest/gtest.h>

using std::cout;
using std::endl;
using std::string;
using std::swap;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

#include "verify_BST_solution1.cpp"
#include "verify_BST_solution2.cpp"


TreeNode* BST_add(TreeNode* root, int val)
{
	if(!root)
	{
		return new TreeNode(val);
	}
	if(val <= root->val) 
		root->left = BST_add(root->left, val);
	else
		root->right = BST_add(root->right, val);
	return root;

}

int BST_size(TreeNode* root)
{
	if(!root)
	{
		return 0;
	}
	return 1 + BST_size(root->left) + BST_size(root->right);
}



TreeNode* create_BST(const std::vector<int>& vals)
{
	TreeNode* root = nullptr;
	for(const auto v : vals)
	{
		root = BST_add(root, v);
	}
	return root;
}

TEST(verify_BST, valid_BST_tree_1)
{
 
 	std::vector<int> nodes = {55,11,12,13,15};
	TreeNode* root = create_BST(nodes);
 	EXPECT_EQ(nodes.size(), BST_size(root));
 	EXPECT_TRUE(isValidBST_top_down(root));
 	EXPECT_TRUE(isValidBST_min_max(root));
}

TEST(verify_BST, empty_tree)
{
 
	TreeNode* empty = create_BST({});
 	EXPECT_EQ(0, BST_size(empty));
 	EXPECT_TRUE(isValidBST_top_down(empty));
 	EXPECT_TRUE(isValidBST_min_max(empty));
}

TEST(verify_BST, single_node_tree)
{
 
 	std::vector<int> nodes = {55};
	TreeNode* root = create_BST(nodes);
 	EXPECT_EQ(nodes.size(), BST_size(root));
 	EXPECT_TRUE(isValidBST_top_down(root));
 	EXPECT_TRUE(isValidBST_min_max(root));
}



TEST(verify_BST, valid_BST_tree_list)
{
 
 	std::vector<int> nodes = {1,2,3,4,5,6,7,8,9};
	TreeNode* root = create_BST(nodes);
 	EXPECT_EQ(nodes.size(), BST_size(root));
 	EXPECT_TRUE(isValidBST_top_down(root));
 	EXPECT_TRUE(isValidBST_min_max(root));
 	EXPECT_EQ(1, tree_min(root));
	EXPECT_EQ(9, tree_max(root));
}

TEST(verify_BST, invalid_BST_tree_1)
{
 
 	std::vector<int> nodes = {55,11,12,13,15};
	TreeNode* root = create_BST(nodes);
	root->left->right->val = 9;
 	EXPECT_EQ(nodes.size(), BST_size(root));
 	EXPECT_FALSE(isValidBST_top_down(root));
 	EXPECT_FALSE(isValidBST_min_max(root));

}

TEST(verify_BST, invalid_BST_tree_list)
{
 	std::vector<int> nodes = {1,2,3,4,5,6,7,8,9};
	TreeNode* root = create_BST(nodes);
	root->val = 10;
 	EXPECT_EQ(nodes.size(), BST_size(root));
 	EXPECT_FALSE(isValidBST_top_down(root));
 	EXPECT_FALSE(isValidBST_min_max(root));
}





int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
