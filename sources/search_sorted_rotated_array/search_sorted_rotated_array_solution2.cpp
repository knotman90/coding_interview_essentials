using Range = std::pair<int, int>;
inline unsigned midpoint(const unsigned l, const unsigned r)
{
  return l + (r - l) / 2;
}

inline int positive_modulo(const int n, const int m)
{
  return (n + m) % m;
}

int find_idx_min(const vector<int>& A)
{
  const int size = A.size();
  int l          = 0;
  int r          = A.size() - 1;
  if (A[l] < A[r])
    return l;
  while (l <= r)
  {
    const int mid = midpoint(l, r);

    const int curr = A[mid];
    const int next = A[positive_modulo(mid + 1, size)];
    const int prec = A[positive_modulo(mid - 1, size)];

    if (curr <= next && curr <= prec)
      return mid;
    if (curr < A[0])
      r = mid - 1;
    else
      l = mid + 1;
  }
  return l;
}

int binary_search(const std::vector<int>& A, const Range& range, const int t)
{
  auto [l, r] = range;
  if (l > r)
    return -1;

  const int mid = midpoint(l, r);
  if (A[mid] == t)
    return mid;

  if (A[mid] < t)
    l = mid + 1;
  else
    r = mid - 1;

  return binary_search(A, {l, r}, t);
}

int search_sorted_rotated_array_log(const vector<int>& A, int t)
{
  if (A.size() == 0)
    return -1;
  const int idx = find_idx_min(A);

  int ans = binary_search(A, Range(0, idx - 1), t);
  if (ans == -1)
    ans = binary_search(A, Range(idx, A.size() - 1), t);
  return ans;
}
