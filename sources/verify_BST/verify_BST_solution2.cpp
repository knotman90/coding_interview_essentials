#include <iostream>

int tree_min(TreeNode *root)
{
  if (!root)
    return std::numeric_limits<int>::max();
  return std::min({root->val, tree_min(root->left), tree_min(root->right)});
}

int tree_max(TreeNode *root)
{
  if (!root)
    return std::numeric_limits<int>::min();
  return std::max({root->val, tree_max(root->left), tree_max(root->right)});
}
bool isValidBST_min_max(TreeNode *root)
{
  if (!root)
    return true;

  bool left_ok = true;
  if (root->left)
    left_ok = tree_max(root->left) <= root->val;
  bool right_ok = true;
  if (root->right)
    right_ok = tree_min(root->right) > root->val;

  return (left_ok && right_ok)
         && (isValidBST_min_max(root->left) && isValidBST_min_max(root->right));
}