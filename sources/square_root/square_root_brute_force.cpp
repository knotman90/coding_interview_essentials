int square_root_brute_force(const int n)
{
  long i = 0;
  while ((i * i) <= n)
    i++;
  //i at this point is the smallest element s.t. i*i > n
  return i - 1;
}