#ifndef BOOK__LIST
#define BOOK__LIST

namespace Book
{
namespace List
{
template <typename T>
struct Node
{
  T val;
  Node *next;
  Node() = default;
  Node(T x) : val(x), next(nullptr)
  {
  }
};

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
int length(Node<T> *head)
{
  int ans = 0;
  while (head)
  {
    ans++;
    head = head->next;
  }
  return ans;
}
}  // namespace List
}  // namespace Test


#endif  // BOOK__LIST