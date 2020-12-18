

int palindrome_partitioning2_DP_bottomup(const std::string s)
{
  std::vector<int> DP(s.size()+1, s.size()-1);
  DP[s.size()-1] =  DP[s.size()] = 0;
  for(int idx_start = std::ssize(s)-2 ; idx_start >=0 ; idx_start--)
  {
      if(is_palindrome(s, idx_start, s.size()-1) ){
        DP[idx_start] = 0;
        continue;
      }
      for(int idx_end = idx_start ; idx_end < std::ssize(s) ; idx_end++){
          if(is_palindrome(s, idx_start, idx_end)){
              const auto cost_partition_rest = idx_end < std::ssize(s)-1 ? DP[idx_end+1] : 0;
              DP[idx_start] = std::min(DP[idx_start], 1 + cost_partition_rest);
          }
      }
  }
  return DP[0];
}