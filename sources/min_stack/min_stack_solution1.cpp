template <class T>
class min_stack_stack_pair
{
 public:
  void push(const T& x)
  {
    const auto nm = q.size() > 0 ? std::min(x, getMin()) : x;
    q.push({ x, nm });
  }

  void pop()
  {
    guard_empty_stack();
    q.pop();
  }

  T top()
  {
    guard_empty_stack();
    return q.top().first;
  }

  T getMin()
  {
    guard_empty_stack();
    return q.top().second;
  }

 protected:
  void guard_empty_stack()
  {
    if (q.size() < 0)
      throw std::logic_error("Invalid operation on an empty stack");
  }

 private:
  std::stack<std::pair<T, T>> q;
};