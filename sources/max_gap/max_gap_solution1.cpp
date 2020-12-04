int max_gap_bruteforce(const std::vector<int>& I)
{
    auto I_copy(I);
    std::ranges::sort(I_copy);
    
    int ans = std::numeric_limits<int>::min();
    for(int i = 0 ; i < std::ssize(I)-1; i++)
    {
        ans = std::max(ans, I_copy[i+1]-I_copy[i]);
    }
    return ans;
}