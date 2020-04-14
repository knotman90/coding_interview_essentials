int find_majority_element_hash_map(const std::vector<int>& N)
{
  const size_t threshold = N.size() / 2;
  
  std::unordered_map<int,int> C;
  std::pair<int,int> max_val = {0,0};
  for (const auto x : N)
  {
    int& countx = C[x];
    countx++;
    if (countx > threshold)
      return x;
  }
  return -1;
}