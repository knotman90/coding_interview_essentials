template <typename T>
Node<T> *detect_cycle_constant_time(Node<T> *head)
{
  Node<T> *n1, *n2;
  n1 = n2 = head;

  while (n1 && n2)
  {
    n1 = n1->next;
    n2 = n2->next;
    if (n2)
      n2 = n2->next;
    else
      break;

    if (n1 == n2)
      break;
  }
  // second phase floys's algorithm
  if (n1 == n2)
  {
    n2 = head;
    while (n1 != n2)
    {
      n1 = n1->next;
      n2 = n2->next;
    }
    return n1;
  }
  return nullptr;
}