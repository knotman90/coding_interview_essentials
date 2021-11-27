using Matrix = std::vector<std::vector<int>>;
int kth_smallest_in_sorted_matrix_nlogn(const Matrix& M, const size_t k)
{
  const int sizei = M.size();
  const int sizej = M[0].size();
  int l           = M[0][0];                  // smallest element
  int r           = M[sizei - 1][sizej - 1];  // largest
  while (l < r)
  {
    const int mid      = l + (r - l) / 2;
    int j              = sizej - 1;
    int count_less_mid = 0;
    for (int i = 0; i < sizei; i++)
    {
      while (j >= 0 && M[i][j] > mid)
      {
        j--;
      }
      count_less_mid += j + 1;
    }
    if (count_less_mid < k)
    {
      l = mid + 1;
    }
    else
    {
      r = mid;
    }
  }
  return l;
}