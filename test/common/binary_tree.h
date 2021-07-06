#ifndef BOOK__LIST
#define BOOK__LIST

#include <utility>
#include <vector>

namespace Book
{
namespace BinaryTree
{
template <typename T>
struct Node
{
  T val;
  Node* left;
  Node* right;
  Node(T x) : val(x), left(nullptr), right(nullptr)
  {
  }
};

enum class Direction
{
  Left,
  Right
};

//! return a fulltree where connections are specified in arcs
template <typename T>
Node<T>* from_arcs_and_values(
    const size_t n,
    const std::vector<std::tuple<size_t, Direction, size_t>>& arcs,
    const std::vector<T>& values)
{
  if (n == 0)
    return nullptr;
  if (values.size() != n)
    throw std::invalid_argument("values size must be equal n="
                                + std::to_string(n));
  using Nodeptr = Node<T>*;
  std::vector<Nodeptr> nodes(n, nullptr);
  for (size_t i = 0; i < n; i++)
  {
    nodes[i] = new Node<T>(values[i]);
  }

  for (size_t i = 0; i < arcs.size(); i++)
  {
    auto [parent, direction, child] = arcs[i];
    if (parent >= n || child >= n)
      throw std::invalid_argument("arcs indexes must be lower than n="
                                  + std::to_string(n));

    if (direction == Direction::Left)
      nodes[parent]->left = nodes[child];
    else  //(direction==Direction::Right)
      nodes[parent]->right = nodes[child];
  }
  return nodes[0];
}

template <typename T, typename Fn>
void visit_in_order(Node<T>* root, Fn fn)
{
  if (!root)
    return;
  visit_in_order(root->left, fn);
  fn(root->val);
  visit_in_order(root->right, fn);
}

}  // namespace BinaryTree
}  // namespace Book

#endif  // BOOK__LIST