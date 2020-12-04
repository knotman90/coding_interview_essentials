template <typename T>
Node<T>* list_reverse_constant_space_iterative(Node<T>* L)
{
  if (!L || !(L->next))
    return L;

  auto curr  = L;
  auto curr_next  = curr->next;
  curr->next = nullptr; //the first node is the new tail
  while (curr && curr_next)
  {
    auto temp  = curr_next->next; //needed to move forward curr_next
    curr_next->next = curr;
    curr       = curr_next;
    curr_next  = temp;
  }
  return curr;
}