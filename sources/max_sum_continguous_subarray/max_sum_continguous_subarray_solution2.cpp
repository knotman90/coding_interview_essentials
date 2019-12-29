int max_sum_contiguous_subarray_bruteforce(const std::vector<int> &A) 
{
	int ans = std::numeric_limits<int>::min();
    for(int i = 0 ; i < A.size() ; i++)
    {
    	for(int j = i ; j < A.size(); j++){
    		const int subarray_sum = std::accumulate(begin(A)+i, end(A)+j,0);
    		ans = std::max(ans, subarray_sum);
    	}
    }
    return ans;
}