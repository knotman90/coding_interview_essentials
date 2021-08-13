struct Bucket
{
  bool used  = false;
  int minval = std::numeric_limits<int>::max();
  int maxval = std::numeric_limits<int>::min();
};

int max_gap_buckets(const std::vector<int>& I)
{
  if (I.size() < 2)
    return 0;

  const auto [minEl, maxEl] = [&I]() {
    const auto p = std::minmax_element(I.begin(), I.end());
    return std::make_tuple(*p.first, *p.second);
  }();

  const int t = std::max(
      1l, (maxEl - minEl) / (std::ssize(I) - 1));  // bucket size or capacity
  const size_t num_buckets = ((maxEl - minEl) / t) + 1;  // number of buckets
  std::vector<Bucket> buckets(num_buckets);

  for (const auto& el : I)
  {
    const size_t bucketIdx  = (el - minEl) / t;  // bucket idx for this element
    buckets[bucketIdx].used = true;
    buckets[bucketIdx].minval = std::min(el, buckets[bucketIdx].minval);
    buckets[bucketIdx].maxval = std::max(el, buckets[bucketIdx].maxval);
  }

  int prevBucketMax = minEl, ans = 0;
  for (auto&& bucket : buckets)
  {
    if (!bucket.used)  // skip empty buckets
      continue;

    ans           = std::max(ans, bucket.minval - prevBucketMax);
    prevBucketMax = bucket.maxval;
  }

  return ans;
}