void power_set_backtracking_helper(const vector<int>& S, const int idx, vector<int>& curr, vector<vector<int>>& ans)
{
    if(idx>= S.size())//base case
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

vector<vector<int>> power_set_backtracking(const vector<int>& S)
{
    vector<vector<int>> ans;
    vector<int> current;
    power_set_backtracking_helper(S,0, current, ans);    
    return ans;
}