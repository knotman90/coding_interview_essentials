#include "generate_combinations.h"

/**
 * Returns
 * 	 true iff the substring of s starting at start and ending at end is
 * palindrome false otherwise.
 * */
bool is_palindrome(const std::string& s, const size_t start, const size_t end)
{
  assert(start <= end);
  assert(end < s.length());

  auto l = start, r = end;
  while (l < r)
    if (s[l++] != s[r--])
      return false;
  return true;
}

int palindrome_partitioning2_bruteforce(const std::string s)
{
  if (is_palindrome(s, 0, s.size() - 1))
    return 0;

  for (int k = 1; k <= std::ssize(s) - 1; k++)
  {
    // generate combinations in groups of k from [0...s.size()-2]
    const auto& cutpoints = all_combinations(k, s.size());
    // is there a partition of size k such that all the associated substrings in
    // s are palindrome?
    const auto found = std::any_of(
        std::begin(cutpoints), std::end(cutpoints), [&](const auto& combo) {
          auto substring_start = 0;
          for (const auto substring_end : combo)
          {
            if (!is_palindrome(s, substring_start, substring_end))
              return false;
            substring_start = substring_end + 1;
          }
          return is_palindrome(s, substring_start, s.size() - 1);
        });
    if (found)
      return k;
  }
  return s.size() - 1;
}