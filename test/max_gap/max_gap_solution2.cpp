void count_sort(vector<int>& I, const unsigned base, const unsigned digit_idx)
{
  std::vector<std::vector<int>> counters(base);
  for (const auto& el : I)
  {
    // get the digit_idx th digit
    const auto digit_value = el / (int)(std::pow(base, digit_idx)) % base;
    // add this number to the corrensponding bucket
    counters[digit_value].push_back(el);
  }

  int pos = 0;
  for (const auto& list : counters)
  {
    for (const auto& num : list)
    {
      I[pos++] = num;
    }
  }
}

void radix_sort(vector<int>& I,
                const unsigned base       = 10,
                const unsigned num_digits = 10)
{
  for (unsigned digit = 0; digit < num_digits; digit++)
    count_sort(I, base, digit);
}

int max_gap_radix_sort(const std::vector<int>& I)
{
  auto I_copy(I);
  radix_sort(I_copy);

  int ans = std::numeric_limits<int>::min();
  for (int i = 0; i < std::ssize(I) - 1; i++)
  {
    ans = std::max(ans, I_copy[i + 1] - I_copy[i]);
  }
  return ans;
}