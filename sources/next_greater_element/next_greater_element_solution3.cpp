std::vector<int> 
next_greater_element_I_stack(const std::vector<int>& A,
                           const std::vector<int>& B)
{
  std::vector<int> C(A.size());
  std::stack<int> stack;
   std::unordered_map<int, int> C_val;

  for(int i = std::ssize(B)-1 ; i >=0 ; i--)
  {
      while(!stack.empty() && B[i] > stack.top())
      {
          stack.pop(); //remove smaller elements than *it
      }
      //now the stack is either empty or contains an increasing sequence
      if(!stack.empty())
        C_val[B[i]] = stack.top();
      stack.push(B[i]);
  }
  for (int i = 0; i < std::ssize(A); i++)
  {
    if(C_val.contains(A[i]))
        C[i] = C_val[A[i]];
    else
        C[i] = -1;
  }
  return C;
}