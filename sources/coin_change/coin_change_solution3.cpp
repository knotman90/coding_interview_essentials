int change_ways_bruteforce_backtracking_helper(
    const std::vector<int>& I,
    const int t,
    const size_t j, /*current denomination*/
    const int coin_used /*number of coin in X*/)
{
    std::cout<<t<<" "<<j<<" "<<coin_used<<endl;
  if (t==0)
    return coin_used;

  if ( t < 0 || j >= I.size())
    return std::numeric_limits<int>::max();

  int ans = std::numeric_limits<int>::max();
  for (int k = 0, new_t = t; new_t >= 0;
       k++, new_t   = t- (I[j] * k))
  {
    ans = std::min(ans,
                   change_ways_bruteforce_backtracking_helper(
                        I, new_t, j + 1, coin_used + k));
  }
  return ans;
}

int change_ways_bruteforce(const std::vector<int>& I,const int t )
{
  return change_ways_bruteforce_backtracking_helper(I,t, 0,0); 
}