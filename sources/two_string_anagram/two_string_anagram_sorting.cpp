
int solution_sorting(const std::string& a, const std::string& b)
{
    if(a.length() != b.length())
    	return -1;
    
    std::string aa(a);
    std::string bb(b);
    
    std::sort(aa.begin(), aa.end());
    std::sort(bb.begin(), bb.end());
    return count_different_letters(aa,bb);   
}