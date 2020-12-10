
void sort_subarrays(auto begin, auto end, std::vector<int>& subarrays)
{
  auto it = begin;
  for(const auto n : subarrays)
  {
    auto itn = begin+n+1;
    std::sort(it, itn);
    it = itn;
  }
  std::sort(it, end);
}

bool check_all_k_combinations(const std::vector<int>& I, const int offset, const int k, std::vector<int> combination) {
  if (k == 0) {
    auto I_copy(I);
    sort_subarrays(std::begin(I_copy), std::end(I_copy),combination);
    return std::ranges::is_sorted(I_copy);
  }

 
  for (int i = offset; i < I.size() - k; ++i) {
    combination.push_back(i);
    if(check_all_k_combinations(I,i+1, k-1, combination))
      return true;
    combination.pop_back();
  }
  return false;
}


int maxChunksToSorted_bruteforce(const std::vector<int>& I)
{
    for(int k = std::ssize(I); k >= 2  ; k--)
    {
      std::vector<int> splitting_points{};
      if(check_all_k_combinations(I,0,k-1,splitting_points) ){
        return k;
      }
    }
    return 1;
}