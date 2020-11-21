template <typename T>
Node<T> *clone_random_list_map(Node<T> *head)
{
  // empty list case
  if (!head)
    return nullptr;

  Node<T> *ans = nullptr;
  std::unordered_map<Node<T> *, int> P;
  std::vector<Node<T> *> ptrs;

  Node<T> *t = head;
  int idx    = 0;
  while (t)
  {
    Node<T> *n = new Node<T>(t->val);
    ptrs.push_back(n);
    if (!ans)
      ans = n;
    // remember the index of this node t
    P[t] = idx;
    t    = t->next;
    idx++;
  }

  // connect the copy list forward
  for (int i = 0; i < ptrs.size() - 1; i++)
    ptrs[i]->next = ptrs[i + 1];

  t   = head;
  idx = 0;
  while (t)
  {
    // which index does t->random has in the original list?
    // connect the current node with the P[t->random]-th node in the copy list
    Node<T> *rnd = P.find(t->random) != P.end() ? ptrs[P[t->random]] : nullptr;
    ptrs[idx]->random = rnd;
    idx++;
    t = t->next;
  }
  return ans;
}