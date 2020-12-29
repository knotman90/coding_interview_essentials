class PalindromeSubstringCacheIterative
{
  public:
    PalindromeSubstringCacheIterative(const std::string& s) :mStr_size(s.size()) {
      buildMap(s);
    }

    [[nodiscard]] bool is_palindrome(const size_t start, const size_t end) const
    {

      return start < mStr_size && end>=0 && 
          mB[start][end]!=-1 &&  mB[start][end];
    }

    [[nodiscard]] size_t size() const {
      return mStr_size;
    }

  private:

    void buildMap(const std::string&s)
    {
        mB.resize(mStr_size, std::vector<int>(mStr_size,-1));
        for(int i = mStr_size-1; i >=0 ; i--)
        {
            for(int j = i ; j < mStr_size ; j++ )
            {
                mB[i][j]=(s[i]==s[j]) && ((j-i<=2) || mB[i+1][j-1]);
                //mB[{i,j}]=s[i]==s[j] && ((j-i<=2) || mB[{i+1,j-1}]);
            }
        }
    }

  std::vector<vector<int>> mB;
  const size_t mStr_size;

};

