template<typename It, typename Cmp_fn>
bool is_valid_wave_array(It begin, It end, Cmp_fn fn = std::greater<int>())
{
  It curr = begin;
  while(curr != end){
    
    if(const It prev = curr-1; prev >= begin && !cmp_fn(curr, prev))
      return false;
    
    if(const It next = curr+1; next < end && !cmp_fn(curr, next))
      return false;
  }
  return true;
}

std::vector<int> wave_brute_force(const std::vector<int> &A)
{
  std::vector<int> B(A);
  std::sort(begin(B), end(B));
  
  do {
    if(is_valid_wave_array(B.begin(), B.end(), std::greater<int>()) || 
      is_valid_wave_array(B.begin(), B.end(), std::less<int>()) )
      return B;
  } while ( std::next_permutation(B.begin(),B.end()) );
  
  throw std::runtime_error("Should never happen");
}
