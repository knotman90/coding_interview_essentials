std::vector<int> next_greater_element_I_bruteforce(const std::vector<int>& A,
const std::vector<int>& B)
{
    std::vector<int>C(A.size());
    for(int i = 0 ; i < std::ssize(A) ; i++)
    {
        auto it = std::find(std::begin(B), std::end(B), A[i]);
        int ans_i = -1;
        while(it != B.end())
        {
            if(*it > A[i] )
                ans_i = (ans_i == -1) ? *it: std::min(ans_i, *it);
            it++;
        }
        C[i] = ans_i;
    }
    return C;
}