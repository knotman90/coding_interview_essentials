ListNode *remove_nth_node_from_end_two_pointers(ListNode *head, int n)
{
  if (n == 0)
    return head;
  ListNode *s, *f, *p = nullptr;
  s = f = head;

  // advance s n times
  while (n)
  {
    s = s->next;
    n--;
  }

  // now s is at a distance of l-n  from the tail
  while (s)
  {
    ListNode *oldf = f;
    f              = f->next;
    s              = s->next;
    p              = oldf;
  }
  // f points to the node l-n of the list

  ListNode *next = f ? f->next : nullptr;
  if (!p)
  {
    head = next;
  }
  else
  {
    p->next = next;
  }

  return head;
}