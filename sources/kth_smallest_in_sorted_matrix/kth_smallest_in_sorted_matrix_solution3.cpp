using Matrix = std::vector<std::vector<int>>;
auto count_less_or_equal(const Matrix& M,
                         const int mid)
{
  const int sizei = M.size();
  const int sizej = M[0].size();
  int count_less_mid = 0;
  int j              = sizej - 1;
  for (int i = 0; i < sizei; i++)
  {
    while (j >= 0 && M[i][j] > mid)
    {
      j--;
    }
    count_less_mid += j + 1;
  }
  return count_less_mid;
}

int kth_smallest_in_sorted_matrix_nlogn(const Matrix& M, const size_t k)
{

  int l           = M[0][0];                  // smallest element
  int r           = M.back().back();  // largest
  while (l < r)
  {
    const int mid      = l + (r - l) / 2;
    if (const int count_less_mid = count_less_or_equal(M, mid); count_less_mid < k)
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