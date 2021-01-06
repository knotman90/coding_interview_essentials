#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "count_bits_solution1.cpp"
#include "count_bits_solution2.cpp"
#include "count_bits_solution3.cpp"
#include "count_bits_solution4.cpp"




TEST(count_bits, test10)
{
	
	constexpr int n = 16;
    const std::vector<int> expected = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4,1};
    {
        auto ans = count_bits_bruteforce(n);
        ASSERT_EQ(ans, expected);
    }

    {
        auto ans = count_bits_DP(n);
        ASSERT_EQ(ans, expected);
    }

        {
        auto ans = count_bits_DP_short(n);
        ASSERT_EQ(ans, expected);
    }

        {
        auto ans = count_bits_DP_powers(n);
        ASSERT_EQ(ans, expected);
    }
    
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

