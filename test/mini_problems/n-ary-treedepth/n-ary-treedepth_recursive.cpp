int n_ary_treedepth_recursive(Node* root)
{
  if (!root)
    return 0;
  int max_depth_child = 0;
  for (auto& childPtr : root->children)
  {
    max_depth_child =
        std::max(max_depth_child, n_ary_treedepth_recursive(childPtr));
  }
  return 1 + max_depth_child;
}