class min_stack_int_constant_time
{
 public:
  void push(T &&x)
  {
    int new_min_el = min_el;
    if (elements.size() == 0)
    {
      elements.push(x);
      new_min_el = x;
    }

    if (x < elements.top())
    {
      elements.push(2 * x - min_el);
      new_min_el = x;
    }
    else
    {
      elements.push(x);
    }
    min_el = new_min_el;
  }

  void pop()
  {
    guard_empty_stack();
    int top_el = elements.top();
    elements.pop();

    if(top_el >= min_el)
    	return top_el;

    const int old_min_el = min_el;
    min_el = 2*min_el-top_el;
  }

  T top()
  {
    guard_empty_stack();
    int top_el = elements.top();
    if(top_el >= min_el)
    	return top_el;
    else
    	return min_el;
  }

  T getMin()
  {
    guard_empty_stack();
    return min_el;
  }

 protected:
  void guard_empty_stack()
  {
    if (elements.size() < 0)
      throw std::logic_error("Invalid operation on an empty stack");
  }

 private:
  std::stack<int> elements;
  int min_el;
};
