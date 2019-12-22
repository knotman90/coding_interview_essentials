bool all_unique(const string& s, const size_t ALPH_SIZE=128)
{
    if(s.size() > ALPH_SIZE)
    	return false;
    	
    std::array<bool, ALPH_SIZE> F = {false};    
    for(int i = 0 ; i != ALPH_SIZE ; i++)
    {
        if(F[s[i]])
            return false;
        F[s[i]]++;
    }
    return true;