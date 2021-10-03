template<typename T>
struct NodeWrapper{
    Node<T>* ptr{nullptr};
    size_t list_idx{};
};

template<typename T>
bool compareNodeWrapper(const NodeWrapper<T>& node1, const NodeWrapper<T>& node2){
    assert(node1.node && node2.node);
    return node1.ptr->val < node2.ptr->val;
}

Node<int>* merge_k_sorted_list_priority_queue(std::vector<Node<int>*> lists)
{
  if (lists.empty())
    return nullptr;
  if (lists.size() <= 1)
    return lists.front();

    std::priority_queue<NodeWrapper<int>, std::vector<NodeWrapper<int>>, decltype(compareNodeWrapper<NodeWrapper<int>>)> queue;



  Node<int>* ans = lists.front();
  for (size_t i = 1; i < lists.size(); i++)
  {
    ans = insert_sorted(ans, lists[i]);  // insert list nodes into ans
  }

  return ans;
}