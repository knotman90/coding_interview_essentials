int depth_cached(Node<int>* root, std::unordered_map<Node<int>*, int>& D)
{
  if (!root)
    return 0;

  if (D.find(root) != D.end())
    return D[root];

  int ans = 0;
  if (root->left)
    ans = 1 + depth_cached(root->left, D);
  if (root->right)
    ans = std::max(ans, 1 + depth_cached(root->right, D));

  D[root] = ans;
  return ans;
}
int diameter_of_binary_tree_linear(Node<int>* root,
                                   std::unordered_map<Node<int>*, int>& D)
{
  if (!root)
    return 0;
  int l, r;
  l = r = 0;
  if (root->left)
    l = 1 + depth_cached(root->left, D);
  if (root->right)
    r = 1 + depth_cached(root->right, D);
  return std::max(
      std::max(l + r, diameter_of_binary_tree_linear(root->left, D)),
      diameter_of_binary_tree_linear(root->right, D));
}