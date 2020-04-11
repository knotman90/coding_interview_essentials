template <typename T>
std::vector<T> to_vector(Node<T> *head)
{
  std::vector<T> ans;
  for (; head; head = head->next)
    ans.push_back(head->val);

  return ans;
}

template <typename T>
Node<T> *from_vector(const std::vector<T> &Vs)
{
  Node<T> *tail = nullptr;
  Node<T> *head = nullptr;
  for (const auto v : Vs)
  {
    Node<T> *n = new Node<T>(v);
    if (!tail)
      head = n;
    else
      tail->next = n;
    tail = n;
  }
  return head;
}

template <typename T>
Node<T> *remove_duplicates_from_linked_list_1(Node<T> *head)
{
  auto vec_list = to_vector<int>(head);
  // std::sort(std::begin(vec_list), std::end(vec_list)); //not necessary. List is sorted already
  vec_list.erase(std::unique(std::begin(vec_list), std::end(vec_list)), std::end(vec_list));

  return from_vector(vec_list);
}
