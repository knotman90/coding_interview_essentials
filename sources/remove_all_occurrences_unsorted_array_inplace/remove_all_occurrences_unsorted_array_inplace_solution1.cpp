int removeElement(int* A, int n1, int B)
{
  size_t x = 0;
  while (A[x] != B && x < n1)
    x++;
  size_t y = x + 1;
  while (y < n1)
  {
    if (A[y] != B)
    {
      A[x] = A[y];
      x++;
    }
    y++;
  }
  return x;
}
