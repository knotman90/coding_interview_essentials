/**
 * Calculates the distance between T and a node with payload `val`
 * Perform a classic BST visit/search (downward) from T for val.
 *
 * @param T is valid binary search tree
 * @param val is the value to be searched in T
 * @return the distance between T and val
 */
template <typename U>
int find_distance_down(const Node<U>* const T, const U val)
{
  assert(T && "node val exists and is reachable from T");
  const auto& payload = T->val;
  if (payload == val)
    return 0;
  if (val <= payload)
    return 1 + find_distance_down(T->left, val);
  return 1 + find_distance_down(T->right, val);
}

/**
 * Find the distance between two nodes a tree
 *
 * @param T is valid binary search tree
 * @param p is the payload of a node in T
 * @param q is the payload of a node in T
 * @return the minimum number of edges to traverse to get from p to q
 */
template <typename U>
int min_distance_nodes_BST(Node<U>* T, const U p, const U q)
{
  const Node<U>* const lca = find_LCA(T, p, q);
  return find_distance_down(lca, p) + find_distance_down(lca, q);
}