int odd_appearing_element_final(const std::vector<int> &A)
{
  int ans = 0; //0 is the neutral element for XOR
  for (const int x : A)
    ans ^= x;
  return ans;
}