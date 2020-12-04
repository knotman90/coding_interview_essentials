#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "max_gap_solution1.cpp"
#include "max_gap_solution2.cpp"


TEST(max_gap, test1)
{
	
	for(const auto&[input, expected] : 
    {
        std::pair<std::vector<int>, int>({1,2,3},1),
        std::pair<std::vector<int>, int>({5,3,1,8,9,2,4},3),
        std::pair<std::vector<int>, int>({7, 1, 8, 9,15},6),
    }
    ){
        EXPECT_EQ(expected, max_gap_bruteforce(input));
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

