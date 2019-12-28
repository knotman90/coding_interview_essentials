int maxSubArray(const std::vector<int> &A) 
{
    std::vector<int>B(A.size(),-10001);
    B[0] = A[0];
    int ans = B[0];
    for(int i = 1 ; i < A.size() ; i++)
    {
        B[i] = std::max(A[i] , B[i-1]+A[i]);
        ans = std::max(ans, B[i]);
    }
    return ans;
}