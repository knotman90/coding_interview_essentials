int max_sum_contiguous_subarray_kadane(const std::vector<int> &A) 
{
    std::vector<int>B(A.size(),std::numeric_limits<int>::min());
    
    B[0] = A[0];
    for(int i = 1 ; i < A.size() ; i++)
        B[i] = std::max(A[i] , B[i-1]+A[i]);
    
    return *max_element(begin(B), end(B));
}

