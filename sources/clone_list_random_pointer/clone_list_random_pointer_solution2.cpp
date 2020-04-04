template<typename T>
Node<T> *interleave_list(Node<T> *head)
{
  Node<T> *h = head;
  while (h)
  {
    Node<T> *next   = h->next;
    Node<T> *h_copy = new Node<T>(h->val);

    h_copy->next = next;
    h->next      = h_copy;
    h            = next;
  }
  return head;
}

template<typename T>
void fix_random_pointers(Node<T> *head)
{
  Node<T> *o = head;
  while (o)
  {
    Node<T> *c = o->next;
    if (o->random)
    {
      Node<T> *pointed   = o->random;
      Node<T> *pointed_c = pointed->next;
      c->random       = pointed_c;
    }
    o = o->next->next;
  }
}

template<typename T>
Node<T> *split_list(Node<T> *head)
{
  Node<T> *o   = head;
  Node<T> *ans = head->next;
  while (o)
  {
    Node<T> *c     = o->next;
    Node<T> *cnext = c->next;

    o->next = c->next;
    if (c->next)
      c->next = c->next->next;
    o = cnext;
  }
  return ans;
}

template<typename T>
Node<T> *clone_random_list_interleave_lists(Node<T> *head)
{
  if (!head)
    return nullptr;

  interleave_list(head);
  fix_random_pointers(head);
  return split_list(head);
}