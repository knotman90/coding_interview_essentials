#include <gtest/gtest.h>
#include <bits/stdc++.h>

using std::string;
using std::swap;
using std::cout;
using std::endl;
using std::begin;
using std::end;
using std::vector;

#include "count_numbers_conforming_bitmask_solution1.cpp"
#include "count_numbers_conforming_bitmask_solution2.cpp"




TEST(count_numbers_conforming_bitmask, test1)
{
	int A = 1073741727, B = 1073741631, C=1073741679;
	EXPECT_EQ(8,solve(A,B,C));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS();
}

