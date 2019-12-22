#include <algorithm>
#include <string>
#include <limits>

int count_different_letters(const std::string& a_perm, const std::string& b)
{
    assert(a_perm.size() == b.size());

    int count = 0;
    for(size_t i = 0; i < a_perm.length(); i++)
    {
        if(a_perm[i] != b[i])
            ++count;
    }
    return count;
}

int solution_brute_force(const std::string& a, const std::string& b)
{
    if(a.length() != b.length())
    	return -1;
    
    std::string a_perm(a);
    sort(a_perm.begin(), a_perm.end());
    int ans = std::numeric_limits<int>::max();
    do
    {
        ans = std::min(ans, count_different_letters(a_perm, b));   
        if(ans==0)
            break;
    }while(std::next_permutation(a_perm.begin(), a_perm.end()));

    return ans;
}