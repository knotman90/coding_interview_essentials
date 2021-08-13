#include <iostream>

using Cache = std::unordered_map<TreeNode*, int>;

int tree_min_memoized(TreeNode* root, Cache& cache)
{
  if (!root)
    return std::numeric_limits<int>::max();

  if (cache.contains(root))
  {
    return cache[root];
  }

  const auto ans = std::min({root->val,
                             tree_min_memoized(root->left, cache),
                             tree_min_memoized(root->right, cache)});
  // update the cache
  cache.insert({root, ans});
  return ans;
}

int tree_max_memoized(TreeNode* root, Cache& cache)
{
  if (!root)
    return std::numeric_limits<int>::min();
  if (cache.contains(root))
  {
    return cache[root];
  }

  const auto ans = std::max({root->val,
                             tree_max_memoized(root->left, cache),
                             tree_max_memoized(root->right, cache)});
  // update the cache
  cache[root] = ans;
  return ans;
}
bool isValidBST_min_max_memoized_helper(TreeNode* root,
                                        Cache& min_cache,
                                        Cache& max_cache)
{
  if (!root)
    return true;

  bool left_ok = true;
  if (root->left)
    left_ok = tree_max_memoized(root->left, max_cache) <= root->val;
  bool right_ok = true;
  if (root->right)
    right_ok = tree_min_memoized(root->right, min_cache) > root->val;

  return (left_ok && right_ok)
         && (isValidBST_min_max_memoized_helper(
                 root->left, min_cache, max_cache)
             && isValidBST_min_max_memoized_helper(
                 root->right, min_cache, max_cache));
}

bool isValidBST_min_max_memoized(TreeNode* root)
{
  Cache min_cache, max_cache;
  return isValidBST_min_max_memoized_helper(root, min_cache, max_cache);
}