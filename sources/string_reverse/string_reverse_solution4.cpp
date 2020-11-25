void reverse_string_inplace_recursive_helper(std::string &s,
                                             const int k,
                                             const int l)
{
  if (k >= l)
    return;

  swap(s[k], s[l]);
  reverse_string_inplace_recursive_helper(s, k + 1, l - 1);
}

void reverse_string_inplace_recursive(std::string &s)
{
  reverse_string_inplace_recursive_helper(s, 0, s.size() - 1);
}