#include "hash_pair.h"

class PalindromeSubstringCacheRecursive
{
  public:
    PalindromeSubstringCacheRecursive(const std::string& s) :mStr_size(s.size()) {
      buildMap(s);
    }

    [[nodiscard]] bool is_palindrome(const size_t start, const size_t end) const
    {
      const std::pair<size_t,size_t> p(start, end);
      return mB.contains(p) &&  mB.at(p);
    }

    [[nodiscard]] size_t size()const {
      return mStr_size;
    }

  private:
    bool is_palindrome_substring_helper(const string&s, const size_t start, const size_t end)
    {
        if(start > end || start >= s.size() || end < 0)
            return true;

        const std::pair<int,int> p(start, end);
        if(mB.contains(p))
            return mB.at(p);
        
        const bool ans = (start == end) || (
            (s[start]==s[end]) && 
                is_palindrome_substring_helper(s,start+1, end-1)
                );
        mB.insert({p, ans});
        return ans;
    }

    void buildMap(const std::string&s)
    {
        for(size_t i = 0 ; i < std::size(s) ; i++)
        {
            for (size_t j = i; j < std::size(s); j++)
            {
                mB[{i,j}] = is_palindrome_substring_helper(s,i,j);
            }
        }
    }

  std::unordered_map<std::pair<int,int>, bool, PairHasher> mB;
  const size_t mStr_size;

};
