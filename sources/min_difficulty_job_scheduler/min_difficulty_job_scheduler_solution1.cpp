class Solution {
public:
using Key = std::tuple<int,int>;
    struct KeyHash {
    std::size_t operator()(const Key & key) const
    {
        return std::get<0>(key) ^ std::get<1>(key);
    }
};

    std::unordered_map<Key,int,KeyHash> DP;
    
    long min_difficulty_helper(const std::vector<int>& A, const size_t start, const int d)
    {
        if(start >= A.size() && d==0)
            return 0;
        
        const size_t remaining = A.size()-start;
        if(remaining < d)
            return std::numeric_limits<int>::max();
        
        auto t = std::make_tuple(start, d);
        
        if(DP.find(t) != DP.end())
            return DP[t];
        
        int M = A[start];
        long ans = std::numeric_limits<int>::max();
        for(int i = start ; i < A.size() ; i++)
        {
            M = std::max(M, A[i]);
            ans = min(ans, M + min_difficulty_helper(A,i+1,d-1));
        }
        DP[t] = ans;
        return ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        auto ans =  min_difficulty_helper(jobDifficulty, 0, d);
        if(ans >= std::numeric_limits<int>::max() )
            return -1;
        return ans;
    }
};