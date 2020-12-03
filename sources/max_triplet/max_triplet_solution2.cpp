
constexpr auto MIN_INT = std::numeric_limits<int>::min();
auto find_largest_smaller_than(const std::set<int>& N, const int n)
{
    auto it =N.lower_bound( n);
    if(N.size() == 0 || it==std::begin(N))
        return std::make_tuple(MIN_INT, false);
    return std::make_tuple(*(--it), true);
}

int max_triplet_sum_prefix_binary_search(const vector<int> &A) {
    std::set<int> N;    
    std::vector<int> L;
    
    L.resize(A.size(), MIN_INT);
    int m = A[A.size()-1];
    for(int i = A.size()-2 ; i >=0 ; i--)
    {
        L[i] = A[i] < m ? m : MIN_INT;
        m = std::max(A[i], m);
    }
    
    int ans = -1;
    for(int i = 0 ; i < A.size(); i++)
    {
        auto larger = L[i];
        auto [smaller, exists] = find_largest_smaller_than(N,A[i]);
        if(larger != MIN_INT && exists)
            ans = std::max(ans, A[i]+larger +smaller);
        N.insert(A[i]);
    }
    return ans;
    
}