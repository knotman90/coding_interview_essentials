vector<vector<int>> power_set_1(const vector<int>& A)
{
    const size_t limit = (1ll<<A.size())-1;    
    vector<vector<int>> PS;
    PS.push_back({});
    for(const auto a : A)
    {
        vector<vector<int>> PS1(PS);
        for(auto& s : PS1)
        {
            s.push_back(a);
            PS.push_back(s);
        }
    }
    return PS;    
}