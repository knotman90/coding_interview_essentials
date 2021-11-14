
Node<int>* insert_sorted(Node<int>* sinkList, Node<int>* toBeInserted)
{
  Node<int>* ans = sinkList;  // head of the merged list
  if (!sinkList)
  {
    sinkList = toBeInserted;
    return ans;
  }

  Node<int>* lastNodeSinkList = nullptr;
  Node<int>* sinkListPrec     = nullptr;
  while (sinkList && toBeInserted)
  {
    lastNodeSinkList = sinkList;  // remember the last node of the sinkList

    if (sinkList->val <= toBeInserted->val)
    {
      sinkListPrec = sinkList;
      sinkList     = sinkList->next;
      continue;
    }

    Node<int>* const toBeInsertedNext = toBeInserted->next;
    toBeInserted->next                = sinkList;
    if (sinkListPrec)
    {
      sinkListPrec->next = toBeInserted;
      // We inserted a value before sinkList. We need to update the prec pointer
      sinkListPrec = toBeInserted;
    }
    else
    {
      // inserting at the front of sinkList.
      ans          = toBeInserted;
      sinkListPrec = ans;
    }
    toBeInserted = toBeInsertedNext;
  }  // while

  // attach the remaining part of toBeinserted list to the end of the sinkList
  if (toBeInserted)
  {
    lastNodeSinkList->next = toBeInserted;
  }
  return ans;
}

Node<int>* merge_k_sorted_list_brute_force(std::vector<Node<int>*> lists)
{
  if (lists.empty())
    return nullptr;
  if (lists.size() <= 1)
    return lists.front();

  Node<int>* ans = lists.front();
  for (size_t i = 1; i < lists.size(); i++)
  {
    ans = insert_sorted(ans, lists[i]);  // insert list nodes into ans
  }

  return ans;
}