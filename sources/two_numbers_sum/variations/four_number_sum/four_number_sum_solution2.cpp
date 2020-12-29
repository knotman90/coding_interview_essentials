int four_sum_cubic(std::vector<int>& A,
                        std::vector<int>& B,
                        std::vector<int>& C,
                        std::vector<int>& D,
                        const int T)
{
    if(A.size() > D.size())
        std::swap(A,D);
    if(B.size() > D.size())
        std::swap(B,D);
    if(C.size() > D.size())
        std::swap(C,D);  

  //D is now the longest
  std::unordered_map<int,int>Dmap; //frequencies map for D
  for(const auto d : D)
      Dmap[d]++;

  int ans = 0;
  for (size_t i = 0; i < A.size(); i++)
    for (size_t j = 0; j < B.size(); j++)
      for (size_t k = 0; k < C.size(); k++){
          const long sum = (long)A[i] + (long)B[j] + 
                           (long)C[k];
          if(auto it = Dmap.find(T-sum) ; it != Dmap.end()){
              ans+=it->second;
          }
      }

  return ans;
}