template <typename T>
Node<T>* list_reverse_constant_space_iterative(Node<T>* L)
{
  if (!L || !(L->next))
    return L;

  auto curr  = L;
  auto next  = curr->next;
  curr->next = nullptr;
  while (curr && next)
  {
    auto temp  = next->next;
    next->next = curr;
    curr       = next;
    next       = temp;
  }
  return curr;
}