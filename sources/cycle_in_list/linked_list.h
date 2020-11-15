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