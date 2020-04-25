int depth(Node<int>* root)
{
  if (!root)
    return 0;
  int ans = 0;
  if (root->left)
    ans = 1 + depth(root->left);
  if (root->right)
    ans = std::max(ans, 1 + depth(root->right));

  return ans;
}
int diameter_of_binary_tree_quadratic(Node<int>* root)
{
  if (!root)
    return 0;
  int l, r;
  l = r = 0;
  if (root->left)
    l = 1 + depth(root->left);
  if (root->right)
    r = 1 + depth(root->right);
  return std::max(std::max(l + r, diameter_of_binary_tree_quadratic(root->left)),
                  diameter_of_binary_tree_quadratic(root->right));
}