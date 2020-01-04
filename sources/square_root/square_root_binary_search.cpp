int square_root_binary_search(const int A) {
  long l = 0, r = A;
  int ans = 0;
  while (l <= r) {
    const long long mid = l + (r - l) / 2;
    if ((long)(mid * mid) == (long)A)
      return mid;
    if (mid * mid > A) {
      r = mid - 1;
    } else {
      l = mid + 1;
      ans = mid;
    }
  }
  return ans;
}