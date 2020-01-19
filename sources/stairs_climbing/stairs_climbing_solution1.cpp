/*int fibonacci(int k)
{
        int p = 0, c = 1;
        while(k--)
        {
                const int tmp = c;
                c = p+tmp;
                p = tmp;
        }
        return p;
}*/

int fibonacci(int k) {
  if (k <= 1)
    return 1;
  return fibonacci(k - 1) + fibonacci(k - 2);
}

int stair_climbing_fibonacci(const int n) {
  if (n <= 1)
    return n;
  return fibonacci(n);
}