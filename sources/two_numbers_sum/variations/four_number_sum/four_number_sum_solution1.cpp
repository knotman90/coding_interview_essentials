int four_sum_bruteforce(std::vector<int>& A,
                        std::vector<int>& B,
                        std::vector<int>& C,
                        std::vector<int>& D,
                        const int T)
{
  int ans = 0;
  for (size_t i = 0; i < A.size; i++)
    for (size_t j = 0; j < B.size; j++)
      for (size_t k = 0; k < C.size; k++)
        for (size_t l = 0; l < D.size; l++)
        {
          const long sum = (long)A[i] + (long)B[j] + 
                           (long)C[k] + (long)D[l];
          if (sum == T)
            ans++;
        }

  return ans;
}