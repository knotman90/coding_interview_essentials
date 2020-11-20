<<<<<<< HEAD
double mediam_sorted_arrays_log(const std::vector<int> &A,
                                const std::vector<int> &B)
{
  int l = 0, r = A.size() - 1;
  const int size      = A.size() + B.size();
  const int half_size = size / 2;

  while (l <= r)
  {
    const int i = l + (r - l) / 2 + 1;
    const int j = half_size - mid;

=======
size_t midpoint(const size_t l, const size_t r)
{
  assert( l <= r );
  return l + (r-l)/2;
}
double mediam_sorted_arrays_binary_search(
        const std::vector<int> &A,
                               const std::vector<int> &B)
{
  
  size_t l = 0, r = A.size() - 1;
  const size_t size_C      = A.size() + B.size();
  const size_t half_size_C = size_C / 2;

  auto median = 0.0;
  while (l <= r)
  {
    const size_t i = midpoint(l,r);
    const size_t j = half_size_C - i;
/*
>>>>>>> db9e6004377e57e406836e62f8d6a33353a91bb2
    const int idx_i = i - 1;
    const int idx_j = j - 1;
    if (A[i - 1] <= B[j] && B[j - 1] <= A[i])
      if (size % 2 == 0)
        return (std::max(A[i - 1], B[j - 1]) + std::min(A[i], B[j])) / 2.0;
      else
        return std::max(A[i - 1], B[j - 1]);

    if (A[i - 1] > B[j])
      r = i - 1;
    else
<<<<<<< HEAD
      l = i - 1;
  }
=======
      l = i - 1;*/
  }
  return median;
>>>>>>> db9e6004377e57e406836e62f8d6a33353a91bb2
}