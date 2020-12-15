int list_length(ListNode* head)
{
  int ans = 0;
  while (head)
  {
    ans++;
    head = head->next;
  }
  return ans;
}

ListNode* remove_nth_node_from_end_bruteforce(ListNode* head, int n)
{
  const int length = list_length(head);
  // we can assume it is always valid/positive

  ListNode *prec = nullptr, *curr = head;

  int index = length - n - 1;
  while (index--)
  {
    prec = curr;
    curr = curr->next;
  }

  ListNode* next = curr->next;
  ListNode* ans  = head;
  if (!prec)
    ans = next;  // we are removing the first node
  else
    prec->next = next;

  return ans;
}