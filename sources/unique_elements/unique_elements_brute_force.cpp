bool all_unique(const string& s)
{
    for(int i = 0 ; i < s.size() ; i++)
        for(int j = i+1 ; j < s.size() ; j++)
            if(s[i] == s[j])
                return false;
        
     return true;
}