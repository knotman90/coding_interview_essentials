template <typename T>
struct NodeWrapper
{
  Node<T>* ptr{nullptr};
  size_t list_idx{};
};

Node<int>* merge_k_sorted_list_priority_queue(std::vector<Node<int>*> lists)
{
  if (lists.empty())
    return nullptr;
  if (lists.size() <= 1)
    return lists.front();

  auto compareNodeWrapper = [](const NodeWrapper<int>& node1,
                               const NodeWrapper<int>& node2) {
    assert(node1.ptr && node2.ptr);
    return node1.ptr->val > node2.ptr->val;
  };

  std::priority_queue<NodeWrapper<int>,
                      std::vector<NodeWrapper<int>>,
                      decltype(compareNodeWrapper)>
      queue(compareNodeWrapper);

  std::vector<Node<int>*> lists_pointers(lists.size(), nullptr);
  for (size_t i = 0; i < lists.size(); i++)
  {
    lists_pointers[i] = lists[i];
    if (lists_pointers[i])
      queue.push(NodeWrapper<int>{lists[i], i});
  }

  Node<int>* ans_current = nullptr;
  Node<int>* ans_head    = nullptr;
  while (!queue.empty())
  {
    auto [ptr, idx] = queue.top();
    queue.pop();

    if (ans_current)
    {
      ans_current->next = ptr;
    }
    else
    {
      ans_head = ptr;
    }
    ans_current = ptr;
    if (lists_pointers[idx]->next)
    {
      lists_pointers[idx] = lists_pointers[idx]->next;
      queue.push(NodeWrapper<int>{lists_pointers[idx], idx});
    }
  }
  return ans_head;
}