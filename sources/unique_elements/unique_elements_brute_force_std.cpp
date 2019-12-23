bool unique_elements_brute_force_std(const std::string& s)
{
    for(auto it = s.begin() ; it != s.end() ; it++)
        if( std::find(it+1, s.end(), *it) != s.end() )
            return false;        
     return true;
}