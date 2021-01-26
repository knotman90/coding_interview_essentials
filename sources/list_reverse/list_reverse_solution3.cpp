template <typename T>
Node<T>* list_reverse_recursive(Node<T>* L)
{
  if (!L || !(L->next))
    return L;

  auto reverse_next_head = list_reverse_recursive(L->next);
  L->next->next          = L;
  L->next                = nullptr;
  return reverse_next_head;
}