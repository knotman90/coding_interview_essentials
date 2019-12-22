bool all_unique(const string& s)
{
    for(auto it = s.begin() ; it != s.end() ; it++)
        if( find(it+1, s.end(), *it) != s.end() )
            return false;        
     return true;
}