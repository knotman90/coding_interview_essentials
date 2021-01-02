int remove_elements_unsorted_array(std::vector<int>& A, auto predicate)
{
  size_t x        = 0;
  const auto size = A.size();
  while (!predicate(A[x]) && x < size)
    x++;
  size_t y = x + 1;
  while (y < size)
  {
    if (!predicate(A[y]))
    {
      A[x] = A[y];
      x++;
    }
    y++;
  }
  return x;
}
