template <typename T>
Node<T>* list_reverse_linear_space(Node<T>* L)
{
  if (!L)
    return nullptr;

  std::stack<Node<T>*> nodes;
  Node<T>* it = L;
  while (it)
  {
    nodes.push(it);
    it = it->next;
  }

  Node<T>* new_head = nodes.top();
  nodes.pop();

  it = new_head;
  while (!nodes.empty())
  {
    const auto it_next = nodes.top();
    nodes.pop();
    it->next = it_next;
    it       = it_next;
  }
  it->next = nullptr;
  return new_head;
}