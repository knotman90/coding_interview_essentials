template <typename T>
Node<T> *remove_duplicates_from_linked_list_linear_space(Node<T> *head)
{
  if (!head || !head->next)
    return head;

  Node<T> *head_n = head->next;

  while (head && head_n && head->val == head_n->val)
  {
    const auto head_n_n = head_n->next;
    delete head_n;
    head_n = head_n_n;
  }

  head->next = remove_duplicates_from_linked_list_linear_space(head_n);
  return head;
}
