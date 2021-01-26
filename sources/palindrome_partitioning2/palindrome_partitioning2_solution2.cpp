using Cache = std::unordered_map<int,int>;

int palindrome_partitioning2_DP_topdown_helper(const std::string s, const int start_idx, Cache& memoization_cache)
{
	if(start_idx >= std::ssize(s) || is_palindrome(s,start_idx, std::ssize(s)-1) )
		return 0;
	
	if(memoization_cache.contains(start_idx))
		return memoization_cache[start_idx];

	int ans = std::numeric_limits<int>::max();
	for(int i = start_idx ; i < std::ssize(s) ; i++)
	{
		if(is_palindrome(s,start_idx, i))
			ans = std::min(ans, 1 + palindrome_partitioning2_DP_topdown_helper(s,i+1,memoization_cache));
	}
	
	assert(ans <= std::ssize(s)-start_idx);
	memoization_cache[start_idx] = ans;
	return ans;	
}

size_t palindrome_partitioning2_DP_topdown(const std::string s)
{
	Cache memoization_cache;
	return palindrome_partitioning2_DP_topdown_helper(s,0, memoization_cache);
}