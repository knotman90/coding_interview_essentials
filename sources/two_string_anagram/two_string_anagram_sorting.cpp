int solution_sorting(const std::string& a, const std::string& b)
{
    if(a.length() != b.length())
    	return -1;
    
    int ans = 0;
    std::string aa(a);
    std::string bb(b);
    
    std::sort(aa.begin(), aa.end());
    std::sort(bb.begin(), bb.end());
    for(int i = 0 ; i < aa.size() ; i++)
        ans+= (aa[i] != bb[i]) ? 1 : 0;
    return ans;
}