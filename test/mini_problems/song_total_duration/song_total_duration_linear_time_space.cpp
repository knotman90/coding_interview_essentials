int numPairsDivisibleBy60(const vector<int>& T, const int k) 
{
    std::vector<int> mod_counters(k,0);
    int ans = 0;
    for(const auto time : T)
    {
        const int m = time%k;
        const int r = (k-m)%k;
        ans+=mod_counters[r];
        mod_counters[m]++;
    }
    return ans;
    
}