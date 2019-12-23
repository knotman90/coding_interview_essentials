void power_set_backtracking_helper(const std::vector<int>& S, const int idx, std::vector<int>& curr, std::vector<std::vector<int>>& ans)
{
    if(idx>= S.size())
//base case
    {
        ans.push_back(curr);
        return;
    }
    
    //include element S[idx]
    curr.push_back(S[idx]);
    power_set_backtracking_helper(S, idx+1, curr, ans);   
    
    //exclude element S[idx]
    curr.pop_back();
    power_set_backtracking_helper(S, idx+1, curr, ans);
}

std::vector<std::vector<int>> power_set_backtracking(const std::vector<int>& S)
{
    std::vector<std::vector<int>> ans;
    std::vector<int> current;
    power_set_backtracking_helper(S,0, current, ans);    
    return ans;
}