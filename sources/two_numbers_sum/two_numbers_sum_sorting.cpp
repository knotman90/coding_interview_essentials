bool two_numers_sum_sorting(vector<int>& A, const int T)
{
	sort(begin(A), end(A));
    const size_t size = A.size();
    for(int i = 0 ; i < size -1; i++)
        if( std::binary_search(begin(A)+i+1, end(A), A[i]-T) )
                return true;
    return false;
}