std::vector<int> count_bits_DP(const unsigned n)
{
    std::vector<int> B;
    B.reserve(n+1);
    B.push_back(0);
    for(unsigned num = 1 ; num <= n ;num++)
    {
        const unsigned last_bit = num&1;
        const unsigned pop_count_rest = B[num>>1];
        B.push_back(last_bit + pop_count_rest);
    }
    return B;
} 
 