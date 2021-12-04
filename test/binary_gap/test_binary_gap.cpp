#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "binary_gap_solution1.cpp"
#include "binary_gap_solution2.cpp"




TEST(binary_gap, various_numbers)
{
	const std::vector<std::pair<int, int>> test_input = 
    {
        {0,0},
        {1,0},
        {2,0},
        {3,0},
        {4,0},
        {6,0},
        {5,1},
        {9,2},
        {10,1},
        {20,1},
        {1041,5},
        {32,0},
        {128,0},
        {2147483547, 2},
        {2147483647, 0},
        {654657,5},
        {97986,4}
    };
	for(const auto& [n, expected] : test_input){
        
        EXPECT_EQ(expected, binary_gap_raw_loop(n)) << "failed for "<<n;
         EXPECT_EQ(expected, binary_gap_raw_loop_skip_trailing_zeros(n)) << "failed for "<<n;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

