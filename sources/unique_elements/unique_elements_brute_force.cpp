bool unique_elements_brute_force(const std::string& s)
{
    for(size_t i = 0 ; i < s.size() ; i++)
        for(size_t j = i+1 ; j < s.size() ; j++)
            if(s[i] == s[j])
                return false;
        
     return true;
}