bool all_unique(const string& s)
{
    unordered_set<char> L;
    for(int i = 0 ; i != s.size() ; i++)
    {
        if(L.find(s[i]) != L.end())
            return false;
        L.insert(s[i]);
    }
     return true;
}