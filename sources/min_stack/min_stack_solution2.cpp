template <class T> 
class min_stack_two_stacks
{
    public:
  void push(T &&x)
  {
    if (x <= getMin() || minimums.size() == 0)
      minimums.push(x);
    elements.push(x);
  }

  void pop()
  {
    guard_empty_stack();
    if (getMin() == elements.top())
      minimums.pop();
    elements.pop();
  }

  T top()
  {
    guard_empty_stack();
    return elements.top();
  }

  T getMin()
  {
    guard_empty_stack();
    return minimums.top();
  }

    protected:
  void guard_empty_stack()
  {
    if (elements.size() < 0)
      throw std::logic_error("Invalid operation on an empty stack");
  }

    private:
  std::stack<int> elements;
  std::stack<int> minimums;
};
