#include "PalindromeSubstringCacheIterative.h"


size_t palindrome_partitioning2_DP_topdown_optimized_helper_it(const PalindromeSubstringCacheIterative& B,
const size_t start_idx, Cache& memoization_cache)
{
  const auto size =  B.size();
	if(start_idx >= size || B.is_palindrome(start_idx, size-1) )
		return 0;
	
	if(memoization_cache.contains(start_idx))
		return memoization_cache[start_idx];

  //cout<<start_idx<<std::endl;
	size_t ans = std::numeric_limits<int>::max();
	for(size_t i = start_idx ; i < size ; i++)
	{
		if(B.is_palindrome(start_idx, i)) //O(1)
			ans = std::min(ans, 1 + palindrome_partitioning2_DP_topdown_optimized_helper_it(B,i+1,memoization_cache));
	}
	
	assert(ans <= size - start_idx);
	memoization_cache[start_idx] = ans;
	return ans;	
}


size_t palindrome_partitioning2_DP_topdown_optimized_it(const std::string s)
{
    PalindromeSubstringCacheIterative B(s);
	  Cache memoization_cache;
	  return palindrome_partitioning2_DP_topdown_optimized_helper_it(B,0u, memoization_cache);
}
